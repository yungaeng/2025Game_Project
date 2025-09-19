#include "session.h"

void session::send_login_ok_packet() {
	sc_packet_login_ok p;
	p.type = S2C_LOGIN_OK;
	p.size = sizeof(p);
	do_send(&p);
}

void session::send_login_fail_packet(char reason) {
	sc_packet_login_fail p;
	p.id = _id;
	p.size = sizeof(p);
	p.type = S2C_LOGIN_FAIL;
	p.reason = reason;
	do_send(&p);
}

void session::send_chat_packet(long long c_id, const char* mess) {
	sc_packet_chat p;
	p.id = c_id;
	p.size = sizeof(p);
	p.type = S2C_CHAT;
	strcpy_s(p.message, mess);
	do_send(&p);
}

void session::send_mission_packet(long long c_id, char miss)
{
	sc_packet_mission p;
	p.size = sizeof(p);
	p.type = S2C_MISSION;
	p.mis = static_cast<mission>(miss);
	do_send(&p);
}

void session::send_gameover(bool result) {
	sc_packet_gameover p;
	p.size = sizeof(p);
	p.type = S2C_GAMEOVER;
	p.IsImposterWin = result;
	do_send(&p);
}

void session::send_host(const char* ip)
{
	sc_packet_host p;
	p.size = sizeof(p);
	p.type = S2C_HOST;
	strcpy_s(p.ip, ip);
	do_send(&p);
}
