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
SOCKET g_s_socket, g_c_socket; // g_c_socket은 AcceptEx용 임시 소켓
ex_over g_a_over; // AcceptEx 오버랩 구조체

concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;
concurrency::concurrent_unordered_map<int, ROOM> rooms;

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
    // 맵에서 shared_ptr를 안전하게 가져옴
    auto it = clients.find(c_id);
    if (it == clients.end()) {
        std::cerr << "Error: Client ID " << c_id << " not found in clients map when processing packet." << std::endl;
        return;
    }
    std::shared_ptr<session> current_session = it->second; // shared_ptr 복사

    // 세션이 이미 ST_FREE 상태라면 더 이상 처리하지 않음
    if (current_session->_state == ST_FREE) {
        std::cerr << "Error: Client ID " << c_id << " is in ST_FREE state, skipping packet processing." << std::endl;
        return;
    }

    switch (packet[1]) {
    case C2S_LOGIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            std::lock_guard<std::mutex> ll(current_session->_s_lock); // _s_lock으로 보호
            strcpy_s(current_session->_name, sizeof(current_session->_name), p->name);
            current_session->_state = ST_INGAME; // 로그인 성공 시 INGAME 상태로 변경
        }

        current_session->send_login_ok_packet();
        current_session->send_avata_info_packet();

        std::cout << "Client [" << c_id << "] logged in as " << current_session->_name << std::endl;

        // 같은 방에 있는 다른 클라이언트들에게 입장 정보 브로드캐스트 (로그인 성공 후 바로 게임 입장으로 가정)
        // C2S_ROOM 처리와 중복될 수 있으므로, 어떤 시점에 입장 패킷을 보낼지 결정해야 함
        // 예시: 로그인 후 바로 로비/기본 방에 입장한다면
        for (auto& pl_pair : clients) {
            std::shared_ptr<session> other_session = pl_pair.second;
            if (other_session->_id == c_id) continue; // 자신에게는 보내지 않음

            // 다른 클라이언트에게 내가 입장했음을 알림
            if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                // 다른 플레이어가 내 정보를 받도록
                other_session->send_enter_packet(c_id);
            }
        }
        // 나에게 다른 모든 플레이어의 입장 정보를 보냄
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
        case 0: { // 방 생성 요청
            int id = get_room_id(); // 새 방 ID 획득
            // TODO: 실제 ROOM 객체 생성 및 관리 로직 필요 (rooms 맵에 추가)

            {   // 클라이언트의 방 ID 설정 및 상태 변경
                std::lock_guard<std::mutex> ll(current_session->_s_lock);
                current_session->_room_id = id;
                current_session->_pid = pid_counter.fetch_add(1); // pid_counter로 변경
                current_session->_state = ST_INGAME;
            }

            current_session->send_room_packet(id);

            std::cout << "Client [" << c_id << "] requested to create room, Room ID : " << id << std::endl;
            break;
        }
        case 1: { // 방 입장 요청 (추가 구현 필요)
            // p->room_id 에 따라 해당 방으로 입장 처리
            //std::cout << "Client [" << c_id << "] requested to join room " << p->room_id << std::endl;
            // TODO: 기존 방에 클라이언트 입장 로직 구현
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
                std::lock_guard<std::mutex> ll{ current_session->_s_lock }; // 세션의 멤버에 접근 전 락
                current_session->_x = new_x;
                current_session->_y = new_y;
            }
            std::cout << "Client [" << c_id << "] moved to (" << new_x << ", " << new_y << ")" << std::endl;

            // 같은 방의 다른 클라이언트들에게 이동 정보 브로드캐스트
            for (auto& pl_pair : clients) {
                std::shared_ptr<session> other_session = pl_pair.second;
                if (other_session->_id == c_id) continue;
                // ST_INGAME 상태인지, 같은 방인지 확인 (락 없이 상태/룸ID 접근 가능하도록 설계 필요)
                // 현재 shared_ptr로 복사했기 때문에 다른 스레드에서 객체가 해제될 위험은 줄지만,
                // _state나 _room_id가 변경될 수 있는 Race Condition은 여전히 존재할 수 있음.
                // 그러나 atomic 변수이거나 변경이 잦지 않고 큰 문제가 아니라면 괜찮을 수 있습니다.
                if (other_session->get_state() == ST_INGAME && other_session->_room_id == current_session->_room_id) {
                    other_session->send_move_packet(c_id);
                }
            }
            // 이동한 클라이언트에게도 자신의 이동 정보 전송 (클라이언트 동기화 목적)
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
        event_queue.push(ev); // 이벤트 큐에 푸시
        break;
    }
    case C2S_ATTACK: {
        // cs_packet_attack* p = reinterpret_cast<cs_packet_attack*>(packet); // p가 사용되지 않아 주석 처리
        std::cout << "Client [" << c_id << "] Attacked." << std::endl;
        // 공격 로직 구현
        break;
    }
    case C2S_CHAT: {
        cs_packet_chat* p = reinterpret_cast<cs_packet_chat*>(packet);
        std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;

        // 같은 방에 있는 모든 클라이언트에게 채팅 브로드캐스트
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
    // 맵에서 shared_ptr를 안전하게 가져옴
    auto it = clients.find(c_id);
    if (it == clients.end()) {
        // 이미 맵에 없거나 처리되었을 경우 (중복 호출 방지)
        return;
    }
    std::shared_ptr<session> disconnected_session = it->second;

    // 이미 ST_FREE 상태라면 중복 처리 방지
    if (disconnected_session->_state == ST_FREE) {
        return;
    }

    std::cout << "Client [" << c_id << "] disconnected." << std::endl;

    int disconnected_room_id = -1;
    {
        std::lock_guard<std::mutex> ll(disconnected_session->_s_lock);
        disconnected_room_id = disconnected_session->_room_id; // 락을 걸고 룸 ID를 가져옴
        disconnected_session->_state = ST_FREE; // 상태를 FREE로 변경
        disconnected_session->_id = -1; // ID 무효화
    }

    // 소켓 닫기
    closesocket(disconnected_session->_socket);

    // 같은 방의 다른 클라이언트들에게 퇴장 정보 브로드캐스트
    // 여기서 clients 맵을 순회하는 동안 다른 스레드에서 disconnect가 호출될 수 있으므로 주의 필요
    // concurrent_unordered_map이므로 순회 자체는 안전하지만,
    // pl.second->get_state()나 _room_id 접근 시점의 데이터 일관성 문제 발생 가능성.
    // 하지만 대부분의 경우 짧은 불일치는 문제가 되지 않음.
    for (auto& pl_pair : clients) {
        std::shared_ptr<session> other_session = pl_pair.second;
        if (other_session->_id == c_id) continue; // 자신에게는 보내지 않음

        // 다른 세션이 아직 유효하고 같은 방에 있었다면 퇴장 패킷 전송
        if (other_session->get_state() == ST_INGAME && other_session->_room_id == disconnected_room_id) {
            other_session->send_leave_packet(c_id);
        }
    }

    // 클라이언트 맵에서 shared_ptr 제거 -> 참조 카운트가 0이 되면 session 객체 자동 해제
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

        // GQCS 오류 처리 (over가 NULL일 가능성도 있음)
        if (FALSE == ret) {
            if (exover == nullptr) { // over가 NULL인 경우 (timeout 또는 다른 GQCS 오류)
                std::cerr << "GQCS returned FALSE with NULL OVERLAPPED. Continuing..." << std::endl;
                continue;
            }
            if (exover->_comp_type == OP_ACCEPT) {
                std::cerr << "AcceptEx Error during GQCS: " << GetLastError() << std::endl;
            }
            else {
                std::cerr << "GQCS Error on client[" << key << "], Type: " << exover->_comp_type << ", Error: " << GetLastError() << std::endl;
                disconnect(static_cast<long long>(key)); // 오류 발생 클라이언트 연결 해제
            }
            if (exover->_comp_type == OP_SEND) {
                delete exover; // send 완료 후 ex_over는 삭제해야 함
            }
            continue;
        }

        // 정상 종료 또는 클라이언트가 소켓을 닫은 경우 (num_bytes == 0)
        if ((0 == num_bytes) && ((exover->_comp_type == OP_RECV) || (exover->_comp_type == OP_SEND))) {
            disconnect(static_cast<long long>(key));
            if (exover->_comp_type == OP_SEND) {
                delete exover; // send 완료 후 ex_over는 삭제해야 함
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
                    new_session->_state = ST_ALLOC; // 새 연결은 우선 ALLOC 상태로
                }
                new_session->_x = 0;
                new_session->_y = 0;
                new_session->_id = client_id;
                new_session->_name[0] = 0; // 이름 초기화
                new_session->_prev_remain = 0;
                new_session->_socket = g_c_socket; // Accepted된 소켓 할당

                // IOCP에 새로 연결된 클라이언트 소켓 등록
                CreateIoCompletionPort(reinterpret_cast<HANDLE>(new_session->_socket), h_iocp, client_id, 0);

                new_session->do_recv(); // 첫 리시브 요청
                std::cout << "New client accepted: ID " << client_id << std::endl;
            }
            else {
                std::cerr << "Max user limit exceeded. Closing new client socket." << std::endl;
                closesocket(g_c_socket); // 새롭게 연결된 소켓 닫기
            }

            // 다음 AcceptEx를 위한 새로운 g_c_socket 생성
            g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
            if (g_c_socket == INVALID_SOCKET) {
                std::cerr << "Failed to create new g_c_socket for next AcceptEx: " << GetLastError() << std::endl;
                // 이 경우 서버가 더 이상 새 연결을 받을 수 없게 됨. 심각한 오류.
            }

            // 다음 AcceptEx 요청
            ZeroMemory(&g_a_over._over, sizeof(g_a_over._over));
            int addr_size = sizeof(SOCKADDR_IN);
            if (FALSE == AcceptEx(g_s_socket, g_c_socket, g_a_over._send_buf, 0, addr_size + 16, addr_size + 16, 0, &g_a_over._over)) {
                int err = GetLastError();
                if (err != WSA_IO_PENDING) {
                    std::cerr << "AcceptEx failed immediately after previous accept: " << err << std::endl;
                    // 서버가 더 이상 새 연결을 받지 못하게 됨.
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
            char* p = exover->_send_buf; // 이 버퍼는 exover에 붙어있는 버퍼

            while (remain_data > 0) {
                int packet_size = p[0];
                // 패킷 크기 검증 (최소 1바이트 이상이어야 함)
                if (packet_size <= 0 || packet_size > BUF_SIZE) { // BUF_SIZE는 정의되어 있어야 함
                    std::cerr << "Invalid packet size (" << packet_size << ") from client [" << key << "]. Disconnecting." << std::endl;
                    disconnect(static_cast<long long>(key));
                    break;
                }

               
                if (packet_size <= remain_data) {
                    process_packet(static_cast<long long>(key), p); // 패킷 처리
                    p = p + packet_size;
                    remain_data = remain_data - packet_size;
                }
                else {
                    break; // 완전한 패킷이 아직 도착하지 않음
                }
            }
            current_session->_prev_remain = remain_data;
            if (remain_data > 0) {
                // 처리되지 않은 데이터를 버퍼의 맨 앞으로 복사
                memcpy(exover->_send_buf, p, remain_data);
            }
            current_session->do_recv(); // 다음 리시브 요청
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