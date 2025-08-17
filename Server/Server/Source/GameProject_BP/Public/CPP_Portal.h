// CPP_Portal.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CPP_Portal.generated.h"

UCLASS()
class GAMEPROJECT_BP_API ACPP_Portal : public AActor
{
    GENERATED_BODY()

    public:
    ACPP_Portal();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    // Components
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* PortalMesh;

    UPROPERTY(VisibleAnywhere)
    UBoxComponent* BoxCollision;

    // Editable Transform for teleport target
    UPROPERTY(EditInstanceOnly, Category = "Teleport", meta = (MakeEditWidget = true))
    FTransform TP_Pos;

    // Overlap Functions
    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
