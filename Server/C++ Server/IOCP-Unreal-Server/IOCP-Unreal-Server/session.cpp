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

void session::send_gameover() {
	sc_packet_gameover p;
	p.size = sizeof(p);
	p.type = S2C_GAMEOVER;
	p.result = 1;
	do_send(&p);
}