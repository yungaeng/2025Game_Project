// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Templates/Function.h"

using PacketHandlerFunc = TFunction<void(const TArray<uint8>&)>;

class RecvPacketHandler
{
public:
    static RecvPacketHandler& Get()
    {
        static RecvPacketHandler Instance;
        return Instance;
    }

    void RegisterHandler(char PacketType, PacketHandlerFunc Handler)
    {
        Handlers.Add(PacketType, Handler);
    }

    void HandlePacket(char PacketType, const TArray<uint8>& Data)
    {
        if (Handlers.Contains(PacketType))
        {
            Handlers[PacketType](Data);
        }
        else
        {
            GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Unknown PacketType Received"));
        }
    }

private:
    RecvPacketHandler() = default;
    ~RecvPacketHandler() = default;

    RecvPacketHandler(const RecvPacketHandler&) = delete;
    RecvPacketHandler& operator=(const RecvPacketHandler&) = delete;

    RecvPacketHandler(RecvPacketHandler&&) = delete;
    RecvPacketHandler& operator=(RecvPacketHandler&&) = delete;

    TMap<char, PacketHandlerFunc> Handlers;
};

