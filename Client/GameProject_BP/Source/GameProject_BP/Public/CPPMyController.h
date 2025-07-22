#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "CPPMyController.generated.h"

class UCPP_W_Indicator;

UCLASS()
class GAMEPROJECT_BP_API ACPPMyController : public APlayerController
{
    GENERATED_BODY()

public:
    ACPPMyController();

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    virtual void OnPossess(APawn* InPawn) override;

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);
    void SpawnIndicators();

public:
    //입력 관련
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputAction* MoveAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputAction* LookAction;

    //Indicator 위젯 클래스
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UCPP_W_Indicator> BP_IndicatorWidgetClass;

private:
    // 여러 타겟용 위젯들 저장


    UPROPERTY()
    TArray<UCPP_W_Indicator*> IndicatorWidgets;  

    
    UPROPERTY()
    APawn* ControlledPawn;
};