#pragma once
#include <iostream>
#include <thread>
#include <atomic>
#include <string>
#include "../IOCP-Unreal-Server/protocol.h"
#include "../IOCP-Unreal-Server\net_header.h" 

SOCKET client_socket;
std::thread RecvThread;
long long myid = -1;
std::atomic<bool> is_connected = false;

char ip_address[100] = "127.0.0.1";
char g_recv_buffer[BUF_SIZE];
int g_packet_offset = 0;

bool connect_to_server(const char* ip_address_str) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        return false;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        std::cerr << "소켓 생성 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address_str, &server_addr.sin_addr) != 1) {
        std::cerr << "유효하지 않은 IP 주소입니다: " << ip_address_str << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    std::cout << "서버에 연결 중... (" << ip_address_str << ":" << PORT << ")" << std::endl;
    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        int err_code = WSAGetLastError();
        std::cerr << "서버를 찾지 못하였습니다! 오류 코드: " << err_code << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    is_connected = true;
    std::cout << "서버를 찾았습니다!" << std::endl;
    return true;
}
void send_signin(const char* name) {
    cs_packet_signin signin_packet;
    signin_packet.size = sizeof(signin_packet);
    signin_packet.type = C2S_SIGNIN;
    strcpy_s(signin_packet.name, sizeof(signin_packet.name), name); // MAX_NAME_LEN 정의 필요
    send(client_socket, reinterpret_cast<char*>(&signin_packet), sizeof(signin_packet), 0);
}
void send_login(const char* name) {
    cs_packet_login login_packet;
    login_packet.size = sizeof(login_packet);
    login_packet.type = C2S_LOGIN;
    strcpy_s(login_packet.name, sizeof(login_packet.name), name); // MAX_NAME_LEN 정의 필요
    send(client_socket, reinterpret_cast<char*>(&login_packet), sizeof(login_packet), 0);
}
void send_room(const char requst) {
    cs_packet_room room_packet;
    room_packet.size = sizeof(room_packet);
    room_packet.type = C2S_ROOM;
    room_packet.requst = requst;
    send(client_socket, reinterpret_cast<char*>(&room_packet), sizeof(room_packet), 0);
}

void send_move(const char dir) {
    cs_packet_move move_packet;
    move_packet.size = sizeof(move_packet);
    move_packet.type = C2S_MOVE;
    move_packet.direction = dir;
    send(client_socket, reinterpret_cast<char*>(&move_packet), sizeof(move_packet), 0);
}
void send_attack() {
    cs_packet_attack attack_packet;
    attack_packet.size = sizeof(attack_packet);
    attack_packet.type = C2S_ATTACK;
    send(client_socket, reinterpret_cast<char*>(&attack_packet), sizeof(attack_packet), 0);
}
void send_chat(const char* message) {
    cs_packet_chat chat_packet;
    chat_packet.size = sizeof(chat_packet);
    chat_packet.type = C2S_CHAT;
    strcpy_s(chat_packet.message, MAX_CHAT_LENGTH, message);
    send(client_socket, reinterpret_cast<char*>(&chat_packet), sizeof(chat_packet), 0);
}
void send_mission(const char mission) {
    cs_packet_mission mission_packet;
    mission_packet.size = sizeof(mission_packet);
    mission_packet.type = C2S_MISSION;
    mission_packet.mission = mission;
    send(client_socket, reinterpret_cast<char*>(&mission_packet), sizeof(mission_packet), 0);
}

