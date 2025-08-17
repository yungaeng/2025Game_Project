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

    UFUNCTION(BlueprintCallable, Category = "Indicator")
    bool CalculateScreenPosition(FVector WorldLocation, FVector2D& OutScreenLocation, bool& bIsOnScreen);


protected:
    virtual void NativeConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

    UPROPERTY(meta = (BindWidget))
    class UImage* IndicatorIcon;

    UPROPERTY()
    AActor* TargetActor;
private:
    FVector2D SavedViewportSize;
    void CheckViewportSizeChanged();
    bool bDidSetVisibleOnce = false;
    bool bDidSetPivot = false;
    FVector2D GetEdgeClampedPosition(const FVector2D& ScreenPosition, const FVector2D& ViewportSize) const;
};