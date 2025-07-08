#include "server.h"

void server::InitServer()
{
    WSADATA WSAData;
    WSAStartup(MAKEWORD(2, 2), &WSAData);
    g_s_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.S_un.S_addr = INADDR_ANY;

    bind(g_s_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr));
    listen(g_s_socket, SOMAXCONN);

    // 서버의 로컬 IP 주소 출력 (이전 코드와 동일)
    char hostname[256];
    gethostname(hostname, sizeof(hostname));
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

    h_iocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);

    // 리스닝 소켓을 IOCP에 등록 (key 9999는 임의의 값)
    CreateIoCompletionPort(reinterpret_cast<HANDLE>(g_s_socket), h_iocp, 9999, 0);
}

bool server::ConnectToServer(const char* server_ip)
{
    // 워커 스레드 생성
    int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2; // 최소 2개 스레드 (CPU 코어 수를 얻지 못할 경우)

    for (int i = 0; i < num_threads; ++i) {
        worker_threads.emplace_back(WorkerThreadFunc, h_iocp);
    }

    event_thread = std::thread{do_event}; // 이벤트 처리 스레드

    std::cout << "Worker threads : " << num_threads << std::endl;
    std::cout << "Now server is running" << std::endl; 
}

void server::DisconnectToServer(long long c_id) {
    event_thread.join();
    for (auto& th : worker_threads) {
        th.join();
    }

    // 자원 해제
    closesocket(g_s_socket);
    CloseHandle(h_iocp);
    WSACleanup();

    closesocket(clients[c_id]->_socket);
    {
        lock_guard<mutex> ll(clients[c_id]->_s_lock);
        clients[c_id]->_state = ST_FREE;
    }
}

void server::ProcessPacket(long long c_id, char* packet) {
    switch (packet[1]) {
    case C2S_SIGNIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            lock_guard<mutex> ll{ clients[c_id]->_s_lock };
            strcpy_s(clients[c_id]->_name, p->name);
        }
        break;
    }
    case C2S_LOGIN: {
        cs_packet_login* p = reinterpret_cast<cs_packet_login*>(packet);
        {
            lock_guard<mutex> ll{ clients[c_id]->_s_lock };
            strcpy_s(clients[c_id]->_name, p->name);
        }
        std::string NAME = clients[c_id]->_name;
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
        std::cout << "Client [" << c_id << "] chatted: " << p->message << std::endl;
        clients[c_id]->send_chat_packet(c_id, p->message);
        break;
    }
    default:
        break;
    }
}

void server::AcceptThreadFunc() {
    // AcceptEx를 위한 클라이언트 소켓 초기화
    g_c_socket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED);
    if (g_c_socket == INVALID_SOCKET) {
        std::cerr << "g_c_socket creation failed for AcceptEx: " << WSAGetLastError() << std::endl;
        CloseHandle(h_iocp);
        closesocket(g_s_socket);
        WSACleanup();
        return;
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
            return;
        }
    }
    std::cout << "Max user : " << MAX_USER << std::endl;
}

void server::WorkerThreadFunc()
{
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
                DisconnectToServer(static_cast<int>(key));
                if (exover->_comp_type == OP_SEND) delete exover;
                continue;
            }
        }

        if ((0 == num_bytes) && ((exover->_comp_type == OP_RECV) || (exover->_comp_type == OP_SEND))) {
            DisconnectToServer(static_cast<int>(key));
            if (exover->_comp_type == OP_SEND) delete exover;
            continue;
        }

        switch (exover->_comp_type) {
        case OP_ACCEPT: {
            long long new_id = next_client_id.fetch_add(1);
            if (new_id >= MAX_USER) {
                return;
            }
            long long client_id = new_id;
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
                    ProcessPacket(static_cast<int>(key), p);
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
