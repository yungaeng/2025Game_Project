// CPP_Computer.cpp
#include "CPP_Computer.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "SoundAnalyzerBase.h"

ACPP_Computer::ACPP_Computer()
{
    PrimaryActorTick.bCanEverTick = false;

    MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    RootComponent = MeshComponent;
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(
        TEXT("StaticMesh'/Game/MyItem/screen2.screen2'"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
    }

    ComputerWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("ComputerWidget"));
    ComputerWidget->SetupAttachment(MeshComponent);
    ComputerWidget->SetRelativeLocation(FVector(15.f, 5.f, 25.f));
    ComputerWidget->SetRelativeRotation(FRotator(0.f, 0.f, 90.f));
    ComputerWidget->SetRelativeScale3D(FVector(0.6f, 0.6f, 0.6f));
    static ConstructorHelpers::FClassFinder<UUserWidget> WidgetAsset(
        TEXT("WidgetBlueprint'/Game/MyMission/MatchingPassword/W_Computer.W_Computer'"));
    if (WidgetAsset.Succeeded())
    {
        ComputerWidget->SetWidgetClass(WidgetAsset.Class);
    }
}

// Called when the game starts or actor is spawned
void ACPP_Computer::BeginPlay()
{
    Super::BeginPlay();

    CreateRandomNumbers();

    TArray<AActor*> Found;
    UGameplayStatics::GetAllActorsWithTag(GetWorld(), SoundAnalyzerTag, Found);
    if (Found.Num() > 0)
    {
        if (ASoundAnalyzerBase* Analyzer = Cast<ASoundAnalyzerBase>(Found[0]))
        {
            Analyzer->OnSoundAnalyzerClear.AddDynamic(this, &ACPP_Computer::CreateRandomNumbers);
        }
    }
}

void ACPP_Computer::CreateRandomNumbers()
{
    ComputerWidget->SetVisibility(false);

    RandomDigits.Empty();
    for (int32 i = 0; i < 3; ++i)
    {
        RandomDigits.Add(FMath::RandRange(0, 9));
    }

    if (UUserWidget* UW = ComputerWidget->GetUserWidgetObject())
    {
        if (UFunction* Func = UW->FindFunction(TEXT("SetNumbers")))
        {
            struct FSetNumbersParams { TArray<int32> Numbers; } Params;
            Params.Numbers = RandomDigits;
            UW->ProcessEvent(Func, &Params);
        }
    }

    ComputerWidget->SetVisibility(true);

    if (AnswerActorClass)
    {
        TArray<AActor*> Answers;
        UGameplayStatics::GetAllActorsOfClass(GetWorld(), AnswerActorClass, Answers);
        if (Answers.Num() > 0)
        {
            AActor* Ans = Answers[0];
            if (UFunction* Func = Ans->FindFunction(TEXT("Start")))
            {
                Ans->ProcessEvent(Func, nullptr);
            }
        }
    }
}

void ACPP_Computer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
