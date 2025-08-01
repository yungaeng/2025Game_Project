// CPP_ToolCollecter.cpp
#include "CPP_ToolCollecter.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

ACPP_ToolCollecter::ACPP_ToolCollecter()
{
    PrimaryActorTick.bCanEverTick = false;

    // Root component
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // Load Adventurer BP class
    static ConstructorHelpers::FClassFinder<AActor> AdventurerBP(TEXT("Blueprint'/Game/PathTo/BP_Adventurer.BP_Adventurer_C'"));
    if (AdventurerBP.Succeeded())
    {
        AdventurerBPClass = AdventurerBP.Class;
    }

    // Static mesh
    ToolMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ToolMesh"));
    ToolMesh->SetupAttachment(RootComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/MyItem/repair_point.repair_point'"));
    if (MeshAsset.Succeeded())
    {
        ToolMesh->SetStaticMesh(MeshAsset.Object);
    }

    // Collision box
    CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
    CollisionBox->SetupAttachment(ToolMesh);
    CollisionBox->SetRelativeLocation(FVector(0.f, 0.f, 72.5f));
    CollisionBox->SetRelativeScale3D(FVector(15.f, 15.f, 2.5f));
    CollisionBox->SetCollisionProfileName(TEXT("BlockAll"));
    CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ACPP_ToolCollecter::OnOverlapBegin);
    CollisionBox->OnComponentEndOverlap.AddDynamic(this, &ACPP_ToolCollecter::OnOverlapEnd);

    // Tool widget
    ToolWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("Tool Widget"));
    ToolWidgetComponent->SetupAttachment(ToolMesh);
    ToolWidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 250.f));
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(TEXT("WidgetBlueprint'/Game/MyMission/RightTool/W_CollectTools.W_CollectTools_C'"));
    if (WidgetAsset.Succeeded())
    {
        ToolWidgetComponent->SetWidgetClass(WidgetAsset.Class);
    }

    // Complete widget
    CompleteWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("CompleteWidget"));
    CompleteWidgetComponent->SetupAttachment(ToolMesh);
    CompleteWidgetComponent->SetRelativeLocation(FVector(0.f, 0.f, 250.f));
    static ConstructorHelpers::FClassFinder<UUserWidget> CompleteWidgetAsset(TEXT("WidgetBlueprint'/Game/MyEnvironment/W_Complete.W_Complete_C'"));
    if (CompleteWidgetAsset.Succeeded())
    {
        CompleteWidgetComponent->SetWidgetClass(CompleteWidgetAsset.Class);
    }

    // Initial state
    IsThisMissionComplete = false;
    IsOnCollector = false;
}

void ACPP_ToolCollecter::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (AdventurerBPClass && OtherActor->IsA(AdventurerBPClass))
    {
        if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
        {
            EnableInput(PC);
        }
        // Show appropriate widget
        if (IsThisMissionComplete)
        {
            CompleteWidgetComponent->SetVisibility(true, false);
        }
        else
        {
            ToolWidgetComponent->SetVisibility(true, false);
        }
        IsOnCollector = true;
    }
}

void ACPP_ToolCollecter::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (AdventurerBPClass && OtherActor->IsA(AdventurerBPClass))
    {
        if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
        {
            DisableInput(PC);
        }

        if (IsThisMissionComplete)
        {
            CompleteWidgetComponent->SetVisibility(false, false);
        }
        else
        {
            ToolWidgetComponent->SetVisibility(false, false);
        }
        IsOnCollector = false;
    }
}

void ACPP_ToolCollecter::UpdateCollectorCount()
{
    // Increment count and notify widget via Blueprint event
    static int32 CollectedCount = 0;
    CollectedCount++;

    if (CollectedCount >=  /* Set your max threshold */ 5)
    {
        IsThisMissionComplete = true;
    }

    BP_UpdateWidget(CollectedCount, IsThisMissionComplete);
}
