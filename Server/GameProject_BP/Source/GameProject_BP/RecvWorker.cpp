// Fill out your copyright notice in the Description page of Project Settings.


#include "RecvWorker.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "protocol.h"
#include "Networker.h"
#include "RecvPacketHandler.h"

RecvWorker::RecvWorker(FSocket* Socket, TSharedPtr<class Networker> networker) : m_Socket(Socket), m_NetworkerPtr(networker)
{
	// 패킷 핸들러 등록
	// SC_LOGIN_OK
	RecvPacketHandler::Get().RegisterHandler(S2C_LOGIN_OK, [this](const TArray<uint8>& Data) {
		const sc_packet_login_ok* p = reinterpret_cast<const sc_packet_login_ok*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("S2C_LOGIN_OK received"));
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_LOGIN_FAIL, [this](const TArray<uint8>& Data) {
		const sc_packet_login_fail* p = reinterpret_cast<const sc_packet_login_fail*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("S2C_LOGIN_FAIL received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
				// TODO : 로그인 실패 시, 다시 입력받는 부분 추가
				// 0 : 알수 없는 이유
				// 1 : 다른 클라이언트에서 사용중
				// 2 : 부적절한 ID (특수문자, 20자 이상)
				// 3 : 서버에 동접이 너무 많음
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_AVATAR_INFO, [this](const TArray<uint8>& Data) {
		const sc_packet_avatar_info* p = reinterpret_cast<const sc_packet_avatar_info*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("S2C_AVATAR_INFO received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
			long long id = p->id;
			player pl;
			pl.id = id;
			pl.hp = p->hp;
			Net->players.emplace(id, pl);
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_ENTER, [this](const TArray<uint8>& Data) {
		const sc_packet_enter* p = reinterpret_cast<const sc_packet_enter*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("S2C_ENTER received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin())
		{
			long long id = p->id;
			player pl;
			pl.id = id;
			memcpy_s(pl.name, sizeof(pl.name), p->name, sizeof(p->name));
			pl.x = p->x;
			pl.y = p->y;
			pl.z = p->z;
			pl.type = p->o_type;
			Net->players.emplace(id, pl);
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_MOVE, [this](const TArray<uint8>& Data) {
		const sc_packet_move* p = reinterpret_cast<const sc_packet_move*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("S2C_MOVE received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
			long long id = p->id;
			auto it = Net->players.find(id);
			if (it != Net->players.end())
			{
				it->second.x = p->x;
				it->second.y = p->y;
				it->second.z = p->z;
			}
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_CHAT, [this](const TArray<uint8>& Data) {
		const sc_packet_chat* p = reinterpret_cast<const sc_packet_chat*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("S2C_CHAT received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
			long long id = p->id;
			auto it = Net->players.find(id);
			//if (it != Net->players.end())
				//memcpy_s(it->second.chat, sizeof(it->second.chat), p->message, sizeof(p->message));
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_STAT_CHANGE, [this](const TArray<uint8>& Data) {
		const sc_packet_stat_change* p = reinterpret_cast<const sc_packet_stat_change*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("S2C_STAT_CHANGE received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
			long long id = p->id;
			auto it = Net->players.find(id);
			if (it != Net->players.end())
			{
				it->second.hp = p->hp;
			}
		}
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_LEAVE, [this](const TArray<uint8>& Data) {
		const sc_packet_leave* p = reinterpret_cast<const sc_packet_leave*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("S2C_LEAVE received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) 
			Net->players.erase(p->id);
		});
	RecvPacketHandler::Get().RegisterHandler(S2C_GAMEOVER, [this](const TArray<uint8>& Data) {
		const sc_packet_gameover* p = reinterpret_cast<const sc_packet_gameover*>(Data.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("S2C_MOVE received"));
		if (TSharedPtr<Networker> Net = m_NetworkerPtr.Pin()) {
			Net->m_result = p->result;
			Net->m_gameover = true;
		}
		});
	m_RecvThread = FRunnableThread::Create(this, (TEXT("RecvWorkerThread")));
}

RecvWorker::~RecvWorker()
{
}

bool RecvWorker::Init()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("RecvThread is Init!!")));
	return true;
}

uint32 RecvWorker::Run()
{
	while (m_Running)
		Recv();
	return 0;
}

void RecvWorker::Exit()
{
}

void RecvWorker::Destroy()
{
	m_Running = false;
}

void RecvWorker::Recv()
{
	uint32 bytesPending;
	if (m_Socket->HasPendingData(bytesPending))
	{
		int32 readBytes;
		TArray<uint8> data;
		data.SetNumUninitialized(BUF_SIZE);
		m_Socket->Recv(data.GetData(), data.Num(), readBytes);

		if (readBytes > 0)
		{
			uint8 packetSize = data[0];
			char packetType = data[1];

			RecvPacketHandler::Get().HandlePacket(packetType, data);
		}
	}
}

