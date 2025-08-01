#include "CPP_Screeming.h"

#include "AudioCaptureComponent.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Camera/CameraComponent.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "SoundAnalyzerBase.h"


ACPP_Screeming::ACPP_Screeming()
{
    PrimaryActorTick.bCanEverTick = true;

    Root = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
    SetRootComponent(Root);

    AudioCapture = CreateDefaultSubobject<UAudioCaptureComponent>(TEXT("AudioCapture"));
    AudioCapture->SetupAttachment(Root);

    StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
    StaticMesh->SetupAttachment(Root);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshObj(TEXT("/Game/MyItem/mic.mic"));
    if (MeshObj.Succeeded())
    {
        StaticMesh->SetStaticMesh(MeshObj.Object);
    }

    const FVector WLoc(0.f, 0.f, 120.f);
    const FRotator WRot(0.f, 0.f, 0.f);
    const FVector WScale(0.7f);
    const FIntPoint WSize(320, 160);

    Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
    Widget->SetupAttachment(Root);
    Widget->SetRelativeLocation(WLoc);
    Widget->SetRelativeRotation(WRot);
    Widget->SetRelativeScale3D(WScale);
    Widget->SetDrawSize(WSize);
    Widget->SetWidgetSpace(EWidgetSpace::World);

    CompleteWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("CompleteWidget"));
    CompleteWidget->SetupAttachment(Root);
    CompleteWidget->SetRelativeLocation(WLoc);
    CompleteWidget->SetRelativeRotation(WRot);
    CompleteWidget->SetRelativeScale3D(WScale);
    CompleteWidget->SetDrawSize(WSize);
    CompleteWidget->SetWidgetSpace(EWidgetSpace::World);

    Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));
    Box->SetupAttachment(Root);
    Box->SetRelativeLocation(FVector(0.f, 0.f, 70.f));
    Box->SetRelativeRotation(FRotator::ZeroRotator);
    Box->SetRelativeScale3D(FVector(1.75f, 1.75f, 3.0f));
    Box->SetBoxExtent(FVector(32.f));

    Box->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    Box->SetCollisionObjectType(ECC_WorldDynamic);
    Box->SetCollisionResponseToAllChannels(ECR_Ignore);
    Box->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

    Box->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Screeming::OnBoxBeginOverlap);
    Box->OnComponentEndOverlap.AddDynamic(this, &ACPP_Screeming::OnBoxEndOverlap);

    static ConstructorHelpers::FClassFinder<UUserWidget> ProgressBP(
        TEXT("/Game/MyMission/TogetherScreeming/W_ScreemingWidget.W_ScreemingWidget_C"));
    if (ProgressBP.Succeeded())
    {
        ProgressWidgetClass = ProgressBP.Class;
    }

    static ConstructorHelpers::FClassFinder<UUserWidget> CompleteBP(
        TEXT("/Game/MyEnvironment/W_Complete.W_Complete_C"));
    if (CompleteBP.Succeeded())
    {
        CompleteWidgetClass = CompleteBP.Class;
    }

    // 시작 시 렌더 못 하게 비워둔다
    Widget->SetWidgetClass(nullptr);
    CompleteWidget->SetWidgetClass(nullptr);
}


void ACPP_Screeming::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    SafeSetVis(Cast<USceneComponent>(Widget), false);
    SafeSetVis(Cast<USceneComponent>(CompleteWidget), false);
}


void ACPP_Screeming::PreInitializeComponents()
{
    Super::PreInitializeComponents();

    SafeSetVis(Cast<USceneComponent>(Widget), false);
    SafeSetVis(Cast<USceneComponent>(CompleteWidget), false);

    if (CompleteWidget)
    {
        CompleteWidget->SetOwnerNoSee(true);
        CompleteWidget->SetHiddenInGame(true);
    }
}

