#pragma once
#include <unordered_map>
#include "session.h"

enum ROOM_STATE { R_FREE, R_READY, R_INGAME };
atomic<int> room_num = -1;

struct ROOM {
	ROOM_STATE state = R_FREE;
	std::mutex rl;

	int id;
	int control_fix_mission;
	int armory_fix_mission;
	bool course_modifi;
	vector<bool> charging_mission;
	bool radio_mission;
	bool lab_temperature_mission;
	bool bedroom_temperature_mission;
};
extern concurrency::concurrent_unordered_map<int, std::shared_ptr<ROOM>> rooms;
extern std::mutex map_lock;

// 모든 룸 데이터에 접근하는 함수들인 main에서 lock_guard 처리를 이미 하였다고 가정한다.

bool same_room(long long from, long long to) {
	if (clients[from]->_room_id == clients[to]->_room_id)
		return true;
}

int create_room_num() {
	room_num.fetch_add(1);
	return room_num;
}

int get_room_id() {
	// 준비 중인 방번호 찾기
	for (auto& r : rooms) {
		std::lock_guard <std::mutex> ll{ r.second->rl };
		if (r.second->state == R_READY && r.second->charging_mission.size() < MAX_ROOM_PLAYER)
			return r.second->id;
	}

	// 대기중인 방이 없음
	return -1;
}

void mission_clear(int roomid, char mission) {
	for (auto& r : rooms) {
		if (r.second->id == roomid)
		{
			switch (mission)
			{
			case 0: {
				r.second->control_fix_mission++;
				break;
			}
			case 1: {
				r.second->armory_fix_mission++;
			    break;
			}
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			default:
				break;
			}
		}
	}
}