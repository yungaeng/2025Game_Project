#include "CPP_W_Indicator.h"
#include "Components/Image.h"
#include "Components/CanvasPanelSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "GameFramework/PlayerController.h"

void UCPP_W_Indicator::SetTarget(AActor* NewTarget)
{
    TargetActor = NewTarget;
}

void UCPP_W_Indicator::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);

    if (!TargetActor) return;

    APlayerController* PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
    if (!PC) return;

    FVector WorldLocation = TargetActor->GetActorLocation();
    FVector2D ScreenLocation;
    bool bProjected = PC->ProjectWorldLocationToScreen(WorldLocation, ScreenLocation);

    if (bProjected && IndicatorIcon)
    {
        // 위젯의 위치를 화면 좌표로 이동
        UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Slot);
        if (CanvasSlot)
        {
            CanvasSlot->SetPosition(ScreenLocation);
        }
    }
}