void process_packet(char* packet) {
    switch (packet[1]) {
    case S2C_LOGIN_OK: {
        std::cout << "로그인 성공!" << std::endl;
        is_connected = true;
        break;
    }
    case S2C_LOGIN_FAIL: {
        sc_packet_login_fail* p = reinterpret_cast<sc_packet_login_fail*>(packet);
        std::cout << "로그인 실패! 서버가 요청을 거부했습니다. 에러 코드" << int(p->reason) << std::endl;
        break;
    }
    case S2C_AVATAR_INFO: {
        sc_packet_avatar_info* p = reinterpret_cast<sc_packet_avatar_info*>(packet);
        // myid가 아직 설정되지 않았다면 최초 로그인
        if (myid == -1) 
            myid = p->id;
        std::cout << "연결 성공! ID: " << myid << " (" << p->x << ", " << p->y << ")에 로그인됨." << std::endl;
        break;
    }
    case S2C_ROOM: {
        sc_packet_room* p = reinterpret_cast<sc_packet_room*>(packet);
        std::cout << "방에 입장하였습니다. 방 번호 : " << p->roomid << "PID : " << p->pid << std::endl;
        break;
    }
    case S2C_MOVE: {
       // TODO
        break;
    }
    case S2C_ENTER: {
        sc_packet_enter* p = reinterpret_cast<sc_packet_enter*>(packet);
        std::cout << "플레이어 [ID: " << p->id << ", 이름: " << p->name << "] (" << p->x << ", " << p->y << ") 입장." << std::endl;
        break;
    }
    case S2C_LEAVE: {
        sc_packet_leave* p = reinterpret_cast<sc_packet_leave*>(packet);
        if (p->id == myid) {
            myid = -1;
            std::cout << "자신이 게임에서 떠났습니다." << std::endl;
        }
        else
            std::cout << "플레이어 [ID: " << p->id << "] 퇴장." << std::endl;
        break;
    }
    case S2C_STAT_CHANGE: {
        // TODO
        break;
    }
    case S2C_CHAT: {
        sc_packet_chat* p = reinterpret_cast<sc_packet_chat*>(packet);
        if (p->id == -1) // 시스템 메시지
            std::cout << "[시스템 메시지]: " << p->message << std::endl;
        else
            std::cout << "[ID: " << p->id << "]: " << p->message << std::endl;
        break;
    }
    default:
        break;
    }
}
void handle_packet(char* packet, int bytes_received) {
    // 새로 받은 데이터를 전역 수신 버퍼의 현재 offset 위치에 복사합니다.
    if (g_packet_offset + bytes_received > BUF_SIZE) {
        std::cerr << "경고: 수신 버퍼 오버플로우 발생! 데이터 손실 가능성. 연결 종료." << std::endl;
        is_connected = false; // 연결 종료 신호
        return;
    }
    memcpy(g_recv_buffer + g_packet_offset, packet, bytes_received);
    g_packet_offset += bytes_received;

    int current_processed_pos = 0; // 현재 버퍼에서 처리된 위치

    while (g_packet_offset - current_processed_pos >= 1) { // 최소한 패킷 크기(1바이트)를 읽을 수 있는지 확인
        unsigned char packet_size = static_cast<unsigned char>(g_recv_buffer[current_processed_pos]);

        if (packet_size == 0 || packet_size > BUF_SIZE) {
            std::cerr << "경고: 잘못된 패킷 크기 수신 (" << static_cast<int>(packet_size) << "). 버퍼 초기화 및 연결 종료." << std::endl;
            g_packet_offset = 0; // 버퍼 초기화
            is_connected = false; // 연결 종료 신호
            return;
        }

        if (g_packet_offset - current_processed_pos >= packet_size) { // 완전한 패킷이 있는지 확인
            process_packet(g_recv_buffer + current_processed_pos);

            current_processed_pos += packet_size; // 처리된 바이트만큼 이동
        }
        else {
            // 완전한 패킷이 아직 도착하지 않음
            break;
        }
    }

    // 처리되지 않고 남아있는 데이터를 버퍼의 맨 앞으로 이동시킵니다.
    if (current_processed_pos > 0) {
        if (g_packet_offset - current_processed_pos > 0) {
            memmove(g_recv_buffer, g_recv_buffer + current_processed_pos, g_packet_offset - current_processed_pos);
        }
        g_packet_offset -= current_processed_pos; // 남은 데이터의 offset 업데이트
    }
}
void recv_thread_func() {
    char buf[BUF_SIZE];
    while (is_connected)
    {
        int ret = recv(client_socket, buf, sizeof(buf), 0);
        if (ret == 0) {
            // 서버의 정상적인 종료
            std::cout << "서버가 종료되었습니다." << std::endl;
            is_connected = false;
            break;
        }
        else if (ret > 0) {
            // 데이터가 있음
            handle_packet(buf, ret);
        }
        else {
            // 비정상 recv
            int error_code = WSAGetLastError();
            if (error_code != WSAEWOULDBLOCK && is_connected)
            {
                std::cerr << "데이터 수신 중 오류 발생! 코드: " << error_code << std::endl;
                is_connected = false;
            }
            break;
        }
    }
}

