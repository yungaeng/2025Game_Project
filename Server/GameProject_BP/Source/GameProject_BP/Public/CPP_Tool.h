#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Tool.generated.h"

class USphereComponent;
class ACharacter;

UCLASS()
class GAMEPROJECT_BP_API ACPP_Tool : public AActor
{
    GENERATED_BODY()

    public:
    ACPP_Tool();

protected:
    virtual void BeginPlay() override;

    UFUNCTION()
    void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    UFUNCTION()
    void OnInteract();

private:
    UPROPERTY(VisibleAnywhere)
    USphereComponent* SphereComponent;

    UPROPERTY()
    ACharacter* CurrentOverlappingActor;

    UPROPERTY()
    UInputComponent* MyInputComponent;
};