//BeginPlay                         
 void ACPP_Screeming::BeginPlay()
{
    Super::BeginPlay();

    // SoundAnalyzer (Tag: Screeming)
    {
        TArray<AActor*> Found;
        UGameplayStatics::GetAllActorsOfClassWithTag(
            this, ASoundAnalyzerBase::StaticClass(), FName(TEXT("Screeming")), Found);
        if (Found.Num() > 0)
        {
            SoundAnalyzer = Cast<ASoundAnalyzerBase>(Found[0]);
        }
        if (SoundAnalyzer)
        {
            SoundAnalyzer->OnSoundAnalyzerClear.AddDynamic(this, &ACPP_Screeming::OnSoundAnalyzerCleared);
            Start();
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("ACPP_Screeming: SoundAnalyzer not found (tag Screeming)"));
        }
    }

 //Imposter 
    {
        TArray<AActor*> Imposters;
        UGameplayStatics::GetAllActorsWithTag(this, FName(TEXT("Imposter")), Imposters);
        if (Imposters.Num() > 0)
        {
            Imposter = Imposters[0];
            ImposterCamera = Imposter->FindComponentByClass<UCameraComponent>();
        }
    }

   
    if (AudioCapture)
    {
        AudioCapture->OnAudioEnvelopeValueNative.AddUObject(this, &ACPP_Screeming::OnEnvelopeValue);
        if (USceneComponent* ACScene = Cast<USceneComponent>(AudioCapture))
        {
            SafeSetVis(ACScene, false);
        }
        AudioCapture->Deactivate();
    }

  
    SafeSetVis(Cast<USceneComponent>(Widget), false);
    SafeSetVis(Cast<USceneComponent>(CompleteWidget), false);
}

//Tick
void ACPP_Screeming::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    if (!bIsStart || IsMissionComplete())
        return;

    // Then0
    if (HowLoud >= LoudThreshold)
    {
        TrySpawnEchoGenerate();
    }

    // Then1
    HandleThen1(DeltaSeconds);
}

void ACPP_Screeming::Start()
{
    bIsStart = true;
    if (GEngine)
    {
        GEngine->AddOnScreenDebugMessage(-1, 2.f, FColor::Green, TEXT("Good CPP"));
    }
}

bool ACPP_Screeming::IsMissionComplete() const
{
    return bMissionComplete;
}

void ACPP_Screeming::OnSoundAnalyzerCleared()
{
    bAnalyzerCleared = true;
    RefreshWidgets();
}


void ACPP_Screeming::OnEnvelopeValue(const UAudioComponent* AC, float Envelope)
{
    float V = FMath::Clamp(Envelope, 0.f, 0.5f);
    V /= 0.5f;
    V *= 2.2f;
    V *= 100.f;

    HowLoud = IsMissionComplete() ? 100.f : V;

    if (ScreemingWidgetInstance && !IsMissionComplete())
    {
        UpdateWidgetHowLoud(HowLoud);
    }
}


bool ACPP_Screeming::IsAdventurer(AActor* OtherActor) const
{
    return AdventurerClass ? (OtherActor && OtherActor->IsA(AdventurerClass)) : true;
}

void ACPP_Screeming::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (!OtherActor || !bIsStart || !IsAdventurer(OtherActor)) return;

    bPlayerInside = true;
    ApplyStateOnEnter();   
    RefreshWidgets();
}

void ACPP_Screeming::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (!OtherActor || !bIsStart || !IsAdventurer(OtherActor)) return;

    bPlayerInside = false;
    ApplyStateOnExit();
    RefreshWidgets();
}


void ACPP_Screeming::ApplyStateOnEnter()
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
    {
        EnableInput(PC);
    }

    // Analyzer가 클리어되어 실제로 소리를 측정해야 하는 시점에만 AudioCapture 켬
    if (bAnalyzerCleared && !IsMissionComplete() && IsValid(AudioCapture))
    {
        AudioCapture->Activate(true);
        if (USceneComponent* ACScene = Cast<USceneComponent>(AudioCapture))
        {
            SafeSetVis(ACScene, true);
        }
    }
}

void ACPP_Screeming::ApplyStateOnExit()
{
    if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
    {
        DisableInput(PC);
    }

    if (!IsMissionComplete() && IsValid(AudioCapture))
    {
        AudioCapture->Deactivate();
        if (USceneComponent* ACScene = Cast<USceneComponent>(AudioCapture))
        {
            SafeSetVis(ACScene, false);
        }
    }
}

