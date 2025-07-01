#pragma once
#include <concurrent_priority_queue.h>

enum EVENT_TYPE { EV_CONTROL_FIX, EV_ARMORY_FIX, EV_COURSE_MODIFI, EV_CHARGING, EV_RADIO, EV_LAB_TEM, EV_BEDROOM_TEM };
struct ROOM_EVENT {
	long long client_id;
	EVENT_TYPE event_id;
	constexpr bool operator < (const ROOM_EVENT& L) const {
		return (client_id > L.client_id);
	}
};

extern concurrency::concurrent_priority_queue<ROOM_EVENT> event_queue;

void do_event() {
	while (true) {
		ROOM_EVENT ev;
		if (true == event_queue.try_pop(ev)) {
			long long player_id = ev.client_id;
			auto& player = clients[player_id];
			switch (ev.event_id) {
			case EV_CONTROL_FIX: {
				// 플레이어가 접속 중이고 게임중인지 확인
				if (player && player->_state == ST_INGAME && rooms[player->_room_id]->state == R_INGAME) {
					//lock_guard<mutex> ll(rooms[player->_room_id].rl);
					rooms[player->_room_id]->control_fix_mission++;
				}
			}
			case EV_ARMORY_FIX: {
				if (player && player->_state == ST_INGAME && rooms[player->_room_id]->state == R_INGAME) {
					//lock_guard<mutex> ll(rooms[player->_room_id].rl);
					rooms[player->_room_id]->armory_fix_mission++;
				}
			}
			case EV_COURSE_MODIFI: {
				if (player && player->_state == ST_INGAME && rooms[player->_room_id]->state == R_INGAME) {
					//lock_guard<mutex> ll(rooms[player->_room_id].rl);
					if(!rooms[player->_room_id]->course_modifi)
						rooms[player->_room_id]->course_modifi = true;
				}
			}
			case EV_CHARGING: {
				for (auto& r : rooms) {
					//std::lock_guard <std::mutex> ll{ r.second.rl };
					if (!rooms[player->_room_id]->charging_mission[player_id])
						rooms[player->_room_id]->charging_mission[player_id] = true;
				}
				break;
			}
			case EV_RADIO: {
				for (auto& r : rooms) {
					//std::lock_guard <std::mutex> ll{ r.second.rl };
					if (!rooms[player->_room_id]->radio_mission)
						rooms[player->_room_id]->radio_mission = true;
				}
				break;
			}
			case EV_LAB_TEM: {
				for (auto& r : rooms) {
					//std::lock_guard <std::mutex> ll{ r.second.rl };
					if (!rooms[player->_room_id]->lab_temperature_mission)
						rooms[player->_room_id]->lab_temperature_mission = true;
				}
				break;
			}
			case EV_BEDROOM_TEM: {
				for (auto& r : rooms) {
					//std::lock_guard <std::mutex> ll{ r.second.rl };
					if (!rooms[player->_room_id]->bedroom_temperature_mission)
						rooms[player->_room_id]->bedroom_temperature_mission = true;
				}
				break;
			}
			default:
				break;
			}
			continue;
		}
	}
}