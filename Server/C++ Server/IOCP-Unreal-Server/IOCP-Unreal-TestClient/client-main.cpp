#include <iostream>
#include <thread>
#include <atomic> // std::atomic�� ����ϱ� ���� �߰�
#include <string>   // std::string�� ����ϱ� ���� �߰�

#include "..\IOCP-Unreal-Server\protocol.h"
#include "..\IOCP-Unreal-Server\net_header.h" 

SOCKET client_socket;
std::thread RecvThread;
long long myid = -1;
std::atomic<bool> is_connected = false; // atomic���� ����
std::atomic<bool> exit_thread = false;  // ���� ������ ���� ��ȣ�� ���� atomic ���� �߰�

char ip_address[100] = "127.0.0.1";
char g_recv_buffer[BUF_SIZE];
int g_packet_offset = 0;

void draw() {
    
};

void disconnect_client() {
    // �̹� ������ �������ų�, �ٸ� �����忡�� ���� ������ ��û�ߴٸ� �ߺ� ó�� ����
    if (!is_connected.exchange(false)) { // is_connected�� false�� �����ϰ� ���� �� �������� (atomic)
        // �̹� false���ٸ� �ٷ� ����
        return;
    }

    myid = -1;

    // ���� �����尡 recv()���� ��ϵǾ� �ִٸ� shutdown���� ����
    if (client_socket != INVALID_SOCKET) {
        shutdown(client_socket, SD_BOTH);
    }

    // ���� �����尡 ����� ������ ��ٸ�
    // �߿�: RecvThread.join()�� �� �Լ��� ȣ���� ������(���� main)������ ȣ���ؾ� �մϴ�.
    // recv_thread_func() ���ο��� disconnect_client()�� ���� ȣ���Ͽ� join�ϸ� ������� �߻��մϴ�.
    if (RecvThread.joinable()) {
        exit_thread = true; // �����忡�� �����ϰ� �����϶�� ��ȣ
        RecvThread.join(); // ���� �����尡 ������ ����� ������ ��ٸ�
    }

    // ���� �ݱ�
    if (client_socket != INVALID_SOCKET) {
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
    }
    std::cout << "Ŭ���̾�Ʈ ������ �����Ǿ����ϴ�." << std::endl;
    draw(); // UI ������Ʈ�� �ʿ��ϴٸ� ���� �����忡�� ����ǵ��� ����
}
void process_packet(char* packet)
{
    switch (packet[1]) {
    case S2C_LOGIN_OK: {
        std::cout << "�α��� ����!" << std::endl;
        is_connected = true;
        break;
    }
    case S2C_LOGIN_FAIL: {
        sc_packet_login_fail* p = reinterpret_cast<sc_packet_login_fail*>(packet);
        std::cout << "�α��� ����! ������ ��û�� �ź��߽��ϴ�. ���� �ڵ�" << p->reason << std::endl;
        is_connected = false;
        break;
    }
    case S2C_AVATAR_INFO: {
        sc_packet_avatar_info* p = reinterpret_cast<sc_packet_avatar_info*>(packet);
        if (myid == -1) { // myid�� ���� �������� �ʾҴٸ� (���� �α���)
            myid = p->id;
        }
        std::cout << "���� ����! ID: " << myid << " (" << p->x << ", " << p->y << ")�� �α��ε�." << std::endl;
        break;
    }
    case S2C_ROOM: {
        sc_packet_room* p = reinterpret_cast<sc_packet_room*>(packet);
        std::cout << "�濡 �����Ͽ����ϴ�. �� ��ȣ : " << p->roomid << "PID : " << p->pid << std::endl;
        break;
    }
    case S2C_MOVE: {
        sc_packet_move* p = reinterpret_cast<sc_packet_move*>(packet);
        if (p->id == myid) {
            std::cout << "�� �̵�: " << p->x << ", " << p->y << std::endl;
        }
        else {
            std::cout << "�ٸ� �÷��̾� �̵� ID: " << p->id << ", " << p->x << ", " << p->y << std::endl;
        }
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
            is_connected = false; // �ڽ��� �������Ƿ� ���� ���� ��ȣ
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
        if (p->id == -1) { // �ý��� �޽���
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
void recv_thread_func() // �̸� ����: recv_thread -> recv_thread_func (���� ���� RecvThread�� ȥ�� ����)
{
    char buf[BUF_SIZE]; // BUF_SIZE�� �����ϰ� ����
    while (is_connected && !exit_thread) // is_connected�� exit_thread�� ��� Ȯ��
    {
        int ret = recv(client_socket, buf, sizeof(buf), 0);
        if (ret > 0) {
            handle_packet(buf, ret);
            draw(); // UI ������Ʈ�� �ʿ��ϴٸ� ���� ������� �޽����� ������ ��� ���
        }
        else if (ret == 0) {
            std::cout << "������ ������ ����Ǿ����ϴ�." << std::endl;
            is_connected = false; // ���� ���� ��ȣ
            break;
        }
        else {
            int error_code = WSAGetLastError();
            // WSAEWOULDBLOCK�� non-blocking ���Ͽ��� �����Ͱ� ���� �� �߻��ϴ� ���̹Ƿ�,
            // blocking ���Ͽ����� �Ϲ������� �߻����� �ʽ��ϴ�.
            // ������ ������ ���� �־�Ӵϴ�.
            if (error_code != WSAEWOULDBLOCK && is_connected)
            {
                std::cerr << "������ ���� �� ���� �߻�! �ڵ�: " << error_code << std::endl;
                is_connected = false; // ���� ���� ��ȣ
            }
            break; // ���� �߻� �� ������ ����
        }
    }
    std::cout << "���� ������ ����." << std::endl;
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
    strcpy_s(login_packet.name, sizeof(login_packet.name), name); // MAX_NAME_LEN ���� �ʿ�
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&login_packet), sizeof(login_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cerr << "�α��� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        is_connected = false; // ���� ���� �� ���� ���� ��ȣ
    }
    else {
        std::cout << "�α��� ��Ŷ ���� �Ϸ�. �̸�: " << name << std::endl;
    }
}
void send_room(const char requst) {
    if (!is_connected) {
        std::cout << "�� ��Ŷ�� ���� �� �����ϴ�: ������ ������� �ʾҽ��ϴ�." << std::endl;
        return;
    }
    cs_packet_room room_packet;
    room_packet.size = sizeof(room_packet);
    room_packet.type = C2S_ROOM;
    room_packet.requst = requst;
    int sent_bytes = send(client_socket, reinterpret_cast<char*>(&room_packet), sizeof(room_packet), 0);
    if (sent_bytes == SOCKET_ERROR) {
        std::cerr << "�α��� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        is_connected = false; // ���� ���� �� ���� ���� ��ȣ
    }
    else {
        std::cout << "�� ��Ŷ ���� �Ϸ�. Ÿ��: " << requst << std::endl;
    }
}
bool connect_to_server(const char* ip_address_str) { // ip_address�� �̸� �浹 ����
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
        std::cerr << "���� ���� ����! ���� �ڵ�: " << err_code << std::endl;
        closesocket(client_socket);
        client_socket = INVALID_SOCKET;
        WSACleanup();
        return false;
    }

    is_connected = true; // ���� ����!
    std::cout << "���� ���� ����!" << std::endl;

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
        std::cerr << "�̵� ��Ŷ ���� ����! ���� �ڵ� : " << WSAGetLastError() << std::endl;
        is_connected = false;
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
        std::cerr << "���� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        is_connected = false;
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
        std::cerr << "ä�� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        is_connected = false;
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
        std::cerr << "�̼� ��Ŷ ���� ����! ���� �ڵ�: " << WSAGetLastError() << std::endl;
        is_connected = false;
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
    send_login("test_user"); // �׽�Ʈ�� ����� �̸�

    // 4. ���� ����: ����� �Է� ó�� �Ǵ� ���� ���� ����
    
    std::cout << "\n��ɾ �Է��ϼ��� ('M': �̵�, 'A': ����, 'C': ä��, 'T': �̼�, 'Q': ����):" << std::endl;
    char input_char;
    std::string chat_message;

    while (is_connected) { // is_connected�� false�� �Ǹ� ���� ����
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

    disconnect_client();


    WSACleanup();
    std::cout << "Ŭ���̾�Ʈ ���α׷��� ���������� ����Ǿ����ϴ�." << std::endl;
    return 0;
}