// CPP_Computer.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "CPP_Computer.generated.h"

class UUserWidget;
class ASoundAnalyzerBase;

UCLASS()
class GAMEPROJECT_BP_API ACPP_Computer : public AActor
{
    GENERATED_BODY()

    public:
    
    ACPP_Computer();

protected:

    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
    UStaticMeshComponent* MeshComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
    UWidgetComponent* ComputerWidget;

    UPROPERTY()
    TArray<int32> RandomDigits;

    UPROPERTY(EditAnywhere, Category = "Config")
    TSubclassOf<AActor> AnswerActorClass;

    UPROPERTY(EditDefaultsOnly, Category = "Config")
    FName SoundAnalyzerTag = TEXT("CorrectAnswer");

    UFUNCTION()
    void CreateRandomNumbers();
};
