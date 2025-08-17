// Fill out your copyright notice in the Description page of Project Settings.


#include "Networker.h"
#include "Sockets.h"
#include "Common\TcpSocketBuilder.h"
#include "SocketSubsystem.h"
#include "RecvWorker.h"

Networker::Networker(FSocket* Socket) : m_Socket(Socket)
{
}

Networker::~Networker()
{
    Disconnect();
}

void Networker::RecvThreadRun()
{
    m_RecvworkerPtr = MakeShared<RecvWorker>(m_Socket, AsShared());
}

void Networker::Disconnect()
{
    m_isgameover = false;
    m_RecvworkerPtr->Destroy();
}

