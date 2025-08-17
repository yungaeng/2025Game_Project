// CPP_Portal.cpp

#include "CPP_Portal.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h" // 캐릭터 사용

ACPP_Portal::ACPP_Portal()
{
    PrimaryActorTick.bCanEverTick = true;

    // Root
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    // Static Mesh
    PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PortalMesh"));
    PortalMesh->SetupAttachment(RootComponent);
    PortalMesh->SetMobility(EComponentMobility::Movable);
    PortalMesh->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
    PortalMesh->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
    PortalMesh->SetRelativeScale3D(FVector(2.5f, 2.5f, 2.5f));
    static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Engine/BasicShapes/Plane.Plane'"));
    if (MeshAsset.Succeeded())
    {
        PortalMesh->SetStaticMesh(MeshAsset.Object);
    }

    // Material
    static ConstructorHelpers::FObjectFinder<UMaterialInterface> MaterialAsset(TEXT("/Script/Engine.Material'/Game/MyMission/Portal/M_Portal.M_Portal'"));
    if (MaterialAsset.Succeeded())
    {
        PortalMesh->SetMaterial(0, MaterialAsset.Object);
    }

    // Collision Box
    BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
    BoxCollision->SetupAttachment(RootComponent);
    BoxCollision->SetBoxExtent(FVector(32.0f, 32.0f, 32.0f));
    BoxCollision->SetRelativeLocation(FVector(0.0f, 0.0f, -18.0f));
    BoxCollision->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));
    BoxCollision->SetRelativeScale3D(FVector(1.0f, 0.25f, 1.0f));
    BoxCollision->SetCollisionProfileName(TEXT("Trigger"));
    BoxCollision->SetGenerateOverlapEvents(true);

    // Delegate binding
    BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACPP_Portal::OnOverlapBegin);
    BoxCollision->OnComponentEndOverlap.AddDynamic(this, &ACPP_Portal::OnOverlapEnd);
}

void ACPP_Portal::BeginPlay()
{
    Super::BeginPlay();
}

void ACPP_Portal::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void ACPP_Portal::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
    bool bFromSweep, const FHitResult& SweepResult)
{
    if (ACharacter* Adventurer = Cast<ACharacter>(OtherActor))
    {
        FTransform CurrentTransform = GetActorTransform();
        FVector NewLocation = TP_Pos.GetLocation();
        FRotator NewRotation = TP_Pos.GetRotation().Rotator();
        Adventurer->SetActorLocationAndRotation(NewLocation, NewRotation, false, nullptr, ETeleportType::TeleportPhysics);
    }
}

void ACPP_Portal::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    
}
