#include "CPP_W_Indicator.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Math/UnrealMathUtility.h"

void UCPP_W_Indicator::SetTarget(AActor* NewTarget)
{
    TargetActor = NewTarget;
}

void UCPP_W_Indicator::NativeConstruct()
{
    Super::NativeConstruct();

    // 초기 Viewport Size 저장
    if (GEngine && GEngine->GameViewport)
    {
        GEngine->GameViewport->GetViewportSize(SavedViewportSize);
    }
}

void UCPP_W_Indicator::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    CheckViewportSizeChanged();
    if (!TargetActor || !IndicatorIcon) return;

    FVector WorldLocation = TargetActor->GetActorLocation();
    FVector2D ScreenLocation;
    bool bIsOnScreen = false;

    if (CalculateScreenPosition(WorldLocation, ScreenLocation, bIsOnScreen))
    {
        if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Slot))
        {
            CanvasSlot->SetPosition(ScreenLocation);
        }

        
        IndicatorIcon->SetVisibility(ESlateVisibility::Visible);

        // 회전 방향 설정
        FVector2D ViewportCenter = SavedViewportSize * 0.5f;
        FVector2D ToTarget = ScreenLocation - ViewportCenter;
        float Angle = FMath::Atan2(ToTarget.Y, ToTarget.X) * 180.f / PI;
        IndicatorIcon->SetRenderTransformAngle(Angle);
    }
    else
    {
        // 화면 밖일 경우 숨기기
        IndicatorIcon->SetVisibility(ESlateVisibility::Hidden);
    }
}


void UCPP_W_Indicator::CheckViewportSizeChanged()
{
    if (!GEngine || !GEngine->GameViewport)
        return;

    FVector2D CurrentSize;
    GEngine->GameViewport->GetViewportSize(CurrentSize);

    if (!CurrentSize.Equals(SavedViewportSize, 1.0f)) // 약간의 오차 허용
    {
        SavedViewportSize = CurrentSize;
        UE_LOG(LogTemp, Warning, TEXT("Viewport size changed to: %s"), *CurrentSize.ToString());
    }
}

bool UCPP_W_Indicator::CalculateScreenPosition(FVector WorldLocation, FVector2D& OutScreenLocation, bool& bIsOnScreen) const
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC) return false;

    FVector2D ViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
    float ViewportScale = UWidgetLayoutLibrary::GetViewportScale(this);

    // 월드 → 화면 좌표로 투영
    bool bProjected = PC->ProjectWorldLocationToScreen(WorldLocation, OutScreenLocation, true);
    if (!bProjected) return false;

    // 스케일 적용
    OutScreenLocation /= ViewportScale;
    // Clamp 범위 설정
    const float Margin = 30.0f;
    const float ClampMinX = Margin;
    const float ClampMinY = Margin;
    const float ClampMaxX = ViewportSize.X - Margin;
    const float ClampMaxY = ViewportSize.Y - Margin;

    // 시야 내 판정
    bool bInRangeX = OutScreenLocation.X >= 0.0f && OutScreenLocation.X <= ViewportSize.X;
    bool bInRangeY = OutScreenLocation.Y >= 0.0f && OutScreenLocation.Y <= ViewportSize.Y;
    bIsOnScreen = bInRangeX && bInRangeY;

    // Clamp
    OutScreenLocation.X = FMath::Clamp(OutScreenLocation.X, ClampMinX, ClampMaxX);
    OutScreenLocation.Y = FMath::Clamp(OutScreenLocation.Y, ClampMinY, ClampMaxY);

    return true;
}
