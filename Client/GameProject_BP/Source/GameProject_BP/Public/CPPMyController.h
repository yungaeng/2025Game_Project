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

    void Move(const FInputActionValue& Value);
    void Look(const FInputActionValue& Value);

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputMappingContext* DefaultMappingContext;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputAction* MoveAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
    class UInputAction* LookAction;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
    TSubclassOf<UCPP_W_Indicator> BP_IndicatorWidgetClass;

private:
 
    UPROPERTY()
    UCPP_W_Indicator* IndicatorWidget;
};