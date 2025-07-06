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
        std::cerr << "WSAStartup ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        return false;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        std::cerr << "���� ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address_str, &server_addr.sin_addr) != 1) {
        std::cerr << "��ȿ���� ���� IP �ּ��Դϴ�: " << ip_address_str << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    std::cout << "������ ���� ��... (" << ip_address_str << ":" << PORT << ")" << std::endl;
    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        int err_code = WSAGetLastError();
        std::cerr << "������ ã�� ���Ͽ����ϴ�! ���� �ڵ�: " << err_code << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    is_connected = true;
    std::cout << "������ ã�ҽ��ϴ�!" << std::endl;
    return true;
}
void send_signin(const char* name) {
    cs_packet_signin signin_packet;
    signin_packet.size = sizeof(signin_packet);
    signin_packet.type = C2S_SIGNIN;
    strcpy_s(signin_packet.name, sizeof(signin_packet.name), name); // MAX_NAME_LEN ���� �ʿ�
    send(client_socket, reinterpret_cast<char*>(&signin_packet), sizeof(signin_packet), 0);
}
void send_login(const char* name) {
    cs_packet_login login_packet;
    login_packet.size = sizeof(login_packet);
    login_packet.type = C2S_LOGIN;
    strcpy_s(login_packet.name, sizeof(login_packet.name), name); // MAX_NAME_LEN ���� �ʿ�
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
        std::cout << "�α��� ����!" << std::endl;
        is_connected = true;
        break;
    }
    case S2C_LOGIN_FAIL: {
        sc_packet_login_fail* p = reinterpret_cast<sc_packet_login_fail*>(packet);
        std::cout << "�α��� ����! ������ ��û�� �ź��߽��ϴ�. ���� �ڵ�" << int(p->reason) << std::endl;
        break;
    }
    case S2C_AVATAR_INFO: {
        sc_packet_avatar_info* p = reinterpret_cast<sc_packet_avatar_info*>(packet);
        // myid�� ���� �������� �ʾҴٸ� ���� �α���
        if (myid == -1) 
            myid = p->id;
        std::cout << "���� ����! ID: " << myid << " (" << p->x << ", " << p->y << ")�� �α��ε�." << std::endl;
        break;
    }
    case S2C_ROOM: {
        sc_packet_room* p = reinterpret_cast<sc_packet_room*>(packet);
        std::cout << "�濡 �����Ͽ����ϴ�. �� ��ȣ : " << p->roomid << "PID : " << p->pid << std::endl;
        break;
    }
    case S2C_MOVE: {
       // TODO
        break;
    }
    case S2C_ENTER: {
        sc_packet_enter* p = reinterpret_cast<sc_packet_enter*>(packet);
        std::cout << "�÷��̾� [ID: " << p->id << ", �̸�: " << p->name << "] (" << p->x << ", " << p->y << ") ����." << std::endl;
        break;
    }
    case S2C_LEAVE: {
        sc_packet_leave* p = reinterpret_cast<sc_packet_leave*>(packet);
        if (p->id == myid) {
            myid = -1;
            std::cout << "�ڽ��� ���ӿ��� �������ϴ�." << std::endl;
        }
        else
            std::cout << "�÷��̾� [ID: " << p->id << "] ����." << std::endl;
        break;
    }
    case S2C_STAT_CHANGE: {
        // TODO
        break;
    }
    case S2C_CHAT: {
        sc_packet_chat* p = reinterpret_cast<sc_packet_chat*>(packet);
        if (p->id == -1) // �ý��� �޽���
            std::cout << "[�ý��� �޽���]: " << p->message << std::endl;
        else
            std::cout << "[ID: " << p->id << "]: " << p->message << std::endl;
        break;
    }
    default:
        break;
    }
}
void handle_packet(char* packet, int bytes_received) {
    // ���� ���� �����͸� ���� ���� ������ ���� offset ��ġ�� �����մϴ�.
    if (g_packet_offset + bytes_received > BUF_SIZE) {
        std::cerr << "���: ���� ���� �����÷ο� �߻�! ������ �ս� ���ɼ�. ���� ����." << std::endl;
        is_connected = false; // ���� ���� ��ȣ
        return;
    }
    memcpy(g_recv_buffer + g_packet_offset, packet, bytes_received);
    g_packet_offset += bytes_received;

    int current_processed_pos = 0; // ���� ���ۿ��� ó���� ��ġ

    while (g_packet_offset - current_processed_pos >= 1) { // �ּ��� ��Ŷ ũ��(1����Ʈ)�� ���� �� �ִ��� Ȯ��
        unsigned char packet_size = static_cast<unsigned char>(g_recv_buffer[current_processed_pos]);

        if (packet_size == 0 || packet_size > BUF_SIZE) {
            std::cerr << "���: �߸��� ��Ŷ ũ�� ���� (" << static_cast<int>(packet_size) << "). ���� �ʱ�ȭ �� ���� ����." << std::endl;
            g_packet_offset = 0; // ���� �ʱ�ȭ
            is_connected = false; // ���� ���� ��ȣ
            return;
        }

        if (g_packet_offset - current_processed_pos >= packet_size) { // ������ ��Ŷ�� �ִ��� Ȯ��
            process_packet(g_recv_buffer + current_processed_pos);

            current_processed_pos += packet_size; // ó���� ����Ʈ��ŭ �̵�
        }
        else {
            // ������ ��Ŷ�� ���� �������� ����
            break;
        }
    }

    // ó������ �ʰ� �����ִ� �����͸� ������ �� ������ �̵���ŵ�ϴ�.
    if (current_processed_pos > 0) {
        if (g_packet_offset - current_processed_pos > 0) {
            memmove(g_recv_buffer, g_recv_buffer + current_processed_pos, g_packet_offset - current_processed_pos);
        }
        g_packet_offset -= current_processed_pos; // ���� �������� offset ������Ʈ
    }
}
void recv_thread_func() {
    char buf[BUF_SIZE];
    while (is_connected)
    {
        int ret = recv(client_socket, buf, sizeof(buf), 0);
        if (ret == 0) {
            // ������ �������� ����
            std::cout << "������ ����Ǿ����ϴ�." << std::endl;
            is_connected = false;
            break;
        }
        else if (ret > 0) {
            // �����Ͱ� ����
            handle_packet(buf, ret);
        }
        else {
            // ������ recv
            int error_code = WSAGetLastError();
            if (error_code != WSAEWOULDBLOCK && is_connected)
            {
                std::cerr << "������ ���� �� ���� �߻�! �ڵ�: " << error_code << std::endl;
                is_connected = false;
            }
            break;
        }
    }
}

