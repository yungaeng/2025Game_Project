#pragma once
constexpr int BUF_SIZE = 265;
constexpr short PORT = 3000;

// ���̿� ũ�⿡ ���� ����
constexpr int  MAX_USER = 500;
constexpr int  VIEW_RANGE = 15;
constexpr short MAX_CHAT_LENGTH = 100;
constexpr char MAX_NAME_LENGTH = 20;
constexpr int MAX_ROOM_PLAYER = 5;

// ��Ŷ Ÿ��
constexpr char C2S_SIGNIN = 01;			// ȸ������
constexpr char C2S_LOGIN = 02;
constexpr char C2S_ROOM = 03;
constexpr char C2S_MISSION = 04;
constexpr char C2S_ATTACK = 05;
constexpr char C2S_CHAT = 06;
constexpr char C2S_LOGOUT = 07;

constexpr char S2C_LOGIN_OK = 10;
constexpr char S2C_LOGIN_FAIL = 11;
constexpr char S2C_MISSION = 12;
constexpr char S2C_ATTACK = 13;
constexpr char S2C_CHAT = 14;
constexpr char S2C_GAMEOVER = 15;

enum requst {
	create, join, leave
};
enum mission {
	control_fix, 
	armory_fix, 
	course_modifi,
	charging,
	radio,
	lab_temperature,
	bedroom_temperature
};

#pragma pack (push, 1)

struct cs_packet_signin {
	unsigned char  size;
	char  type;
	char  name[MAX_NAME_LENGTH];
};
struct cs_packet_login {
	unsigned char  size;
	char  type;
	char  name[MAX_NAME_LENGTH];
};
struct cs_packet_room {
	unsigned char size;
	char type;
	requst req;
};
struct cs_packet_mission {
	unsigned char  size;
	char  type;
	mission mis;
};
struct cs_packet_attack {
	unsigned char  size;
	char  type;
};
struct cs_packet_chat {
	unsigned char  size;
	char  type;
	char  message[MAX_CHAT_LENGTH];
};
struct cs_packet_logout {
	unsigned char  size;
	char  type;
};

struct sc_packet_login_ok
{
	unsigned char size;
	char type;
};
struct sc_packet_login_fail {
	unsigned char size;
	char type;
	long long  id;
	char reason;			// 0 : �˼� ���� ����
							// 1 : �ٸ� Ŭ���̾�Ʈ���� �����
							// 2 : �������� ID (Ư������, 20�� �̻�)
							// 3 : ������ ������ �ʹ� ����
							// 4 : �ش�Ǵ� ������ ����
};
struct sc_packet_mission {
	unsigned char  size;
	char  type;
	mission mis;
};
struct sc_packet_attack {
	unsigned char  size;
	char  type;
};
struct sc_packet_chat {
	unsigned char size;
	char type;
	long long  id;						// �޼����� ���� Object�� ID
										// -1 => SYSTEM MESSAG
	char message[MAX_CHAT_LENGTH];		// NULL terminated ���ڿ�
};
struct sc_packet_gameover {
	unsigned char size;
	char type;
	char result;	// 0 : ������
					// 1 : Ž�谡 ��
};

#pragma pack (pop)