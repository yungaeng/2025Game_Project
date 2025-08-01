#include "CPP_Tool.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

ACPP_Tool::ACPP_Tool()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create Sphere Component
    SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
    RootComponent = SphereComponent;
    SphereComponent->InitSphereRadius(100.f);
    SphereComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
    SphereComponent->SetGenerateOverlapEvents(true);

    // Optional Mesh Component
    UStaticMeshComponent* MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    MeshComponent->SetupAttachment(SphereComponent);
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/MyItem/part.part"));
    if (MeshAsset.Succeeded())
    {
        MeshComponent->SetStaticMesh(MeshAsset.Object);
        MeshComponent->SetWorldScale3D(FVector(2.0f));
    }

    CurrentOverlappingActor = nullptr;
    MyInputComponent = nullptr;
}

void ACPP_Tool::BeginPlay()
{
    Super::BeginPlay();

    SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Tool::OnSphereBeginOverlap);
    SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ACPP_Tool::OnSphereEndOverlap);
}

void ACPP_Tool::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (ACharacter* Adventurer = Cast<ACharacter>(OtherActor))
    {
        CurrentOverlappingActor = Adventurer;

        if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
        {
            EnableInput(PC);

            if (!MyInputComponent)
            {
                MyInputComponent = NewObject<UInputComponent>(this, TEXT("ToolInputComponent"));
                MyInputComponent->RegisterComponent();
                MyInputComponent->bBlockInput = false;
                MyInputComponent->Priority = 10;
                MyInputComponent->BindAction("Interact", IE_Pressed, this, &ACPP_Tool::OnInteract);
                this->AddInstanceComponent(MyInputComponent);
                this->InputComponent = MyInputComponent; // 엔진에 연결
            }
        }
    }
}

void ACPP_Tool::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (ACharacter* Adventurer = Cast<ACharacter>(OtherActor))
    {
        CurrentOverlappingActor = nullptr;

        if (APlayerController* PC = UGameplayStatics::GetPlayerController(this, 0))
        {
            DisableInput(PC);
        }
    }
}

void ACPP_Tool::OnInteract()
{
    if (!CurrentOverlappingActor) return;

    // Call "ToolCollect" function on overlapping BP_Adventurer
    FName FuncName = FName("ToolCollect");
    if (CurrentOverlappingActor->FindFunction(FuncName))
    {
        CurrentOverlappingActor->CallFunctionByNameWithArguments(*FuncName.ToString(), *GLog, nullptr, true);
    }
}
