#pragma once
#include "room.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <string>
#include "db.h"
HANDLE h_iocp;
SOCKET g_s_socket, g_c_socket; // g_c_socket�� AcceptEx�� �ӽ� ����
ex_over g_a_over;              // AcceptEx ������ ����ü
DB g_db;                       // DB

concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
concurrency::concurrent_unordered_map<int, std::shared_ptr<ROOM>> rooms;

std::atomic<long long> next_client_id = 0;
std::atomic<int> pid_counter = 0; // pid�� ��ġ�� �ʰ� �̸� ����

long long get_new_client_id() {
    long long new_id = next_client_id.fetch_add(1);
    if (new_id >= MAX_USER) {
        std::cerr << "Max user limit exceeded. Cannot allocate new client ID." << std::endl;
        return -1;
    }
    return new_id;
}
void process_packet(long long c_id, char* packet)
{
    switch (packet[1]) {
    case C2S_SIGNIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            lock_guard<mutex> ll{ clients[c_id]->_s_lock };
            strcpy_s(clients[c_id]->_name, p->name);
        }
        logindata ld;
        ld.ID = c_id;
        ld.NAME = clients[c_id]->_name;

       
        if (g_db.FindDB(ld.NAME)) {
            // ȸ���� �̹� �ִٸ�
            // 1 : �ٸ� Ŭ���̾�Ʈ���� �����
            clients[c_id]->send_login_fail_packet(1);
        }
        else {
            // ����� �ִ� �����̶��
            // �� ȸ�� ����ϰ� �α��� ������.
            g_db.InsertDB(ld);
            clients[c_id]->send_login_ok_packet();
            clients[c_id]->send_avata_info_packet();
        }
            
        // ���� DB �����ֱ�
        g_db.SelectDB();

        break;
    }
    case C2S_LOGIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            lock_guard<mutex> ll{ clients[c_id]->_s_lock };
            strcpy_s(clients[c_id]->_name, p->name);
        }
        std::string NAME = clients[c_id]->_name;

        if (g_db.FindDB(NAME)) {
            clients[c_id]->send_login_ok_packet();
            clients[c_id]->send_avata_info_packet();
        }
        else {
            // 4 : �ش�Ǵ� ������ ����
            clients[c_id]->send_login_fail_packet(4);
        }

        // ���� DB �����ֱ�
        g_db.SelectDB();
        
        break;
    }
    case C2S_ROOM: {
        cs_packet_room* p = reinterpret_cast<cs_packet_room*>(packet);
        switch (p->requst)
        {
        case 'C': {
            int room_id = get_room_id();
            rooms[room_id] = std::make_shared<ROOM>();
            {
                lock_guard<mutex> ll{ rooms[room_id]->rl };
                rooms[room_id]->state = R_READY;
                rooms[room_id]->player++;
                {
                    lock_guard<mutex> ll{ clients[c_id]->_s_lock };
                    clients[c_id]->_pid = rooms[room_id]->player;
                    clients[c_id]->_room_id = room_id;
                }
            }
            clients[c_id]->send_room_packet(c_id);
            break;
        } 
        case 'J': {
            int room_id = get_room_id();
            {
                lock_guard<mutex> ll{ rooms[room_id]->rl };
                rooms[room_id]->player++;
                {
                    lock_guard<mutex> ll{ clients[c_id]->_s_lock };
                    clients[c_id]->_pid = rooms[room_id]->player;
                    clients[c_id]->_room_id = room_id;
                }
            }
            clients[c_id]->send_room_packet(c_id);
            break;
        }
        case 'L':
        default:
            break;
        }
        break;
    }
    case C2S_MOVE: { 
        break;
    }
    case C2S_MISSION: {
        //cs_packet_mission* p = reinterpret_cast<cs_packet_mission*>(packet);
        //std::cout << "Client [" << c_id << "] requested mission: " << static_cast<int>(p->mission) << std::endl;
        //ROOM_EVENT ev;
        //ev.client_id = c_id;
        //ev.event_id = (EVENT_TYPE)p->mission;
        //event_queue.push(ev); // �̺�Ʈ ť�� Ǫ��
        break;
    }
    case C2S_ATTACK: {
        
        break;
    }
    case C2S_CHAT: {
        cs_packet_chat* p = reinterpret_cast<cs_packet_chat*>(packet);
        std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;
        clients[c_id]->send_chat_packet(c_id, p->message);
        break;
    }
    default:
        std::cout << "Unknown packet type received from client [" << c_id << "]: " << static_cast<int>(packet[1]) << std::endl;
        break;
    }
}
void disconnect(long long c_id) {
    closesocket(clients[c_id]->_socket);
    {
        lock_guard<mutex> ll(clients[c_id]->_s_lock);
        clients[c_id]->_state = ST_FREE;
    }
    // �ӽ� : �α� �ƿ��ϸ� db���� ����
    g_db.DeleteDB(c_id);
    g_db.SelectDB();
}
void worker_thread(HANDLE h_iocp) {
    while (true) {
        DWORD num_bytes;
        ULONG_PTR key;
        WSAOVERLAPPED* over = nullptr;
        BOOL ret = GetQueuedCompletionStatus(h_iocp, &num_bytes, &key, &over, INFINITE);
        ex_over* exover = reinterpret_cast<ex_over*>(over);
        if (FALSE == ret) {
            if (exover->_comp_type == OP_ACCEPT) cout << "Accept Error";
            else {
                cout << "GQCS Error on client[" << key << "]\n";
                disconnect(static_cast<int>(key));
                if (exover->_comp_type == OP_SEND) delete exover;
                continue;
            }
        }

        if ((0 == num_bytes) && ((exover->_comp_type == OP_RECV) || (exover->_comp_type == OP_SEND))) {
            disconnect(static_cast<int>(key));
            if (exover->_comp_type == OP_SEND) delete exover;
            continue;
        }

        switch (exover->_comp_type) {
        case OP_ACCEPT: {
            long long client_id = get_new_client_id();
            if (client_id != -1) {
                clients[client_id] = std::make_shared<session>();
                {
                    lock_guard<mutex> ll(clients[client_id]->_s_lock);
                    clients[client_id]->_state = ST_ALLOC;
                }
                clients[client_id]->_x = 0;
                clients[client_id]->_y = 0;
                clients[client_id]->_id = client_id;
                clients[client_id]->_name[0] = 0;
                clients[client_id]->_prev_remain = 0;
                clients[client_id]->_socket = g_c_socket;
                CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_c_socket), h_iocp, client_id, 0);
                clients[client_id]->do_recv();
                g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
                cout << "Player Num : " << clients.size() << endl;
            }
            else {
                cout << "Max user exceeded.\n";
            }
            ZeroMemory(&g_a_over._over, sizeof(g_a_over._over));
            int addr_size = sizeof(SOCKADDR_IN);
            AcceptEx(g_s_socket, g_c_socket, g_a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &g_a_over._over);
            break;
        }
        case OP_RECV: {
            int remain_data = num_bytes + clients[key]->_prev_remain;
            char* p = exover->_send_buf;
            while (remain_data > 0) {
                int packet_size = p[0];
                if (packet_size <= remain_data) {
                    process_packet(static_cast<int>(key), p);
                    p = p + packet_size;
                    remain_data = remain_data - packet_size;
                }
                else break;
            }
            clients[key]->_prev_remain = remain_data;
            if (remain_data > 0) {
                memcpy(exover->_send_buf, p, remain_data);
            }
            clients[key]->do_recv();
            break;
        }
        case OP_SEND: {
            delete exover; // �۽� �Ϸ�� ������ ����ü �޸� ����
            break;
        }
        }
    }
}
int main()
{
    WSADATA WSAData;
    if (WSAStartup(MAKEWORD(2, 2), &WSAData) != 0) {
        std::cerr << "WSAStartup failed: " << WSAGetLastError() << std::endl;
        return 1;
    }

    g_s_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (g_s_socket == INVALID_SOCKET) {
        std::cerr << "WSASocket failed: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(g_s_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
    

    if (listen(g_s_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << std::endl;
        closesocket(g_s_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server port : " << PORT << std::endl;

    // ������ ���� IP �ּ� ��� (���� �ڵ�� ����)
    char hostname[256];
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        ADDRINFOA hints = {};
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        ADDRINFOA* result = nullptr;
        int rv = getaddrinfo(hostname, nullptr, &hints, &result);
        if (rv == 0) {
            for (ADDRINFOA* ptr = result; ptr != nullptr; ptr = ptr->ai_next) {
                if (ptr->ai_family == AF_INET) {
                    sockaddr_in* ipv4 = reinterpret_cast<sockaddr_in*>(ptr->ai_addr);
                    char ip_buffer[INET_ADDRSTRLEN];
                    inet_ntop(AF_INET, &(ipv4->sin_addr), ip_buffer, INET_ADDRSTRLEN);
                    if (std::string(ip_buffer) != "127.0.0.1") {
                        std::cout << "Local IP address : " << ip_buffer << std::endl;
                    }
                }
            }
            freeaddrinfo(result);
        }
        else {
            std::cerr << "getaddrinfo failed: " << gai_strerrorA(rv) << std::endl;
        }
    }
    else
        std::cerr << "gethostname failed: " << WSAGetLastError() << std::endl;

    h_iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
    if (h_iocp == NULL) {
        std::cerr << "CreateIoCompletionPort failed: " << WSAGetLastError() << std::endl;
        closesocket(g_s_socket);
        WSACleanup();
        return 1;
    }

    // ������ ������ IOCP�� ��� (key 9999�� ������ ��)
    CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_s_socket), h_iocp, 9999, 0);

    // AcceptEx�� ���� Ŭ���̾�Ʈ ���� �ʱ�ȭ
    g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (g_c_socket == INVALID_SOCKET) {
        std::cerr << "g_c_socket creation failed for AcceptEx: " << WSAGetLastError() << std::endl;
        CloseHandle(h_iocp);
        closesocket(g_s_socket);
        WSACleanup();
        return 1;
    }

    g_a_over._comp_type = OP_ACCEPT;
    int addr_size = sizeof(SOCKADDR_IN);
    if (FALSE == AcceptEx(g_s_socket, g_c_socket, g_a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &g_a_over._over)) {
        int err = WSAGetLastError();
        if (err != WSA_IO_PENDING) {
            std::cerr << "Initial AcceptEx failed: " << err << std::endl;
            CloseHandle(h_iocp);
            closesocket(g_s_socket);
            closesocket(g_c_socket);
            WSACleanup();
            return 1;
        }
    }
    std::cout << "Max user : " << MAX_USER << std::endl;

    // DB �ʱ�ȭ
    if (g_db.InitDB())
        std::cout << "DB is Working..." << std::endl;


    // ��Ŀ ������ ����
    std::vector <std::thread> worker_threads;
    int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2; // �ּ� 2�� ������ (CPU �ھ� ���� ���� ���� ���)

    for (int i = 0; i < num_threads; ++i) {
        worker_threads.emplace_back(worker_thread, h_iocp);
    }

    std::thread event_thread{ do_event }; // �̺�Ʈ ó�� ������

    std::cout << "Worker threads : " << num_threads << std::endl;
    std::cout << "Now server is running" << std::endl;
    g_db.SelectDB();

    //--------------------------- ���⼭���� ���� ����---------------------------------



    //--------------------------- ���⼭���� ���� ����---------------------------------
    // ��� �����尡 ����� ������ ��ٸ�
    event_thread.join();
    for (auto& th : worker_threads) {
        th.join();
    }

    // �ڿ� ����
    closesocket(g_s_socket);
    CloseHandle(h_iocp);
    WSACleanup();

    std::cout << "Server has shut down gracefully." << std::endl;
    return 0;
}