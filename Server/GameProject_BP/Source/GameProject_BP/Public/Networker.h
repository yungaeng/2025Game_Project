// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "protocol.h"

/**
 * 
 */

// 로그인 성공 시 호출될 델리게이트를 정의합니다.
DECLARE_MULTICAST_DELEGATE(FOnLoginOkDelegate);

class GAMEPROJECT_BP_API Networker : public TSharedFromThis<Networker>
{
public:
	Networker(class FSocket* Socket);
	~Networker();

	void RecvThreadRun();
	void Disconnect();

    // 델리게이트 선언
    FOnLoginOkDelegate OnLoginOk;
public:
	class FSocket* m_Socket;
	TSharedPtr<class RecvWorker> m_RecvworkerPtr;

    bool m_login = false;
	bool m_gameover = false;
    char m_result;
};

