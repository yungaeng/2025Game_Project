// CPP_ToolCollecter.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "CPP_ToolCollecter.generated.h"

UCLASS()
class GAMEPROJECT_BP_API ACPP_ToolCollecter : public AActor
{
    GENERATED_BODY()

    public:
    ACPP_ToolCollecter();

    /** Increment and update the widget's collected tools count */
    UFUNCTION(BlueprintCallable, Category = "Collector")
    void UpdateCollectorCount();

    /** Blueprint event to update widget visuals */
    UFUNCTION(BlueprintImplementableEvent, Category = "Collector")
    void BP_UpdateWidget(int32 CollectedCount, bool bMissionComplete);

protected:
    // Components

   
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* ToolMesh;

    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* CollisionBox;

    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UWidgetComponent* ToolWidgetComponent;

  
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UWidgetComponent* CompleteWidgetComponent;

    UPROPERTY(EditDefaultsOnly, Category = "Collector")
    TSubclassOf<AActor> AdventurerBPClass;

   

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collector")
    bool IsThisMissionComplete;

    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collector")
    bool IsOnCollector;



    UFUNCTION()
    void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
