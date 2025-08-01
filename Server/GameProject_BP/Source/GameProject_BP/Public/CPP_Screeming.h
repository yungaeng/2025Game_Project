#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPP_Screeming.generated.h"

class UAudioCaptureComponent;
class UStaticMeshComponent;
class UWidgetComponent;
class UBoxComponent;
class UCameraComponent;
class UUserWidget;
class UAudioComponent;
class ASoundAnalyzerBase;

UCLASS()
class GAMEPROJECT_BP_API ACPP_Screeming : public AActor
{
    GENERATED_BODY()

    public:
    ACPP_Screeming();
    virtual void Tick(float DeltaSeconds) override;

protected:
   
    virtual void OnConstruction(const FTransform& Transform) override;
    virtual void PreInitializeComponents() override;
    virtual void BeginPlay() override;

   
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bIsStart = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bAnalyzerCleared = false;          // BP_SoundAnalyzer Clear

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bMissionComplete = false;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "State")
    bool bPlayerInside = false;             // Adventurer overlap?

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Screeming")
    float HowLoud = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Screeming")
    float LoudThreshold = 95.f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Screeming")
    float MaxTime = 0.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Screeming")
    float ClearTimeLimit = 3.0f;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Screeming")
    bool bFirstClear = false;

  
    UPROPERTY(EditAnywhere, Category = "Screeming|Refs")
    TSubclassOf<AActor> AdventurerClass;         

    UPROPERTY(EditAnywhere, Category = "Screeming|Refs")
    TSubclassOf<AActor> EchoGenerateClass;      

    UPROPERTY(EditDefaultsOnly, Category = "Screeming|Refs")
    TSubclassOf<UUserWidget> ProgressWidgetClass;   

    UPROPERTY(EditDefaultsOnly, Category = "Screeming|Refs")
    TSubclassOf<UUserWidget> CompleteWidgetClass;   


    UPROPERTY()
    ASoundAnalyzerBase* SoundAnalyzer = nullptr;

    UFUNCTION()
    void OnSoundAnalyzerCleared();

    void Start();
    bool IsMissionComplete() const;

    UFUNCTION()
    void OnEnvelopeValue(const UAudioComponent* AC, float Envelope);

    
    UFUNCTION()
    void OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnBoxEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    bool IsAdventurer(AActor* OtherActor) const;
    void ApplyStateOnEnter();   // EnableInput + (조건 맞으면) AudioCapture ON
    void ApplyStateOnExit();    // DisableInput + AudioCapture OFF

    
    bool bSpawnGateOpen = true;
    FTimerHandle SpawnGateTimerHandle;

    void TrySpawnEchoGenerate();
    void ReopenSpawnGate();


    void HandleThen1(float DeltaSeconds);

    
    UPROPERTY()
    UUserWidget* ScreemingWidgetInstance = nullptr;

    void UpdateWidgetHowLoud(float Value);
    void RefreshWidgets();     


    void SafeSetVis(USceneComponent* Comp, bool bVisible);

    
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    USceneComponent* Root;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UAudioCaptureComponent* AudioCapture;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UStaticMeshComponent* StaticMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UWidgetComponent* Widget;          

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UWidgetComponent* CompleteWidget;   

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
    UBoxComponent* Box;

  
    UPROPERTY()
    AActor* Imposter = nullptr;

    UPROPERTY()
    UCameraComponent* ImposterCamera = nullptr;
};
