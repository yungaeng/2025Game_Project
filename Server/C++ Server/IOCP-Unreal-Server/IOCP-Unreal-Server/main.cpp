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
SOCKET g_s_socket, g_c_socket; // g_c_socket은 AcceptEx용 임시 소켓
ex_over g_a_over;              // AcceptEx 오버랩 구조체
DB g_db;                       // DB

concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
concurrency::concurrent_unordered_map<int, std::shared_ptr<ROOM>> rooms;

std::atomic<long long> next_client_id = 0;
std::atomic<int> pid_counter = 0; // pid와 겹치지 않게 이름 변경

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
    //// 맵에서 shared_ptr를 안전하게 가져옴
    //auto it = clients.find(c_id);
    //if (it == clients.end()) {
    //    std::cerr << "Error: Client ID " << c_id << " not found in clients map when processing packet." << std::endl;
    //    return;
    //}
    //std::shared_ptr<session> current_session = it->second; // shared_ptr 복사

    //// 세션이 이미 ST_FREE 상태라면 더 이상 처리하지 않음
    //if (current_session->_state == ST_FREE) {
    //    std::cerr << "Error: Client ID " << c_id << " is in ST_FREE state, skipping packet processing." << std::endl;
    //    return;
    //}

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
            // 회원이 이미 있다면
            // 1 : 다른 클라이언트에서 사용중
            clients[c_id]->send_login_fail_packet(1);
        }
        else {
            // 만들수 있는 계정이라면
            // 새 회원 등록하고 로그인 시켜줌.
            g_db.InsertDB(ld);
            clients[c_id]->send_login_ok_packet();
            clients[c_id]->send_avata_info_packet();
        }
            

        // 현재 DB 보여주기
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
            // 4 : 해당되는 계정이 없음
            clients[c_id]->send_login_fail_packet(4);
        }

        // 현재 DB 보여주기
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
        //event_queue.push(ev); // 이벤트 큐에 푸시
        break;
    }
    case C2S_ATTACK: {
        
        break;
    }
    case C2S_CHAT: {
        cs_packet_chat* p = reinterpret_cast<cs_packet_chat*>(packet);
        //std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;

        //// 같은 방에 있는 모든 클라이언트에게 채팅 브로드캐스트
        //for (auto& pl_pair : clients) {
        //    std::shared_ptr<session> other_session = pl_pair.second;
        //    if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
        //        other_session->send_chat_packet(c_id, p->message);
        //    }
        //}
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
    // 임시 : 로그 아웃하면 db에서 삭제
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
            delete exover; // 송신 완료된 오버랩 구조체 메모리 해제
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

    // 서버의 로컬 IP 주소 출력 (이전 코드와 동일)
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

    // 리스닝 소켓을 IOCP에 등록 (key 9999는 임의의 값)
    CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_s_socket), h_iocp, 9999, 0);

    // AcceptEx를 위한 클라이언트 소켓 초기화
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

    // DB 초기화
    if (g_db.InitDB())
        std::cout << "DB is Working..." << std::endl;


    // 워커 스레드 생성
    std::vector <std::thread> worker_threads;
    int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2; // 최소 2개 스레드 (CPU 코어 수를 얻지 못할 경우)

    for (int i = 0; i < num_threads; ++i) {
        worker_threads.emplace_back(worker_thread, h_iocp);
    }

    std::thread event_thread{ do_event }; // 이벤트 처리 스레드

    std::cout << "Worker threads : " << num_threads << std::endl;
    std::cout << "Now server is running" << std::endl;
    g_db.SelectDB();

    //--------------------------- 여기서부터 서버 실행---------------------------------



    //--------------------------- 여기서부터 서버 종료---------------------------------
    // 
    // 서버 종료 대기 (예: 콘솔 입력 대기 또는 특정 종료 시그널)
    // 현재는 이 스레드들이 main 스레드가 join하기 전까지 계속 실행됩니다.
    // 적절한 서버 종료 로직이 필요합니다 (예: 키 입력 시 종료, Ctrl+C 핸들러 등).
    std::string command;
    while (std::getline(std::cin, command)) {
        if (command == "exit" || command == "quit") {
            std::cout << "Shutting down server..." << std::endl;
            // TODO: 모든 클라이언트 연결 강제 종료 및 IOCP 포스트 퀴트 메시지
            // PostQueuedCompletionStatus(h_iocp, 0, 0, nullptr); // 각 워커 스레드에 종료 신호
            break;
        }
    }

    // 모든 스레드가 종료될 때까지 기다림
    event_thread.join();
    for (auto& th : worker_threads) {
        th.join();
    }

    // 자원 해제
    closesocket(g_s_socket);
    CloseHandle(h_iocp);
    WSACleanup();

    std::cout << "Server has shut down gracefully." << std::endl;
    return 0;
}