void ACPP_Screeming::RefreshWidgets()
{
    // 기본 OFF
    SafeSetVis(Cast<USceneComponent>(Widget), false);
    SafeSetVis(Cast<USceneComponent>(CompleteWidget), false);

    // 진행 위젯: Analyzer Clear + 미션 미완료 + Adventurer 겹침
    if (!bMissionComplete && bAnalyzerCleared && bPlayerInside)
    {
        if (Widget && !Widget->GetWidgetClass() && ProgressWidgetClass)
        {
            Widget->SetWidgetClass(ProgressWidgetClass);
            ScreemingWidgetInstance = Widget->GetUserWidgetObject();
        }
        SafeSetVis(Cast<USceneComponent>(Widget), true);
    }

    // 완료 위젯: 미션 완료 + Adventurer 겹침
    if (bMissionComplete && bPlayerInside)
    {
        if (CompleteWidget && !CompleteWidget->GetWidgetClass() && CompleteWidgetClass)
        {
            CompleteWidget->SetWidgetClass(CompleteWidgetClass);
            CompleteWidget->SetOwnerNoSee(false);
        }
        SafeSetVis(Cast<USceneComponent>(CompleteWidget), true);
    }
}

void ACPP_Screeming::UpdateWidgetHowLoud(float Value)
{
    if (!ScreemingWidgetInstance) return;

    static FName FuncName(TEXT("UpdateHowLoud"));
    if (UFunction* Func = ScreemingWidgetInstance->FindFunction(FuncName))
    {
        struct FUpdateParam { float HowLoudInWidget; } Args;
        Args.HowLoudInWidget = Value;
        ScreemingWidgetInstance->ProcessEvent(Func, &Args);
    }
}


void ACPP_Screeming::TrySpawnEchoGenerate()
{
    if (!bSpawnGateOpen || !EchoGenerateClass) return;

    bSpawnGateOpen = false;

    const FVector Loc = GetActorLocation();
    const FRotator Rot = FRotator::ZeroRotator;

    FActorSpawnParameters Params;
    Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    Params.Instigator = GetInstigator();

    AActor* Spawned = GetWorld()->SpawnActor<AActor>(EchoGenerateClass, Loc, Rot, Params);
    if (Spawned)
    {
        static FName InitName(TEXT("InitFromCPP"));
        if (UFunction* F = Spawned->FindFunction(InitName))
        {
            struct FInitParams
            {
                float SoundRange;
                float StartRange;
                UObject* ImposterCamera;
                FLinearColor DecalColor;
            } Args;

            Args.SoundRange = 500.f;
            Args.StartRange = 0.f;
            Args.ImposterCamera = ImposterCamera;
            Args.DecalColor = FLinearColor::White;

            Spawned->ProcessEvent(F, &Args);
        }
    }

    GetWorldTimerManager().SetTimer(
        SpawnGateTimerHandle, this, &ACPP_Screeming::ReopenSpawnGate, 0.5f, false);
}

void ACPP_Screeming::ReopenSpawnGate()
{
    bSpawnGateOpen = true;
}

void ACPP_Screeming::HandleThen1(float DeltaSeconds)
{
    MaxTime += DeltaSeconds;

    if (MaxTime >= ClearTimeLimit)
    {
        bMissionComplete = true;
        RefreshWidgets();

        if (IsValid(AudioCapture))
        {
            AudioCapture->Deactivate();
            if (USceneComponent* ACScene = Cast<USceneComponent>(AudioCapture))
            {
                SafeSetVis(ACScene, false);
            }
        }

        if (!bFirstClear)
        {
            bFirstClear = true;
        }

        MaxTime = 0.f;
    }
}


void ACPP_Screeming::SafeSetVis(USceneComponent* Comp, bool bVisible)
{
    if (IsValid(Comp))
    {
        Comp->SetVisibility(bVisible, true);
        Comp->SetHiddenInGame(!bVisible, true);
    }
}
