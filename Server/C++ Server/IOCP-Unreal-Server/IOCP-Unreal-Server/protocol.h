#pragma once
constexpr int BUF_SIZE = 265;
constexpr short PORT = 3000;

// 길이와 크기에 대한 정보
constexpr int  MAX_USER = 500;
constexpr int  VIEW_RANGE = 15;
constexpr short MAX_CHAT_LENGTH = 100;
constexpr char MAX_NAME_LENGTH = 20;
constexpr int MAX_ROOM_PLAYER = 5;

// 패킷 타입
constexpr char C2S_SIGNIN = 01;			// 회원가입
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
	char reason;			// 0 : 알수 없는 이유
							// 1 : 다른 클라이언트에서 사용중
							// 2 : 부적절한 ID (특수문자, 20자 이상)
							// 3 : 서버에 동접이 너무 많음
							// 4 : 해당되는 계정이 없음
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
	long long  id;						// 메세지를 보낸 Object의 ID
										// -1 => SYSTEM MESSAG
	char message[MAX_CHAT_LENGTH];		// NULL terminated 문자열
};
struct sc_packet_gameover {
	unsigned char size;
	char type;
	char result;	// 0 : 임포승
					// 1 : 탐험가 승
};

#pragma pack (pop)