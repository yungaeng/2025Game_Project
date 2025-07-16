// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "protocol.h"
#include <unordered_map>

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

    bool m_login = false;
	bool m_gameover = false;
    char m_result;
};

