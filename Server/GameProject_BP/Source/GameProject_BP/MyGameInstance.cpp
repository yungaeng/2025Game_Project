// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Networker.h"

bool UMyGameInstance::ConnectToServer(FString AddrIP)
{
	//���� �����
	m_Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Srream"), TEXT("Client Socket"));

	// ���Ͽ� ���� ip �Ҵ�
	FIPv4Address ip;
	if(AddrIP.IsEmpty())
		FIPv4Address::Parse(m_IPAddr, ip);	
	else
		FIPv4Address::Parse(AddrIP, ip);

	// ��Ʈ�� ip�� �ּ������Ϳ� �Ҵ�
	TSharedRef<FInternetAddr> internetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	internetAddr->SetIp(ip.Value);
	internetAddr->SetPort(m_Port);

	UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connecting to Server..."), true, true, FColor::Red, 5.f);

	// ������ �ش� �ּҷ� ����õ� �� ��� ��ȯ
	m_Connecting = m_Socket->Connect(*internetAddr);

	if (m_Connecting)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Success"), true, true, FColor::Blue, 5.f);
		m_NetworkerPtr = MakeShared<class Networker>(m_Socket);
		m_NetworkerPtr->RecvThreadRun();
		SendLogin();
		return true;
	}
	else
	{
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Failed"), true, true, FColor::Red, 5.f);
		return false;
	}
}
void UMyGameInstance::DisconnectToServer()
{
	// Send Logout Packet
	cs_packet_login p;
	int32 bytesSent;
	p.size = sizeof(p);
	p.type = C2S_LOGOUT;
	m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);

	if (m_Socket)
	{
		m_NetworkerPtr->Disconnect();
		m_NetworkerPtr = nullptr;

		ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get();
		SocketSubsystem->DestroySocket(m_Socket);
		m_Socket = nullptr;
	}
}

void UMyGameInstance::SendLogin()
{
	FString name = "UnrealPlayer";
	int32 bytesSent;
	cs_packet_login p{};
	p.size = sizeof(p);
	p.type = C2S_LOGIN;
	strcpy_s(p.name, sizeof(p.name), TCHAR_TO_ANSI(*name));
	m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);
}

void UMyGameInstance::SendRoom(uint8 request)
{
	int32 bytesSent;
	cs_packet_room p{};
	p.size = sizeof(p);
	p.type = C2S_ROOM;
	p.requst = request;
	m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);
}
void UMyGameInstance::SendAttack()
{
	int32 bytesSent;
	cs_packet_attack p{};
	p.size = sizeof(p);
	p.type = C2S_ATTACK;
	m_Socket->Send((uint8*)&p, p.size, bytesSent);
}


bool UMyGameInstance::GetGameOver()
{
	return m_NetworkerPtr->m_gameover;
}



