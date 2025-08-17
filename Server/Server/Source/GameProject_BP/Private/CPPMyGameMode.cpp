#include "CPPMyGameMode.h"
#include "CPPMyController.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ACPPMyGameMode::ACPPMyGameMode()
{
    PlayerControllerClass = ACPPMyController::StaticClass();

    static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/BP_MyController.BP_MyController_C"));
    if (PlayerControllerBPClass.Succeeded())
    {
        PlayerControllerClass = PlayerControllerBPClass.Class;
    }
    static ConstructorHelpers::FClassFinder<APawn> AdventurerPawnClass(TEXT("/Game/MyAdventurer/BP_Adventurer.BP_Adventurer_C"));
    if (AdventurerPawnClass.Succeeded())
    {
        DefaultPawnClass = AdventurerPawnClass.Class;
    }
}

void ACPPMyGameMode::BeginPlay()
{
    Super::BeginPlay();



    // 게임 시작 시 어드벤처러 스폰
   // RespawnAdventurer();
}

/*
void ACPPMyGameMode::RespawnAdventurer()
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0);
    if (PC && DefaultPawnClass)
    {
        FVector SpawnLocation = FVector(0.f, 0.f, 200.f); // 적절한 스폰 위치
        FRotator SpawnRotation = FRotator::ZeroRotator;

        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = PC;
        SpawnParams.Instigator = PC->GetPawn();

        APawn* NewPawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, SpawnLocation, SpawnRotation, SpawnParams);
        if (NewPawn)
        {
            PC->Possess(NewPawn);
        }
    }
}

*/