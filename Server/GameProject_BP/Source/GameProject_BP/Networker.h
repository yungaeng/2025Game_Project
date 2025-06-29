// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "protocol.h"
#include <unordered_map>
#include <mutex>
//#include "HAL/CriticalSection.h"

struct player {
	long long id;
	char name[MAX_NAME_LENGTH];
	float x, y, z;
	int hp;
	char type;
	char chat[MAX_CHAT_LENGTH];
};
/**
 * 
 */
class GAMEPROJECT_BP_API Networker : public TSharedFromThis<Networker>
{
public:
	Networker(class FSocket* Socket);
	~Networker();

	void RecvThreadRun();
	void Disconnect();
public:
	class FSocket* m_Socket;
	TSharedPtr<class RecvWorker> m_RecvworkerPtr;

	FString old_chat;

	std::unordered_map<long long, player> players;
	bool m_gameover;
	char m_result;
};

