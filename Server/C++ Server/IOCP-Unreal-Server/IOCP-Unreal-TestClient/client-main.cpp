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

    // RecvThread�� ���� ���̰� joinable�� ��쿡�� join�� �õ��մϴ�.
    // �̴� recv_thread ���ο��� disconnect_client�� ȣ��� �� �̹� �����尡 ���� ���� �� �ֱ� �����Դϴ�.
    if (RecvThread.joinable()) {
        shutdown(client_socket, SD_BOTH); // ���� �����尡 recv���� ��ϵ��� �ʵ��� �մϴ�.
        RecvThread.join();
    }
    if (client_socket != INVALID_SOCKET) {
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
    }
    std::cout << "Ŭ���̾�Ʈ ������ �����Ǿ����ϴ�." << std::endl;
    draw();
}
void process_packet(char* packet)
{
    switch (packet[1]) {
    case S2C_LOGIN_OK: {
        // �α��� ���� ��Ŷ ó�� (�ʿ��� ��� �߰� ����)
        std::cout << "�α��� ����!" << std::endl;
        break;
    }
    case S2C_LOGIN_FAIL: {
        // �α��� ���� ��Ŷ ó�� (�ʿ��� ��� �߰� ����)
        std::cout << "�α��� ����!" << std::endl;
        disconnect_client(); // �α��� ���� �� ���� ����
        break;
    }
    case S2C_AVATAR_INFO: {
        sc_packet_avatar_info* p = reinterpret_cast<sc_packet_avatar_info*>(packet);
        if (myid == -1)
            myid = p->id;
        std::cout << "���� ����! ID: " << myid << " (" << p->x << ", " << p->y << ")�� �α��ε�." << std::endl;
        break;
    }
    case S2C_MOVE: {
        sc_packet_move* p = reinterpret_cast<sc_packet_move*>(packet);
        if (p->id == myid) {
            std::cout << "�� �̵�: " << p->x << ", " << p->y << std::endl;
        }
        std::cout << "�ٸ� �÷��̾� �̵� ID: "<< p->id<< ", " << p->x << ", " << p->y << std::endl;
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
            disconnect_client(); // �ڽ��� ������ ���� ����
        }
        else {
            std::cout << "�÷��̾� [ID: " << p->id << "] ����." << std::endl;
        }
        break;
    }
    case S2C_STAT_CHANGE: {
        sc_packet_stat_change* p = reinterpret_cast<sc_packet_stat_change*>(packet);
        std::cout << "���� ���� - ID: " << p->id << ", HP: " << p->hp << std::endl;
        break;
    }
    case S2C_CHAT: {
        sc_packet_chat* p = reinterpret_cast<sc_packet_chat*>(packet);
        if (p->id == -1) {
            std::cout << "[�ý��� �޽���]: " << p->message << std::endl;
        }
        else {
            std::cout << "[ID: " << p->id << "]: " << p->message << std::endl;
        }
        break;
    }
    default:
        std::cout << "�� �� ���� ��Ŷ Ÿ�� ���� : " << static_cast<int>(packet[1]) << std::endl;
        break;
    }
}
void handle_packet(char* packet, int bytes_received)
{
    // ���� ���� �����͸� ���� ���� ������ ���� offset ��ġ�� �����մϴ�.
    if (g_packet_offset + bytes_received > BUF_SIZE) {
        // ���� �����÷ο� ���� �� ���
        std::cerr << "���: ���� ���� �����÷ο� �߻�! ������ �ս� ���ɼ�. Ŭ���̾�Ʈ ���� ����." << std::endl;
        disconnect_client();
        return;
    }
    memcpy(g_recv_buffer + g_packet_offset, packet, bytes_received);
    g_packet_offset += bytes_received;

    int current_processed_pos = 0; // ���� ���ۿ��� ó���� ��ġ

    while (g_packet_offset - current_processed_pos >= 1) { // �ּ��� ��Ŷ ũ��(1����Ʈ)�� ���� �� �ִ��� Ȯ��
        unsigned char packet_size = static_cast<unsigned char>(g_recv_buffer[current_processed_pos]);

        if (packet_size == 0 || packet_size > BUF_SIZE) {
            std::cout << "���: �߸��� ��Ŷ ũ�� ���� (" << static_cast<int>(packet_size) << "). ���� �ʱ�ȭ �� ���� ����." << std::endl;
            g_packet_offset = 0; // ���� �ʱ�ȭ
            disconnect_client(); // �߸��� ��Ŷ�� ���� �������� �����̹Ƿ� ������ �����ϴ�.
            return; // �Լ� ����
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
    if (current_processed_pos > 0 && g_packet_offset > current_processed_pos) {
        memmove(g_recv_buffer, g_recv_buffer + current_processed_pos, g_packet_offset - current_processed_pos);
    }
    g_packet_offset -= current_processed_pos; // ���� �������� offset ������Ʈ
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
            std::cout << "������ ������ ����Ǿ����ϴ�." << std::endl;
            disconnect_client();
            break;
        }
        else {
            int error_code = WSAGetLastError();
            if (error_code != WSAEWOULDBLOCK && is_connected)
            {
                std::cout << "������ ���� �� ���� �߻�! �ڵ�: " << error_code << std::endl;
                disconnect_client();
            }
            break;
        }
    }
}
void send_login(const char* name)
{
    if (!is_connected) {
        std::cout << "�α��� ��Ŷ�� ���� �� �����ϴ�: ������ ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_login login_packet;
    login_packet.size = sizeof(login_packet);
    login_packet.type = C2S_LOGIN;
    strcpy_s(login_packet.name, sizeof(login_packet.name), name);
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&login_packet), sizeof(login_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "�α��� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
    else {
        std::cout << "�α��� ��Ŷ ���� �Ϸ�. �̸�: " << name << std::endl;
    }
}
bool connect_to_server(const char* ip_address) {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup ����!" << std::endl;
        return false;
    }

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == INVALID_SOCKET) {
        std::cout << "���� ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return false;
    }

    SOCKADDR_IN server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) != 1) {
        std::cout << "��ȿ���� ���� IP �ּ��Դϴ�: " << ip_address << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    std::cout << "������ ���� ��... (" << ip_address << ":" << PORT << ")" << std::endl;
    if (connect(client_socket, reinterpret_cast<sockaddr*>(&server_addr), sizeof(server_addr)) == SOCKET_ERROR) {
        int err_code = WSAGetLastError();
        std::cout << "���� ���� ����! ���� �ڵ�: " << err_code << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    is_connected = true;
    std::cout << "���� ���� ����!" << std::endl;

    RecvThread = std::thread(recv_thread); // ���� ������ ����
    return true;
}
void send_move(const char dir)
{
    if (!is_connected || myid == -1) {
        std::cout << "�̵� ��Ŷ�� ���� �� �����ϴ�: �α��ε��� �ʾҰų� ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_move move_packet;
    move_packet.size = sizeof(move_packet);
    move_packet.type = C2S_MOVE;
    move_packet.direction = dir;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&move_packet), sizeof(move_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "�̵� ��Ŷ ���� ����! ���� �ڵ� : " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_attack() {
    if (!is_connected || myid == -1) {
        std::cout << "���� ��Ŷ�� ���� �� �����ϴ�: �α��ε��� �ʾҰų� ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_attack attack_packet;
    attack_packet.size = sizeof(attack_packet);
    attack_packet.type = C2S_ATTACK;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&attack_packet), sizeof(attack_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "���� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_chat(const char* message)
{
    if (!is_connected || myid == -1) {
        std::cout << "ä�� ��Ŷ�� ���� �� �����ϴ�: �α��ε��� �ʾҰų� ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_chat chat_packet;
    chat_packet.size = sizeof(chat_packet);
    chat_packet.type = C2S_CHAT;
    strcpy_s(chat_packet.message, MAX_CHAT_LENGTH, message);
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&chat_packet), sizeof(chat_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "ä�� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        disconnect_client();
    }
}
void send_mission(const char mission) {
    if (!is_connected || myid == -1) {
        std::cout << "�̼� ��Ŷ�� ���� �� �����ϴ�: �α��ε��� �ʾҰų� ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_mission mission_packet;
    mission_packet.size = sizeof(mission_packet);
    mission_packet.type = C2S_MISSION;
    mission_packet.mission = mission;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&mission_packet), sizeof(mission_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cout << "�̼� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
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