int main() {
    // 1. 서버 연결 시도
    if (!connect_to_server(ip_address)) {
        std::cerr << "서버 연결에 실패하여 프로그램을 종료합니다." << std::endl;
        return -1;
    }

    // 2. 수신 스레드 시작
    RecvThread = std::thread(recv_thread_func);
    
    // 3. 로그인 패킷 전송
    // 유효한 아이디를 받고, 서버로부터 ok를 받을 때 까지
    while (-1 == myid) {
        std::cout << "1. 회원가입" << std::endl;
        std::cout << "2. 로그인" << std::endl;
        std::string input;
        std::getline(std::cin, input);

        switch (std::stoi(input))
        {
        case 1: {
            std::cout << "이름을 입력하세요 : ";
            std::string name;
            std::getline(std::cin, name);
            send_signin(name.c_str());
            break;
        }
        case 2: {
            std::cout << "이름을 입력하세요 : ";
            std::string name;
            std::getline(std::cin, name);
            send_login(name.c_str());
            break;
        }
        default:
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 과도한 CPU 점유 방지
    }

    // 4. 메인 루프: 사용자 입력 처리 또는 게임 로직 진행
    while (is_connected) { // is_connected가 false가 되면 루프 종료
        std::cout << "명령어를 입력하세요 " << std::endl;
        std::cout << "'M': 이동" << std::endl;
        std::cout << "'R' : 방 요쳥" << std::endl;
        std::cout << "'A' : 공격" << std::endl;
        std::cout << "'C' : 채팅" << std::endl;
        std::cout << "'T' : 미션" << std::endl;
        std::cout << "'Q' : 종료" << std::endl;
        char input_char;
        std::string chat_message;

        std::cout << "> ";
        std::cin >> input_char;

        switch (toupper(input_char)) { // 대소문자 구분 없이 처리
        case 'M': {
            std::cout << "이동 방향 입력 (W/A/S/D): ";
            char move_dir;
            std::cin >> move_dir;
            send_move(toupper(move_dir));
            break;
        }
        case 'R': {
            std::cout << "요청 타입 create/join/leave (C/J/L)";
            char move_dir;
            std::cin >> move_dir;
            send_room(toupper(move_dir));
            break;
        }
        case 'A': {
            send_attack();
            break;
        }
        case 'C': {
            std::cout << "메시지 입력: ";
            std::cin.ignore(); // 이전 입력의 \n 무시
            std::getline(std::cin, chat_message);
            send_chat(chat_message.c_str());
            break;
        }
        case 'T': {
            std::cout << "미션 타입 입력 (숫자): ";
            int mission_type_int;
            std::cin >> mission_type_int;
            send_mission(static_cast<char>(mission_type_int));
            break;
        }
        case 'Q': {
            std::cout << "클라이언트 종료 요청." << std::endl;
            is_connected = false;
            break;
        }
        default: {
            std::cout << "알 수 없는 명령어입니다. (M, A, C, T, Q)" << std::endl;
            break;
        }
        }

        // 연결 끊김 플래그가 설정되었는지 다시 확인하여 루프를 즉시 종료할 수 있도록 함
        if (!is_connected) {
            std::cout << "서버와의 연결이 끊어졌거나 종료 요청으로 메인 루프를 종료합니다." << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // 과도한 CPU 점유 방지
    }

    // 여기서 클라이언트 종료
    // 소켓 해제/스레드 종료
    RecvThread.join();
    closesocket(client_socket);
    WSACleanup();
    std::cout << "클라이언트 프로그램이 성공적으로 종료되었습니다." << std::endl;
    return 0;

}