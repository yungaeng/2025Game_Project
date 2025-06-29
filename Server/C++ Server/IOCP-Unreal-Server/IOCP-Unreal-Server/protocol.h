#pragma once
constexpr int BUF_SIZE = 265;
constexpr short PORT = 3000;

// ���̿� ũ�⿡ ���� ����
constexpr int  MAX_USER = 500;
constexpr int  VIEW_RANGE = 15;
constexpr short MAX_CHAT_LENGTH = 255;
constexpr char MAX_NAME_LENGTH = 20;

// ��Ŷ Ÿ��
constexpr char C2S_LOGIN = 1;
constexpr char C2S_ROOM = 2;
constexpr char C2S_MOVE = 3;
constexpr char C2S_MISSION = 4;
constexpr char C2S_ATTACK = 5;
constexpr char C2S_CHAT = 6;
constexpr char C2S_TELEPORT = 7;		// ���� �׽�Ʈ �� ��
constexpr char C2S_LOGOUT = 8;

constexpr char S2C_LOGIN_OK = 9;
constexpr char S2C_LOGIN_FAIL = 10;
constexpr char S2C_ROOM = 11;
constexpr char S2C_AVATAR_INFO = 12;
constexpr char S2C_ENTER = 13;
constexpr char S2C_MOVE = 14;
constexpr char S2C_CHAT = 15;
constexpr char S2C_STAT_CHANGE = 16;
constexpr char S2C_LEAVE = 17;
constexpr char S2C_GAMEOVER = 18;

#pragma pack (push, 1)

struct cs_packet_login {
	unsigned char  size;
	char  type;
	char  name[MAX_NAME_LENGTH];
};
struct cs_packet_room
{
	unsigned char size;
	char type;
	char requst;
};
struct cs_packet_move {
	unsigned char  size;
	char  type;
	char  direction;
};
struct cs_packet_mission {
	unsigned char  size;
	char  type;
	char  mission;
};
struct cs_packet_attack {
	unsigned char  size;
	char  type;
};
struct cs_packet_chat {
	unsigned char  size;
	char  type;
	char  message[MAX_CHAT_LENGTH];		// NULL terminated ���ڿ�
};
struct cs_packet_teleport {
	unsigned char  size;
	char  type;
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
};
struct sc_packet_room
{
	unsigned char size;
	char type;
	int roomid;
	int pid;
};
struct sc_packet_avatar_info {
	unsigned char size;
	char type;
	long long  id;
	float x, y, z;
	int hp;
};
struct sc_packet_enter {
	unsigned char size;
	char type;
	long long  id;
	char name[MAX_NAME_LENGTH];
	char o_type;						// 0 : adventurer
										// 1 : imposter  
	float x, y, z;
};
struct sc_packet_move {
	unsigned char size;
	char type;
	long long id;
	float x, y, z;
};
struct sc_packet_chat {
	unsigned char size;
	char type;
	long long  id;						// �޼����� ���� Object�� ID
										// -1 => SYSTEM MESSAG
	char message[MAX_CHAT_LENGTH];		// NULL terminated ���ڿ�
};
struct sc_packet_stat_change {
	unsigned char size;
	char type;
	long long  id;
	int hp;
};
struct sc_packet_leave {
	unsigned char size;
	char type;
	long long  id;
};
struct sc_packet_gameover {
	unsigned char size;
	char type;
	char result;	// 0 : ������
					// 1 : Ž�谡 ��
};


#pragma pack (pop)