int main() {
    // 1. ���� ���� �õ�
    if (!connect_to_server(ip_address)) {
        std::cerr << "���� ���ῡ �����Ͽ� ���α׷��� �����մϴ�." << std::endl;
        return -1;
    }

    // 2. ���� ������ ����
    RecvThread = std::thread(recv_thread_func);
    
    // 3. �α��� ��Ŷ ����
    // ��ȿ�� ���̵� �ް�, �����κ��� ok�� ���� �� ����
    while (-1 == myid) {
        std::cout << "1. ȸ������" << std::endl;
        std::cout << "2. �α���" << std::endl;
        std::string input;
        std::getline(std::cin, input);

        switch (std::stoi(input))
        {
        case 1: {
            std::cout << "�̸��� �Է��ϼ��� : ";
            std::string name;
            std::getline(std::cin, name);
            send_signin(name.c_str());
            break;
        }
        case 2: {
            std::cout << "�̸��� �Է��ϼ��� : ";
            std::string name;
            std::getline(std::cin, name);
            send_login(name.c_str());
            break;
        }
        default:
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // ������ CPU ���� ����
    }

    // 4. ���� ����: ����� �Է� ó�� �Ǵ� ���� ���� ����
    while (is_connected) { // is_connected�� false�� �Ǹ� ���� ����
        std::cout << "��ɾ �Է��ϼ��� " << std::endl;
        std::cout << "'M': �̵�" << std::endl;
        std::cout << "'R' : �� �䫊" << std::endl;
        std::cout << "'A' : ����" << std::endl;
        std::cout << "'C' : ä��" << std::endl;
        std::cout << "'T' : �̼�" << std::endl;
        std::cout << "'Q' : ����" << std::endl;
        char input_char;
        std::string chat_message;

        std::cout << "> ";
        std::cin >> input_char;

        switch (toupper(input_char)) { // ��ҹ��� ���� ���� ó��
        case 'M': {
            std::cout << "�̵� ���� �Է� (W/A/S/D): ";
            char move_dir;
            std::cin >> move_dir;
            send_move(toupper(move_dir));
            break;
        }
        case 'R': {
            std::cout << "��û Ÿ�� create/join/leave (C/J/L)";
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
            std::cout << "�޽��� �Է�: ";
            std::cin.ignore(); // ���� �Է��� \n ����
            std::getline(std::cin, chat_message);
            send_chat(chat_message.c_str());
            break;
        }
        case 'T': {
            std::cout << "�̼� Ÿ�� �Է� (����): ";
            int mission_type_int;
            std::cin >> mission_type_int;
            send_mission(static_cast<char>(mission_type_int));
            break;
        }
        case 'Q': {
            std::cout << "Ŭ���̾�Ʈ ���� ��û." << std::endl;
            is_connected = false;
            break;
        }
        default: {
            std::cout << "�� �� ���� ��ɾ��Դϴ�. (M, A, C, T, Q)" << std::endl;
            break;
        }
        }

        // ���� ���� �÷��װ� �����Ǿ����� �ٽ� Ȯ���Ͽ� ������ ��� ������ �� �ֵ��� ��
        if (!is_connected) {
            std::cout << "�������� ������ �������ų� ���� ��û���� ���� ������ �����մϴ�." << std::endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(10)); // ������ CPU ���� ����
    }

    // ���⼭ Ŭ���̾�Ʈ ����
    // ���� ����/������ ����
    RecvThread.join();
    closesocket(client_socket);
    WSACleanup();
    std::cout << "Ŭ���̾�Ʈ ���α׷��� ���������� ����Ǿ����ϴ�." << std::endl;
    return 0;

}