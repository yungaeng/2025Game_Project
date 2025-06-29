#include <iostream>
#include <thread>
#include "..\IOCP-Unreal-Server\protocol.h"
#include "..\IOCP-Unreal-Server\net_header.h"

SOCKET client_socket;
std::thread RecvThread;
long long myid = -1;
bool is_connected = false;

char ip_address[100] = "127.0.0.1";
char g_recv_buffer[BUF_SIZE];
int g_packet_offset = 0;

void draw() {};

void disconnect_client() {
    if (!is_connected) return;

    is_connected = false;
    myid = -1;

    // RecvThread가 실행 중이고 joinable한 경우에만 join을 시도합니다.
    // 이는 recv_thread 내부에서 disconnect_client가 호출될 때 이미 스레드가 종료 중일 수 있기 때문입니다.
    if (RecvThread.joinable()) {
        shutdown(client_socket, SD_BOTH); // 수신 스레드가 recv에서 블록되지 않도록 합니다.
        RecvThread.join();
    }
    if (client_socket != INVALID_SOCKET) {
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
    }
    std::cout << "클라이언트 연결이 해제되었습니다." << std::endl;
    draw();
}
void process_packet(char* packet)
{
    switch (packet[1]) {
    case S2C_LOGIN_OK: {
        // 로그인 성공 패킷 처리 (필요한 경우 추가 로직)
        std::cout << "로그인 성공!" << std::endl;
        break;
    }
    case S2C_LOGIN_FAIL: {
        // 로그인 실패 패킷 처리 (필요한 경우 추가 로직)
        std::cout << "로그인 실패!" << std::endl;
        disconnect_client(); // 로그인 실패 시 연결 해제
        break;
    }
    case S2C_AVATAR_INFO: {
        sc_packet_avatar_info* p = reinterpret_cast<sc_packet_avatar_info*>(packet);
        if (myid == -1)
            myid = p->id;
        std::cout << "연결 성공! ID: " << myid << " (" << p->x << ", " << p->y << ")에 로그인됨." << std::endl;
        break;
    }
    case S2C_MOVE: {
        sc_packet_move* p = reinterpret_cast<sc_packet_move*>(packet);
        if (p->id == myid) {
            std::cout << "내 이동: " << p->x << ", " << p->y << std::endl;
        }
        std::cout << "다른 플레이어 이동 ID: "<< p->id<< ", " << p->x << ", " << p->y << std::endl;
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
            disconnect_client(); // 자신이 떠나면 연결 해제
        }
        else {
            std::cout << "플레이어 [ID: " << p->id << "] 퇴장." << std::endl;
        }
        break;
    }
    case S2C_STAT_CHANGE: {
        sc_packet_stat_change* p = reinterpret_cast<sc_packet_stat_change*>(packet);
        std::cout << "스탯 변경 - ID: " << p->id << ", HP: " << p->hp << std::endl;
        break;
    }
    case S2C_CHAT: {
        sc_packet_chat* p = reinterpret_cast<sc_packet_chat*>(packet);
        if (p->id == -1) {
            std::cout << "[시스템 메시지]: " << p->message << std::endl;
        }
        else {
            std::cout << "[ID: " << p->id << "]: " << p->message << std::endl;
        }
        break;
    }
    default:
        std::cout << "알 수 없는 패킷 타입 수신 : " << static_cast<int>(packet[1]) << std::endl;
        break;
    }
}
void handle_packet(char* packet, int bytes_received)
{
    // 새로 받은 데이터를 전역 수신 버퍼의 현재 offset 위치에 복사합니다.
    if (g_packet_offset + bytes_received > BUF_SIZE) {
        // 버퍼 오버플로우 방지 및 경고
        std::cerr << "경고: 수신 버퍼 오버플로우 발생! 데이터 손실 가능성. 클라이언트 연결 해제." << std::endl;
        disconnect_client();
        return;
    }
    memcpy(g_recv_buffer + g_packet_offset, packet, bytes_received);
    g_packet_offset += bytes_received;

    int current_processed_pos = 0; // 현재 버퍼에서 처리된 위치

    while (g_packet_offset - current_processed_pos >= 1) { // 최소한 패킷 크기(1바이트)를 읽을 수 있는지 확인
        unsigned char packet_size = static_cast<unsigned char>(g_recv_buffer[current_processed_pos]);

        if (packet_size == 0 || packet_size > BUF_SIZE) {
            std::cout << "경고: 잘못된 패킷 크기 수신 (" << static_cast<int>(packet_size) << "). 버퍼 초기화 및 연결 해제." << std::endl;
            g_packet_offset = 0; // 버퍼 초기화
            disconnect_client(); // 잘못된 패킷은 보통 프로토콜 오류이므로 연결을 끊습니다.
            return; // 함수 종료
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
    if (current_processed_pos > 0 && g_packet_offset > current_processed_pos) {
        memmove(g_recv_buffer, g_recv_buffer + current_processed_pos, g_packet_offset - current_processed_pos);
    }
    g_packet_offset -= current_processed_pos; // 남은 데이터의 offset 업데이트
}
void recv_thread()
{
    char buf[2048];
    while (is_connected)
    {
        int ret = recv(client_socket, buf, sizeof(buf), 0);
        if (ret > 0) {
            handle_packet(buf, ret);
            draw();
        }
        else if (ret == 0) {
            std::cout << "서버와 연결이 종료되었습니다." << std::endl;
            disconnect_client();
            break;
        }
        else {
            int error_code = WSAGetLastError();
            if (error_code != WSAEWOULDBLOCK && is_connected)
            {
                std::cout << "데이터 수신 중 오류 발생! 코드: " << error_code << std::endl;
                disconnect_client();
            }
            break;
        }
    }
}
void send_login(const char* name)
{
    if (!is_connected) {
        std::cout << "로그인 패킷을 보낼 수 없습니다: 서버에 연결되지 않았습니다." << std::endl;
        return;
    }
    cs_packet_login login_packet;
    login_packet.size = sizeof(login_packet);
    login_packet.type = C2S_LOGIN;
    strcpy_s(login_packet.name, sizeof(login_packet.name), name);
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&login_packet), sizeof(login_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "로그인 패킷 전송 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
    else {
        std::cout << "로그인 패킷 전송 완료. 이름: " << name << std::endl;
    }
}
bool connect_to_server(const char* ip_address) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup 실패!" << std::endl;
        return false;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        std::cout << "소켓 생성 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) != 1) {
        std::cout << "유효하지 않은 IP 주소입니다: " << ip_address << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    std::cout << "서버에 연결 중... (" << ip_address << ":" << PORT << ")" << std::endl;
    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        int err_code = WSAGetLastError();
        std::cout << "서버 연결 실패! 오류 코드: " << err_code << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    is_connected = true;
    std::cout << "서버 연결 성공!" << std::endl;

    RecvThread = std::thread(recv_thread); // 수신 스레드 시작
    return true;
}
void send_move(const char dir)
{
    if (!is_connected || myid == -1) {
        std::cout << "이동 패킷을 보낼 수 없습니다: 로그인되지 않았거나 연결되지 않았습니다." << std::endl;
        return;
    }
    cs_packet_move move_packet;
    move_packet.size = sizeof(move_packet);
    move_packet.type = C2S_MOVE;
    move_packet.direction = dir;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&move_packet), sizeof(move_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "이동 패킷 전송 실패! 오류 코드 : " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_attack() {
    if (!is_connected || myid == -1) {
        std::cout << "공격 패킷을 보낼 수 없습니다: 로그인되지 않았거나 연결되지 않았습니다." << std::endl;
        return;
    }
    cs_packet_attack attack_packet;
    attack_packet.size = sizeof(attack_packet);
    attack_packet.type = C2S_ATTACK;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&attack_packet), sizeof(attack_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "공격 패킷 전송 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_chat(const char* message)
{
    if (!is_connected || myid == -1) {
        std::cout << "채팅 패킷을 보낼 수 없습니다: 로그인되지 않았거나 연결되지 않았습니다." << std::endl;
        return;
    }
    cs_packet_chat chat_packet;
    chat_packet.size = sizeof(chat_packet);
    chat_packet.type = C2S_CHAT;
    strcpy_s(chat_packet.message, MAX_CHAT_LENGTH, message);
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&chat_packet), sizeof(chat_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "채팅 패킷 전송 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_mission(const char mission) {
    if (!is_connected || myid == -1) {
        std::cout << "미션 패킷을 보낼 수 없습니다: 로그인되지 않았거나 연결되지 않았습니다." << std::endl;
        return;
    }
    cs_packet_mission mission_packet;
    mission_packet.size = sizeof(mission_packet);
    mission_packet.type = C2S_MISSION;
    mission_packet.mission = mission;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&mission_packet), sizeof(mission_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "미션 패킷 전송 실패! 오류 코드: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}

int main() {
    if (!connect_to_server(ip_address)) {
        return -1;
    }

    send_login("test");

    while (is_connected) {
        std::cout << "input : ";
        char input;
        std::cin >> input;
        switch (input)
        {
        case 'M': {
            // send move;
            char dir =  rand() % 4;
            send_move(dir);
            break;
        }
        case 'A': {
            // send attack
            send_attack();
            break;
        }
        case 'C': {
            // send chat;
            char msg[MAX_CHAT_LENGTH];
            std::cout << "message : ";
            std::cin >> msg;
            send_chat(msg);
            break;
        }
        case 'T': {
            // send misstion
            char mission = rand() % 7;
            send_mission(mission);
            break;
        }
        default:
            break;
        }


        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    WSACleanup();
    return 0;
}