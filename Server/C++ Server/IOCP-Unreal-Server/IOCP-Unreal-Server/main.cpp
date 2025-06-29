#pragma once
#include "room.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <atomic>

HANDLE h_iocp;
SOCKET g_s_socket, g_c_socket;
ex_over g_a_over;

concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
concurrency::concurrent_unordered_map<int, ROOM> rooms;
std::atomic<long long> next_client_id = 0;
std::atomic<int> pid = 0;

long long get_new_client_id() {
    long long new_id = next_client_id.fetch_add(1);
    if (new_id >= MAX_USER) {
        return -1;
    }
    return new_id;
}
void process_packet(long long c_id, char* packet)
{
    if (clients.find(c_id) == clients.end() || clients[c_id]->_state == ST_FREE) {
        std::cerr << "Error: Invalid client ID " << c_id << " attempting to process packet." << std::endl;
        return;
    }

    switch (packet[1]) {
    case C2S_LOGIN: {
        // 앞서 클라이언트 세션 초기화와 아이디 배정은 accept에서 끝남
        // 여기서 DB작업과 로그인 및 아이디 작업을 진행함
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        strcpy_s(clients[c_id]->_name, sizeof(clients[c_id]->_name), p->name);
    
        clients[c_id]->send_login_ok_packet(); // 클라이언트에게 로그인 성공 정보 전송
        clients[c_id]->send_avata_info_packet();

        std::cout << "Client [" << c_id << "] logged in as " << clients[c_id]->_name << std::endl;
        break;
    }
    case C2S_ROOM: {
        cs_packet_room* p = reinterpret_cast<cs_packet_room*>(packet);
        switch (p->requst) {
        case 0: { // 방 생성 요청
            int id = get_room_id();
            // TODO: 클라이언트에게 방 생성
            
            // 클라이언트의 방 ID 설정
            { 
                std::lock_guard<std::mutex> ll(clients[c_id]->_s_lock);
                clients[c_id]->_room_id = id;
                clients[c_id]->_pid = pid.fetch_add(1);
                clients[c_id]->_state = ST_INGAME; // 방에 입장했으므로 INGAME 상태로 변경
            }
            
            clients[c_id]->send_room_packet(id);

            std::cout << "Client [" << c_id << "] request create room," << p->requst <<" Room ID : " << id << std::endl;
            break;
        }
        case 1: {
            break;
        }
        default:
            break;
        }
        // TODO: C2S_ROOM 구현 시 clients[c_id]->_room_id = get_room_id();

        // 같은 룸에 있는 다른 클라이언트들에게 입장 정보 브로드캐스트
        /*for (auto& pl : clients) {
            if (pl.second->_id == c_id || ST_INGAME != pl.second->_state) continue;

            if (false == same_room(c_id, pl.second->_id)) continue;
            if (clients[c_id]->_room_id != pl.second->_room_id) continue;
            clients[c_id]->send_enter_packet(pl.second->_id);
            pl.second->send_enter_packet(c_id);
        }*/
    }
    case C2S_MOVE: {
        cs_packet_move* p = reinterpret_cast<cs_packet_move*>(packet);
        long long client_id = c_id;
        std::shared_ptr<session> current_session = clients[client_id];

        int new_x = current_session->_x;
        int new_y = current_session->_y;

     
        switch (p->direction) {
        case 'W': new_y--; break;   
        case 'S': new_y++; break;    
        case 'A': new_x--; break;   
        case 'D': new_x++; break;   
        default:
            std::cout << "Client [" << client_id << "] sent invalid move direction: " << p->direction << std::endl;
            return;
        }

        if (new_x < 0) new_x = 0;
        if (new_x >= 100) new_x = 99;
        if (new_y < 0) new_y = 0;
        if (new_y >= 100) new_y = 99;

        if (new_x != current_session->_x || new_y != current_session->_y) {
            {
                std::lock_guard<std::mutex> ll{ current_session->_s_lock };
                current_session->_x = new_x;
                current_session->_y = new_y;
            }
            std::cout << "Client [" << client_id << "] moved to (" << new_x << ", " << new_y << ")" << std::endl;

            for (auto& pl : clients) {
                if (pl.second->_id == client_id || ST_INGAME != pl.second->_state || pl.second->_room_id != current_session->_room_id) continue;
                pl.second->send_move_packet(client_id);
            }
            current_session->send_move_packet(client_id);
        }
        break;
    }
    case C2S_MISSION: {
        cs_packet_mission* p = reinterpret_cast<cs_packet_mission*>(packet);
        std::cout << "Client [" << c_id << "] requested mission." << std::endl;
        ROOM_EVENT ev;
        ev.client_id = c_id;
        ev.event_id = (EVENT_TYPE)p->mission;
        event_queue.push(ev);
        break;
    }
    case C2S_ATTACK: {
        cs_packet_attack* p = reinterpret_cast<cs_packet_attack*>(packet);
        std::cout << "Client [" << c_id << "] Attacked: " << std::endl;
        break;
    }
    case C2S_CHAT: {
        cs_packet_chat* p = reinterpret_cast<cs_packet_chat*>(packet);
        std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;
       
        for (auto& pl : clients) {
            if (ST_INGAME != pl.second->get_state() || pl.second->_room_id != clients[c_id]->_room_id) continue;

            pl.second->send_chat_packet(c_id, p->message);
        }
        break;
    }
    default:
        std::cout << "Unknown packet type received from client [" << c_id << "]: " << static_cast<int>(packet[1]) << std::endl;
        break;
    }
}

