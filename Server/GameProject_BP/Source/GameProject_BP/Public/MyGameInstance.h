// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "protocol.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */

UCLASS()
class GAMEPROJECT_BP_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	bool ConnectToServer(FString AddrIP);
	UFUNCTION(BlueprintCallable)
	void DisconnectToServer();

    UFUNCTION(BlueprintCallable)
    void SendSignin(FString input);
	UFUNCTION(BlueprintCallable)
	void SendLogin(FString input);
	UFUNCTION(BlueprintCallable)
	void SendRoom(uint8 request);
	UFUNCTION(BlueprintCallable)
	void SendAttack();


    UFUNCTION(BlueprintCallable)
    bool GetLoginOk();
    UFUNCTION(BlueprintCallable)
    bool GetCharacter();
	UFUNCTION(BlueprintCallable)
	bool GetGameOver();
    UFUNCTION(BlueprintCallable)
    bool GetGameOverState();

public:
	// 서버와 연결
	class FSocket* m_Socket;
	FString m_IPAddr = TEXT("127.0.0.1");
	int16 m_Port = PORT;
	bool m_Connecting = false;

	// Recv작업을 위한 스레드를 생성하는 객체 포인터
	TSharedPtr<class Networker> m_NetworkerPtr;
};
