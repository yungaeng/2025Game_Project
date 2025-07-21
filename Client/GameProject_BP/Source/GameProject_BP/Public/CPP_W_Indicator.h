#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CPP_W_Indicator.generated.h"

UCLASS()
class GAMEPROJECT_BP_API UCPP_W_Indicator : public UUserWidget
{
    GENERATED_BODY()

    public:
    UFUNCTION(BlueprintCallable, Category = "Indicator")
    void SetTarget(AActor* NewTarget);

protected:
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    UPROPERTY(meta = (BindWidget))
    class UImage* IndicatorIcon;

    UPROPERTY()
    AActor* TargetActor;
};
