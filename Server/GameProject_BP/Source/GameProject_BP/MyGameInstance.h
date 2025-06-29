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
	void SendLogin();
	UFUNCTION(BlueprintCallable)
	void SendRoom(uint8 request);
	UFUNCTION(BlueprintCallable)
	void SendAttack();


	UFUNCTION(BlueprintCallable)
	bool GetGameOver();


public:
	// ������ ����
	class FSocket* m_Socket;
	FString m_IPAddr = TEXT("127.0.0.1");
	int16 m_Port = PORT;
	bool m_Connecting = false;

	// Recv�۾��� ���� �����带 �����ϴ� ��ü ������
	TSharedPtr<class Networker> m_NetworkerPtr;
};
