#include "CPP_W_Indicator.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"
#include "Engine/GameViewportClient.h"
#include "Math/UnrealMathUtility.h"


DEFINE_LOG_CATEGORY_STATIC(LogIndicator, Log, All);

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

    if (!TargetActor || !IndicatorIcon) { return; }

    // ===== Viewport & UI Scale =====
    const FVector2D RawViewportSize = UWidgetLayoutLibrary::GetViewportSize(this);
    const float     UIScale = UWidgetLayoutLibrary::GetViewportScale(this); // DPI
    const FVector2D ViewportSize = RawViewportSize / UIScale;                    // UMG 좌표계와 맞춤
    SavedViewportSize = ViewportSize;

    // ===== 거리 체크 =====
    APawn* OwnerPawn = GetOwningPlayerPawn();
    if (!OwnerPawn) { return; }

    const float MaxVisibleDistance = 1000.f;
    const float Distance = FVector::Dist(TargetActor->GetActorLocation(), OwnerPawn->GetActorLocation());
    if (Distance > MaxVisibleDistance)
    {
        IndicatorIcon->SetVisibility(ESlateVisibility::Hidden);
        return;
    }

    // ===== 스크린 좌표 계산 =====
    FVector2D ScreenPos;
    bool bOnScreen = false;
    const bool bProjected = CalculateScreenPosition(TargetActor->GetActorLocation(), ScreenPos, bOnScreen);

    // 디버그
    UE_LOG(LogIndicator, Warning, TEXT("P:%d On:%d Scr:%s VP:%s Scale:%f"),
        bProjected, bOnScreen, *ScreenPos.ToString(), *ViewportSize.ToString(), UIScale);

    if (!bProjected)
    {
        IndicatorIcon->SetVisibility(ESlateVisibility::Hidden);
        return;
    }

    // 온스크린이면 숨김 (오프스크린 전용)
    if (bOnScreen)
    {
        IndicatorIcon->SetVisibility(ESlateVisibility::Hidden);
        return;
    }

    // ===== 오프스크린 → 가장자리로 이동 =====
    const FVector2D EdgePos = GetEdgeClampedPosition(ScreenPos, ViewportSize);

    if (UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(IndicatorIcon->Slot))
    {
        // 한 번만 중앙 피벗 세팅
        if (!bDidSetPivot)
        {
            CanvasSlot->SetAlignment(FVector2D(0.5f, 0.5f));
            bDidSetPivot = true;
        }
        CanvasSlot->SetPosition(EdgePos);
    }

    // ===== 회전 =====
    const FVector2D Center = ViewportSize * 0.5f;
    const FVector2D Dir = (EdgePos - Center).GetSafeNormal();
    const float AngleDeg = FMath::Atan2(Dir.Y, Dir.X) * 180.f / PI;
    IndicatorIcon->SetRenderTransformAngle(AngleDeg);

    // ===== 스케일 =====
    const float MinDistance = 50.f;
    const float T = FMath::Clamp((Distance - MinDistance) / (MaxVisibleDistance - MinDistance), 0.f, 1.f);
    const float Scale = FMath::Lerp(1.f, 0.2f, T);
    IndicatorIcon->SetRenderScale(FVector2D(Scale, Scale));

    IndicatorIcon->SetVisibility(ESlateVisibility::Visible);
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

bool UCPP_W_Indicator::CalculateScreenPosition(FVector WorldLocation,
    FVector2D& OutScreenLocation,
    bool& bIsOnScreen)
{
    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC) return false;

    // 픽셀 좌표로 투영
    bool bProjected = PC->ProjectWorldLocationToScreen(WorldLocation, OutScreenLocation, true); // bPlayerViewportRelative = true

    // DPI 보정
    const float UIScale = UWidgetLayoutLibrary::GetViewportScale(this);
    OutScreenLocation /= UIScale;

    const FVector2D VP = SavedViewportSize.IsNearlyZero() ?
        UWidgetLayoutLibrary::GetViewportSize(this) / UIScale :
        SavedViewportSize;

    bIsOnScreen = (OutScreenLocation.X >= 0.f && OutScreenLocation.X <= VP.X &&
        OutScreenLocation.Y >= 0.f && OutScreenLocation.Y <= VP.Y);

    return bProjected;
}



FVector2D UCPP_W_Indicator::GetEdgeClampedPosition(const FVector2D& ScreenPosition,
    const FVector2D& ViewportSize) const
{
    const FVector2D Center = ViewportSize * 0.5f;
    FVector2D Dir = (ScreenPosition - Center);
    if (!Dir.Normalize())
    {
        Dir = FVector2D(1.f, 0.f);
    }

    const float EdgeBuffer = 35.f;
    const float HalfW = ViewportSize.X * 0.5f - EdgeBuffer;
    const float HalfH = ViewportSize.Y * 0.5f - EdgeBuffer;

    float X = Dir.X * HalfW;
    float Y = Dir.Y * HalfH;

    const float Slope = FMath::Abs(Dir.Y / Dir.X);
    if (Slope > (HalfH / HalfW))
    {
        // 위/아래에 먼저 닿음
        Y = FMath::Sign(Dir.Y) * HalfH;
        X = Y / Slope;
    }
    else
    {
        // 좌/우에 먼저 닿음
        X = FMath::Sign(Dir.X) * HalfW;
        Y = X * Slope;
    }

    return Center + FVector2D(X, Y);
}
