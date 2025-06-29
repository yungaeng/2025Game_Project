#pragma once
#include "room.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>
#include <string>

HANDLE h_iocp;
SOCKET g_s_socket, g_c_socket; // g_c_socket�� AcceptEx�� �ӽ� ����
ex_over g_a_over; // AcceptEx ������ ����ü

concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
concurrency::concurrent_unordered_map<int, ROOM> rooms;

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
    // �ʿ��� shared_ptr�� �����ϰ� ������
    auto it = clients.find(c_id);
    if (it == clients.end()) {
        std::cerr << "Error: Client ID " << c_id << " not found in clients map when processing packet." << std::endl;
        return;
    }
    std::shared_ptr<session> current_session = it->second; // shared_ptr ����

    // ������ �̹� ST_FREE ���¶�� �� �̻� ó������ ����
    if (current_session->_state == ST_FREE) {
        std::cerr << "Error: Client ID " << c_id << " is in ST_FREE state, skipping packet processing." << std::endl;
        return;
    }

    switch (packet[1]) {
    case C2S_LOGIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            std::lock_guard<std::mutex> ll(current_session->_s_lock); // _s_lock���� ��ȣ
            strcpy_s(current_session->_name, sizeof(current_session->_name), p->name);
            current_session->_state = ST_INGAME; // �α��� ���� �� INGAME ���·� ����
        }

        current_session->send_login_ok_packet();
        current_session->send_avata_info_packet();

        std::cout << "Client [" << c_id << "] logged in as " << current_session->_name << std::endl;

        // ���� �濡 �ִ� �ٸ� Ŭ���̾�Ʈ�鿡�� ���� ���� ��ε�ĳ��Ʈ (�α��� ���� �� �ٷ� ���� �������� ����)
        // C2S_ROOM ó���� �ߺ��� �� �����Ƿ�, � ������ ���� ��Ŷ�� ������ �����ؾ� ��
        // ����: �α��� �� �ٷ� �κ�/�⺻ �濡 �����Ѵٸ�
        for (auto& pl_pair : clients) {
            std::shared_ptr<session> other_session = pl_pair.second;
            if (other_session->_id == c_id) continue; // �ڽſ��Դ� ������ ����

            // �ٸ� Ŭ���̾�Ʈ���� ���� ���������� �˸�
            if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                // �ٸ� �÷��̾ �� ������ �޵���
                other_session->send_enter_packet(c_id);
            }
        }
        // ������ �ٸ� ��� �÷��̾��� ���� ������ ����
        for (auto& pl_pair : clients) {
            std::shared_ptr<session> other_session = pl_pair.second;
            if (other_session->_id == c_id) continue;
            if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                current_session->send_enter_packet(other_session->_id);
            }
        }

        break;
    }
    case C2S_ROOM: {
        cs_packet_room* p = reinterpret_cast<cs_packet_room*>(packet);
        switch (p->requst) {
        case 0: { // �� ���� ��û
            int id = get_room_id(); // �� �� ID ȹ��
            // TODO: ���� ROOM ��ü ���� �� ���� ���� �ʿ� (rooms �ʿ� �߰�)

            {   // Ŭ���̾�Ʈ�� �� ID ���� �� ���� ����
                std::lock_guard<std::mutex> ll(current_session->_s_lock);
                current_session->_room_id = id;
                current_session->_pid = pid_counter.fetch_add(1); // pid_counter�� ����
                current_session->_state = ST_INGAME;
            }

            current_session->send_room_packet(id);

            std::cout << "Client [" << c_id << "] requested to create room, Room ID : " << id << std::endl;
            break;
        }
        case 1: { // �� ���� ��û (�߰� ���� �ʿ�)
            // p->room_id �� ���� �ش� ������ ���� ó��
            //std::cout << "Client [" << c_id << "] requested to join room " << p->room_id << std::endl;
            // TODO: ���� �濡 Ŭ���̾�Ʈ ���� ���� ����
            break;
        }
        default:
            std::cout << "Client [" << c_id << "] sent invalid room request type: " << static_cast<int>(p->requst) << std::endl;
            break;
        }
        break;
    }
    case C2S_MOVE: {
        cs_packet_move* p = reinterpret_cast<cs_packet_move*>(packet);

        int new_x = current_session->_x;
        int new_y = current_session->_y;

        switch (p->direction) {
        case 'W': new_y--; break;
        case 'S': new_y++; break;
        case 'A': new_x--; break;
        case 'D': new_x++; break;
        default:
            std::cout << "Client [" << c_id << "] sent invalid move direction: " << p->direction << std::endl;
            return;
        }

        if (new_x < 0) new_x = 0;
        if (new_x >= 100) new_x = 100 - 1;
        if (new_y < 0) new_y = 0;
        if (new_y >= 100) new_y = 100 - 1;

        if (new_x != current_session->_x || new_y != current_session->_y) {
            {
                std::lock_guard<std::mutex> ll{ current_session->_s_lock }; // ������ ����� ���� �� ��
                current_session->_x = new_x;
                current_session->_y = new_y;
            }
            std::cout << "Client [" << c_id << "] moved to (" << new_x << ", " << new_y << ")" << std::endl;

            // ���� ���� �ٸ� Ŭ���̾�Ʈ�鿡�� �̵� ���� ��ε�ĳ��Ʈ
            for (auto& pl_pair : clients) {
                std::shared_ptr<session> other_session = pl_pair.second;
                if (other_session->_id == c_id) continue;
                // ST_INGAME ��������, ���� ������ Ȯ�� (�� ���� ����/��ID ���� �����ϵ��� ���� �ʿ�)
                // ���� shared_ptr�� �����߱� ������ �ٸ� �����忡�� ��ü�� ������ ������ ������,
                // _state�� _room_id�� ����� �� �ִ� Race Condition�� ������ ������ �� ����.
                // �׷��� atomic �����̰ų� ������ ���� �ʰ� ū ������ �ƴ϶�� ������ �� �ֽ��ϴ�.
                if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                    other_session->send_move_packet(c_id);
                }
            }
            // �̵��� Ŭ���̾�Ʈ���Ե� �ڽ��� �̵� ���� ���� (Ŭ���̾�Ʈ ����ȭ ����)
            current_session->send_move_packet(c_id);
        }
        break;
    }
    case C2S_MISSION: {
        cs_packet_mission* p = reinterpret_cast<cs_packet_mission*>(packet);
        std::cout << "Client [" << c_id << "] requested mission: " << static_cast<int>(p->mission) << std::endl;
        ROOM_EVENT ev;
        ev.client_id = c_id;
        ev.event_id = (EVENT_TYPE)p->mission;
        event_queue.push(ev); // �̺�Ʈ ť�� Ǫ��
        break;
    }
    case C2S_ATTACK: {
        // cs_packet_attack* p = reinterpret_cast<cs_packet_attack*>(packet); // p�� ������ �ʾ� �ּ� ó��
        std::cout << "Client [" << c_id << "] Attacked." << std::endl;
        // ���� ���� ����
        break;
    }
    case C2S_CHAT: {
        cs_packet_chat* p = reinterpret_cast<cs_packet_chat*>(packet);
        std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;

        // ���� �濡 �ִ� ��� Ŭ���̾�Ʈ���� ä�� ��ε�ĳ��Ʈ
        for (auto& pl_pair : clients) {
            std::shared_ptr<session> other_session = pl_pair.second;
            if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                other_session->send_chat_packet(c_id, p->message);
            }
        }
        break;
    }
    default:
        std::cout << "Unknown packet type received from client [" << c_id << "]: " << static_cast<int>(packet[1]) << std::endl;
        break;
    }
}
void disconnect(long long c_id) {
    // �ʿ��� shared_ptr�� �����ϰ� ������
    auto it = clients.find(c_id);
    if (it == clients.end()) {
        // �̹� �ʿ� ���ų� ó���Ǿ��� ��� (�ߺ� ȣ�� ����)
        return;
    }
    std::shared_ptr<session> disconnected_session = it->second;

    // �̹� ST_FREE ���¶�� �ߺ� ó�� ����
    if (disconnected_session->_state == ST_FREE) {
        return;
    }

    std::cout << "Client [" << c_id << "] disconnected." << std::endl;

    int disconnected_room_id = -1;
    {
        std::lock_guard<std::mutex> ll(disconnected_session->_s_lock);
        disconnected_room_id = disconnected_session->_room_id; // ���� �ɰ� �� ID�� ������
        disconnected_session->_state = ST_FREE; // ���¸� FREE�� ����
        disconnected_session->_id = -1; // ID ��ȿȭ
    }

    // ���� �ݱ�
    closesocket(disconnected_session->_socket);

    // ���� ���� �ٸ� Ŭ���̾�Ʈ�鿡�� ���� ���� ��ε�ĳ��Ʈ
    // ���⼭ clients ���� ��ȸ�ϴ� ���� �ٸ� �����忡�� disconnect�� ȣ��� �� �����Ƿ� ���� �ʿ�
    // concurrent_unordered_map�̹Ƿ� ��ȸ ��ü�� ����������,
    // pl.second->get_state()�� _room_id ���� ������ ������ �ϰ��� ���� �߻� ���ɼ�.
    // ������ ��κ��� ��� ª�� ����ġ�� ������ ���� ����.
    for (auto& pl_pair : clients) {
        std::shared_ptr<session> other_session = pl_pair.second;
        if (other_session->_id == c_id) continue; // �ڽſ��Դ� ������ ����

        // �ٸ� ������ ���� ��ȿ�ϰ� ���� �濡 �־��ٸ� ���� ��Ŷ ����
        if (other_session->get_state() == ST_INGAME && other_session->_room_id == disconnected_room_id) {
            other_session->send_leave_packet(c_id);
        }
    }

    // Ŭ���̾�Ʈ �ʿ��� shared_ptr ���� -> ���� ī��Ʈ�� 0�� �Ǹ� session ��ü �ڵ� ����
    //clients.erase(c_id);
    std::cout << "Client [" << c_id << "] removed from clients map." << std::endl;
}
void worker_thread(HANDLE h_iocp) {
    while (true) {
        DWORD num_bytes;
        ULONG_PTR key;
        WSAOVERLAPPED* over = nullptr;
        BOOL ret = GetQueuedCompletionStatus(h_iocp, &num_bytes, &key, &over, INFINITE);

        ex_over* exover = reinterpret_cast<ex_over*>(over);

        // GQCS ���� ó�� (over�� NULL�� ���ɼ��� ����)
        if (FALSE == ret) {
            if (exover == nullptr) { // over�� NULL�� ��� (timeout �Ǵ� �ٸ� GQCS ����)
                std::cerr << "GQCS returned FALSE with NULL OVERLAPPED. Continuing..." << std::endl;
                continue;
            }
            if (exover->_comp_type == OP_ACCEPT) {
                std::cerr << "AcceptEx Error during GQCS: " << GetLastError() << std::endl;
            }
            else {
                std::cerr << "GQCS Error on client[" << key << "], Type: " << exover->_comp_type << ", Error: " << GetLastError() << std::endl;
                disconnect(static_cast<long long>(key)); // ���� �߻� Ŭ���̾�Ʈ ���� ����
            }
            if (exover->_comp_type == OP_SEND) {
                delete exover; // send �Ϸ� �� ex_over�� �����ؾ� ��
            }
            continue;
        }

        // ���� ���� �Ǵ� Ŭ���̾�Ʈ�� ������ ���� ��� (num_bytes == 0)
        if ((0 == num_bytes) && ((exover->_comp_type == OP_RECV) || (exover->_comp_type == OP_SEND))) {
            disconnect(static_cast<long long>(key));
            if (exover->_comp_type == OP_SEND) {
                delete exover; // send �Ϸ� �� ex_over�� �����ؾ� ��
            }
            continue;
        }

        switch (exover->_comp_type) {
        case OP_ACCEPT: {
            long long client_id = get_new_client_id();
            if (client_id != -1) {
                std::shared_ptr<session> new_session = clients.at(client_id);
                {
                    std::lock_guard<std::mutex> ll(new_session->_s_lock);
                    new_session->_state = ST_ALLOC; // �� ������ �켱 ALLOC ���·�
                }
                new_session->_x = 0;
                new_session->_y = 0;
                new_session->_id = client_id;
                new_session->_name[0] = 0; // �̸� �ʱ�ȭ
                new_session->_prev_remain = 0;
                new_session->_socket = g_c_socket; // Accepted�� ���� �Ҵ�

                // IOCP�� ���� ����� Ŭ���̾�Ʈ ���� ���
                CreateIoCompletionPort(reinterpret_cast<HANDLE>(new_session->_socket), h_iocp, client_id, 0);

                new_session->do_recv(); // ù ���ú� ��û
                std::cout << "New client accepted: ID " << client_id << std::endl;
            }
            else {
                std::cerr << "Max user limit exceeded. Closing new client socket." << std::endl;
                closesocket(g_c_socket); // ���Ӱ� ����� ���� �ݱ�
            }

            // ���� AcceptEx�� ���� ���ο� g_c_socket ����
            g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
            if (g_c_socket == INVALID_SOCKET) {
                std::cerr << "Failed to create new g_c_socket for next AcceptEx: " << GetLastError() << std::endl;
                // �� ��� ������ �� �̻� �� ������ ���� �� ���� ��. �ɰ��� ����.
            }

            // ���� AcceptEx ��û
            ZeroMemory(&g_a_over._over, sizeof(g_a_over._over));
            int addr_size = sizeof(SOCKADDR_IN);
            if (FALSE == AcceptEx(g_s_socket, g_c_socket, g_a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &g_a_over._over)) {
                int err = GetLastError();
                if (err != WSA_IO_PENDING) {
                    std::cerr << "AcceptEx failed immediately after previous accept: " << err << std::endl;
                    // ������ �� �̻� �� ������ ���� ���ϰ� ��.
                }
            }
            break;
        }
        case OP_RECV: {
            auto it_recv = clients.find(static_cast<long long>(key));
            if (it_recv == clients.end() || it_recv->second->_state == ST_FREE) {
                std::cerr << "Error: Client ID " << key << " not found or freed when processing RECV." << std::endl;
                break;
            }
            std::shared_ptr<session> current_session = it_recv->second;

            int remain_data = num_bytes + current_session->_prev_remain;
            char* p = exover->_send_buf; // �� ���۴� exover�� �پ��ִ� ����

            while (remain_data > 0) {
                int packet_size = p[0];
                // ��Ŷ ũ�� ���� (�ּ� 1����Ʈ �̻��̾�� ��)
                if (packet_size <= 0 || packet_size > BUF_SIZE) { // BUF_SIZE�� ���ǵǾ� �־�� ��
                    std::cerr << "Invalid packet size (" << packet_size << ") from client [" << key << "]. Disconnecting." << std::endl;
                    disconnect(static_cast<long long>(key));
                    break;
                }

               
                if (packet_size <= remain_data) {
                    process_packet(static_cast<long long>(key), p); // ��Ŷ ó��
                    p = p + packet_size;
                    remain_data = remain_data - packet_size;
                }
                else {
                    break; // ������ ��Ŷ�� ���� �������� ����
                }
            }
            current_session->_prev_remain = remain_data;
            if (remain_data > 0) {
                // ó������ ���� �����͸� ������ �� ������ ����
                memcpy(exover->_send_buf, p, remain_data);
            }
            current_session->do_recv(); // ���� ���ú� ��û
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
    else {
        std::cerr << "gethostname failed: " << WSAGetLastError() << std::endl;
    }

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

    // ���� ���� ��� (��: �ܼ� �Է� ��� �Ǵ� Ư�� ���� �ñ׳�)
    // ����� �� ��������� main �����尡 join�ϱ� ������ ��� ����˴ϴ�.
    // ������ ���� ���� ������ �ʿ��մϴ� (��: Ű �Է� �� ����, Ctrl+C �ڵ鷯 ��).
    std::string command;
    while (std::getline(std::cin, command)) {
        if (command == "exit" || command == "quit") {
            std::cout << "Shutting down server..." << std::endl;
            // TODO: ��� Ŭ���̾�Ʈ ���� ���� ���� �� IOCP ����Ʈ ��Ʈ �޽���
            // PostQueuedCompletionStatus(h_iocp, 0, 0, nullptr); // �� ��Ŀ �����忡 ���� ��ȣ
            break;
        }
    }

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