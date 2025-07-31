// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GAMEPROJECT_BP_API RecvWorker : public FRunnable
{
public:
	RecvWorker(class FSocket* Socket, TSharedPtr<class Networker> networker);
	~RecvWorker();

	virtual bool Init() override;
	virtual uint32 Run() override;
	virtual void Exit() override;

	void Destroy();

private:
	void Recv();

protected:
	FSocket* m_Socket;
	FRunnableThread* m_RecvThread = nullptr;
	TWeakPtr<class Networker> m_NetworkerPtr = nullptr;
	bool m_Running = true;
};
