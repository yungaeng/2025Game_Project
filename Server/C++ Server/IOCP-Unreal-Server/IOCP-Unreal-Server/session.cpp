#include "session.h"

void session::send_login_ok_packet() {
	sc_packet_login_ok p;
	p.type = S2C_LOGIN_OK;
	p.size = sizeof(p);
	do_send(&p);
}

void session::send_avata_info_packet() {
	sc_packet_avatar_info p;
	p.id = _id;
	p.size = sizeof(p);
	p.type = S2C_AVATAR_INFO;
	p.x = _x;
	p.y = _y;
	p.hp = _hp;
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

void session::send_room_packet(long long c_id)
{
	sc_packet_room p;
	p.type = S2C_ROOM;
	p.size = sizeof(p);
	do_send(&p);
}

void session::send_enter_packet(long long c_id) {
	sc_packet_enter p;
	p.id = c_id;
	strcpy_s(p.name, clients[c_id]->_name);
	p.size = sizeof(p);
	p.type = S2C_ENTER;
	p.x = clients[c_id]->_x;
	p.y = clients[c_id]->_y;
	p.z = clients[c_id]->_z;
	p.o_type = clients[c_id]->_type;
	do_send(&p);
} 

void session::send_move_packet(long long c_id) {
	sc_packet_move p;
	p.id = c_id;
	p.size = sizeof(p);
	p.type = S2C_MOVE;
	p.x = clients[c_id]->_x;
	p.y = clients[c_id]->_y;
	p.z = clients[c_id]->_z;
	do_send(&p);
}


void session::send_leave_packet(long long c_id) {
	sc_packet_leave p;
	p.id = c_id;
	p.size = sizeof(p);
	p.type = S2C_LEAVE;
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

void session::send_stat_change(long long affected_id, int hp) {
	sc_packet_stat_change p;
	p.size = sizeof(p);
	p.type = S2C_STAT_CHANGE;
	p.id = affected_id; // 변화 시킬 타겟
	p.hp = hp;
	do_send(&p);
}

void session::send_gameover() {
	sc_packet_gameover p;
	p.size = sizeof(p);
	p.type = S2C_GAMEOVER;
	p.result = 1;
	do_send(&p);
}