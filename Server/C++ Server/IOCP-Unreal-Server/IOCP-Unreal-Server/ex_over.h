#pragma once
#include "net_header.h"
#include "protocol.h"

enum COMP_TYPE { OP_ACCEPT, OP_RECV, OP_SEND, OP_DISCONNECT, OP_GAMESTART };

class ex_over{
public:
	WSAOVERLAPPED _over;
	WSABUF _wsabuf;
	char _send_buf[BUF_SIZE];
	COMP_TYPE _comp_type;
	ex_over()
	{
		_wsabuf.len = BUF_SIZE;
		_wsabuf.buf = _send_buf;
		_comp_type = OP_RECV;
		ZeroMemory(&_over, sizeof(_over));
		_send_buf[0] = 0;
	}
	ex_over(char* packet)
	{
		_wsabuf.len = packet[0];
		_wsabuf.buf = _send_buf;
		ZeroMemory(&_over, sizeof(_over));
		_comp_type = OP_SEND;
		memcpy(_send_buf, packet, packet[0]);
	}
};

