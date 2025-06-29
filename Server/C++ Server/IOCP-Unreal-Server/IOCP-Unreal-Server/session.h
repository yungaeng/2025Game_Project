#pragma once
#include "ex_over.h"
#include <mutex>
#include <concurrent_unordered_map.h>
using namespace std;

enum S_STATE { ST_FREE, ST_ALLOC, ST_INGAME };

class session {
	ex_over _recv_over;
public:
	mutex _s_lock;
	S_STATE _state;
	atomic_bool	_is_active;		// 주위에 플레이어가 있는가?
	long long _id;
	
	SOCKET _socket;
	float	_x, _y, _z;
	char _type;					// 0 : adventurer
								// 1 : imposter  
	int _hp;
	int _atk;
	int _room_id;
	int _pid;
	
	char	_name[MAX_NAME_LENGTH];
	char _recv_buffer[BUF_SIZE]; // 각 세션별 수신 버퍼
	int _prev_remain;
public:
	session() {
		_id = -1;
		_socket = 0;
		_x = _y = _z = 0;
		_hp = 50;
		_atk = 10;
		_name[0] = 0;
		_state = ST_FREE;
		memset(_recv_buffer, 0, BUF_SIZE);
		_prev_remain = 0;
		_type = 0;
	}
	~session() {}

	void do_recv() {
		DWORD recv_flag = 0;
		memset(&_recv_over._over, 0, sizeof(_recv_over._over));
		_recv_over._wsabuf.len = BUF_SIZE - _prev_remain;
		_recv_over._wsabuf.buf = _recv_over._send_buf + _prev_remain;
		WSARecv(_socket, &_recv_over._wsabuf, 1, 0, &recv_flag,
			&_recv_over._over, 0);
	}
	void do_send(void* packet) {
		ex_over* send_data = new ex_over{ reinterpret_cast<char*>(packet) };
		WSASend(_socket, &send_data->_wsabuf, 1, 0, 0, &send_data->_over, 0);
	}

public:
	void send_login_ok_packet();
	void send_avata_info_packet();
	void send_login_fail_packet(char reason);
	void send_room_packet(long long c_id);
	void send_enter_packet(long long c_id);
	void send_move_packet(long long c_id);
	void send_chat_packet(long long c_id, const char* mess);
	void send_stat_change(long long affected_id, int hp);
	void send_leave_packet(long long c_id);
	char get_state() { return _state; }
};
extern concurrency::concurrent_unordered_map<long long, std::shared_ptr<session>> clients;
