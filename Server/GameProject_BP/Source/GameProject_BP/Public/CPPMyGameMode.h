#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPPMyGameMode.generated.h"

UCLASS()
class GAMEPROJECT_BP_API ACPPMyGameMode : public AGameModeBase
{
    GENERATED_BODY()

    public:
    ACPPMyGameMode();

protected:
    virtual void BeginPlay() override;

public:
    // 어드벤처러 스폰 함수
    void RespawnAdventurer();
};
