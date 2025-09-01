#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CheckBox.h"
#include "W_CheckMission.generated.h"

/**
 * 단일 미션 체크박스 위젯
 */
UCLASS()
class GAMEPROJECT_BP_API UW_CheckMission : public UUserWidget
{
    GENERATED_BODY()

    public:
    // 블루프린트 미션 액터(예: BP_FixTemperature). CreateWidget 시 주입
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission", meta = (ExposeOnSpawn = "true"))
    AActor* MissionActor = nullptr;

    // 완료 여부 변수 이름(블루프린트 변수명). 추천: bIsComplete
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FName CompleteVarName = TEXT("bIsComplete");

    // 액터가 없을 때 기본 체크 상태
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    bool bCheckedWhenActorInvalid = false;

protected:
    // 디자이너에서 이름을 반드시 CheckBox_Mission 으로!
    UPROPERTY(meta = (BindWidget))
    UCheckBox* CheckBox_Mission = nullptr;

    virtual void NativeConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    bool ReadBoolFromMission(bool& OutValue) const;
    void UpdateCheckBox();
};
