#pragma once
#include <unordered_map>
#include "session.h"

enum ROOM_STATE { R_FREE, R_READY, R_INGAME };
atomic<int> room_num = -1;

struct ROOM {
	ROOM_STATE state = R_FREE;
	std::mutex rl;
	int id;
	int player;
	int control_fix_mission;
	int armory_fix_mission;
	bool course_modifi;
	vector<bool> charging_mission;
	bool radio_mission;
	bool lab_temperature_mission;
	bool bedroom_temperature_mission;
};
extern concurrency::concurrent_unordered_map<int, std::shared_ptr<ROOM>> rooms;

bool same_room(long long from, long long to) {
	if (clients[from]->_room_id == clients[to]->_room_id)
		return true;
}
int get_room_id() {
	// �غ� ���� ���ȣ ã��
	for (auto& r : rooms) {
		std::lock_guard <std::mutex> ll{ r.second->rl };
		if (r.second->state == R_READY)
			return r.second->id;
	}

	// �غ� ���� �� ����, �� �� ����
	return room_num++;
}
