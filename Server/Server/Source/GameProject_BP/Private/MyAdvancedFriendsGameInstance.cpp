// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAdvancedFriendsGameInstance.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Networker.h"

bool UMyAdvancedFriendsGameInstance::ConnectToServer(FString AddrIP)
{
    //소켓 만들기
    m_Socket = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateSocket(TEXT("Srream"), TEXT("Client Socket"));

    // 소켓에 서버 ip 할당
    FIPv4Address ip;
    if (AddrIP.IsEmpty())
        FIPv4Address::Parse(m_IPAddr, ip);
    else
        FIPv4Address::Parse(AddrIP, ip);

    // 포트와 ip를 주소포인터에 할당
    TSharedRef<FInternetAddr> internetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
    internetAddr->SetIp(ip.Value);
    internetAddr->SetPort(m_Port);

    UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connecting to Server..."), true, true, FColor::Red, 5.f);

    // 소켓을 해당 주소로 연결시도 후 결과 반환
    m_Connecting = m_Socket->Connect(*internetAddr);

    if (m_Connecting)
    {
        UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Success"), true, true, FColor::Blue, 5.f);
        m_NetworkerPtr = MakeShared<class Networker>(m_Socket);
        m_NetworkerPtr->RecvThreadRun();
        return true;
    }
    else
    {
        UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Connection Failed"), true, true, FColor::Red, 5.f);
        return false;
    }
}
void UMyAdvancedFriendsGameInstance::DisconnectToServer()
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

void UMyAdvancedFriendsGameInstance::SendSignin(FString input)
{
    FString name = input;
    int32 bytesSent;
    cs_packet_login p{};
    p.size = sizeof(p);
    p.type = C2S_SIGNIN;
    strcpy_s(p.name, sizeof(p.name), TCHAR_TO_ANSI(*name));
    m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);
}
void UMyAdvancedFriendsGameInstance::SendLogin(FString input)
{
    FString name = input;
    int32 bytesSent;
    cs_packet_login p{};
    p.size = sizeof(p);
    p.type = C2S_LOGIN;
    strcpy_s(p.name, sizeof(p.name), TCHAR_TO_ANSI(*name));
    m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);
}
void UMyAdvancedFriendsGameInstance::SendRoom(uint8 request)
{
    int32 bytesSent;
    cs_packet_room p{};
    p.size = sizeof(p);
    p.type = C2S_ROOM;
    p.requst = request;
    m_Socket->Send((uint8*)&p, sizeof(p), bytesSent);
}
void UMyAdvancedFriendsGameInstance::SendAttack()
{
    int32 bytesSent;
    cs_packet_attack p{};
    p.size = sizeof(p);
    p.type = C2S_ATTACK;
    m_Socket->Send((uint8*)&p, p.size, bytesSent);
}

bool UMyAdvancedFriendsGameInstance::GetLoginOk()
{
    if (m_NetworkerPtr.IsValid())
        return m_NetworkerPtr->m_islogin;
    return false;
}

bool UMyAdvancedFriendsGameInstance::GetCharacter()
{
    if (m_NetworkerPtr.IsValid())
        return m_NetworkerPtr->m_isimposter;
    return false;
}

bool UMyAdvancedFriendsGameInstance::GetGameOver()
{
    if (m_NetworkerPtr.IsValid())
        return m_NetworkerPtr->m_isgameover;
    return false;
}

bool UMyAdvancedFriendsGameInstance::GetGameOverState()
{
    if (m_NetworkerPtr.IsValid()) {

        if (m_NetworkerPtr->m_result == 0)
            return true;
        else
            return false;
    }
    else
        return false;
}