void disconnect(long long c_id) {
    if (clients.find(c_id) == clients.end() || clients[c_id]->_state == ST_FREE) {
        return;
    }

    std::cout << "Client [" << c_id << "] disconnected." << std::endl;

    int disconnected_room_id = clients[c_id]->_room_id;
    clients[c_id]->send_leave_packet(c_id);
    for (auto& pl : clients) {
        if (pl.second->_id == c_id) continue;
        if (ST_INGAME == pl.second->get_state() && pl.second->_room_id == disconnected_room_id) {
            pl.second->send_leave_packet(c_id);
        }
    }

    closesocket(clients[c_id]->_socket);

    {
        std::lock_guard<std::mutex> ll(clients[c_id]->_s_lock);
        clients[c_id]->_state = ST_FREE;
        clients[c_id]->_id = -1;
    }
}

void worker_thread(HANDLE h_iocp) {
    while (true) {
        DWORD num_bytes;
        ULONG_PTR key;
        WSAOVERLAPPED* over = nullptr;
        BOOL ret = GetQueuedCompletionStatus(h_iocp, &num_bytes, &key, &over, INFINITE);
        ex_over* exover = reinterpret_cast<ex_over*>(over);

        if (FALSE == ret) {
            if (exover->_comp_type == OP_ACCEPT) {
                std::cerr << "AcceptEx Error, WSAGetLastError: " << WSAGetLastError() << std::endl;
            }
            else {
                std::cerr << "GQCS Error on client[" << key << "], WSAGetLastError: " << WSAGetLastError() << std::endl;
                if (key != 9999) { 
                    disconnect(static_cast<long long>(key));
                }
            }
            if (exover->_comp_type == OP_SEND) delete exover;
            continue;
        }

        if ((0 == num_bytes) && ((exover->_comp_type == OP_RECV) || (exover->_comp_type == OP_SEND))) {
            disconnect(static_cast<long long>(key));
            if (exover->_comp_type == OP_SEND) delete exover;
            continue;
        }

        switch (exover->_comp_type) {
        case OP_ACCEPT: {
            long long client_id = get_new_client_id();
            if (client_id != -1 && client_id < MAX_USER) {
                if (clients.find(client_id) == clients.end() || clients[client_id] == nullptr) {
                    clients[client_id] = std::make_shared<session>();
                }

                {
                    std::lock_guard<std::mutex> ll(clients[client_id]->_s_lock);
                    clients[client_id]->_state = ST_ALLOC;
                }
                clients[client_id]->_x = 0;
                clients[client_id]->_y = 0;
                clients[client_id]->_id = client_id;
                clients[client_id]->_name[0] = 0;
                clients[client_id]->_prev_remain = 0;
                clients[client_id]->_socket = g_c_socket;
                clients[client_id]->_type = 0; // 임시
                clients[client_id]->_hp = 100;

                CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_c_socket),
                    h_iocp, client_id, 0);
                clients[client_id]->do_recv();
                std::cout << "New client accepted. ID: " << client_id << std::endl;

                g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
            }
            else {
                std::cout << "Max user exceeded or invalid client ID. Rejecting connection." << std::endl;
                closesocket(g_c_socket);
                g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
            }

            // 다음 AcceptEx를 위한 오버랩 초기화 및 호출
            ZeroMemory(&g_a_over._over, sizeof(g_a_over._over));
            int addr_size = sizeof(SOCKADDR_IN);
            AcceptEx(g_s_socket, g_c_socket, g_a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &g_a_over._over);
            break;
        }
        case OP_RECV: {
            long long client_id = static_cast<long long>(key);
            std::shared_ptr<session> current_session = clients[client_id];

            // 새로 받은 데이터를 세션의 수신 버퍼에 복사
            if (current_session->_prev_remain + num_bytes > BUF_SIZE) {
                std::cerr << "경고: 서버 수신 버퍼 오버플로우 (클라이언트 " << client_id << "). 연결 해제." << std::endl;
                disconnect(client_id);
                delete exover; // 오버랩드 객체 메모리 해제
                continue;
            }
            memcpy(current_session->_recv_buffer + current_session->_prev_remain, exover->_send_buf, num_bytes);
            current_session->_prev_remain += num_bytes;

            int current_processed_pos = 0; // 현재 버퍼에서 처리된 위치

            while (current_session->_prev_remain - current_processed_pos >= 1) {
                unsigned char packet_size = static_cast<unsigned char>(current_session->_recv_buffer[current_processed_pos]);

                if (packet_size == 0 || packet_size > BUF_SIZE) {
                    std::cerr << "Invalid packet size (" << static_cast<int>(packet_size) << ") received from client [" << client_id << "]. Disconnecting." << std::endl;
                    current_session->_prev_remain = 0; // 버퍼 초기화
                    disconnect(client_id);
                    break;
                }

                if (current_session->_prev_remain - current_processed_pos >= packet_size) {
                    process_packet(client_id, current_session->_recv_buffer + current_processed_pos);
                    current_processed_pos += packet_size;
                }
                else {
                    // 완전한 패킷이 아직 도착하지 않음
                    break;
                }
            }

            // 처리되지 않고 남아있는 데이터를 버퍼의 맨 앞으로 이동시킵니다.
            if (current_processed_pos > 0 && current_session->_prev_remain > current_processed_pos) {
                memmove(current_session->_recv_buffer, current_session->_recv_buffer + current_processed_pos, current_session->_prev_remain - current_processed_pos);
            }
            current_session->_prev_remain -= current_processed_pos;

            current_session->do_recv(); // 다음 WSARecv 호출
            //delete exover; // 사용된 오버랩드 객체 메모리 해제
            break;
        }
        case OP_SEND:
            delete exover;
            break;
        default:
            std::cerr << "Unknown completion type: " << exover->_comp_type << " on client [" << key << "]" << std::endl;
            break;
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

    if (bind(g_s_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        std::cerr << "bind failed: " << WSAGetLastError() << std::endl;
        closesocket(g_s_socket);
        WSACleanup();
        return 1;
    }

    if (listen(g_s_socket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "listen failed: " << WSAGetLastError() << std::endl;
        closesocket(g_s_socket);
        WSACleanup();
        return 1;
    }

    std::cout << "Server port : " << PORT << std::endl;

    // 서버의 로컬 IP 주소 출력
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

    CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_s_socket), h_iocp, 9999, 0);

    // AcceptEx를 위한 클라이언트 소켓 초기화
    g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (g_c_socket == INVALID_SOCKET) {
        std::cerr << "g_c_socket creation failed: " << WSAGetLastError() << std::endl;
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
            std::cerr << "AcceptEx failed: " << err << std::endl;
            CloseHandle(h_iocp);
            closesocket(g_s_socket);
            closesocket(g_c_socket);
            WSACleanup();
            return 1;
        }
    }
    std::cout << "Max user : " << MAX_USER << std::endl;

    // 워커 스레드 생성
    std::vector <std::thread> worker_threads;
    int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;

    for (int i = 0; i < num_threads; ++i) {
        worker_threads.emplace_back(worker_thread, h_iocp);
    }

    std::thread event_thread{ do_event };

    std::cout << "Worker threads : " << num_threads << std::endl;
    std::cout << "Now server is running" << std::endl;


    event_thread.join();
    for (auto& th : worker_threads) {
        th.join();
    }


    closesocket(g_s_socket);
    CloseHandle(h_iocp);
    WSACleanup();
    return 0;
}