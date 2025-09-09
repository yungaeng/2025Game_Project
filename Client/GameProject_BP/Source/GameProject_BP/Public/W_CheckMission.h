#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/CheckBox.h"
#include "Components/Image.h"
#include "W_CheckMission.generated.h"

/**
 * 단일 미션 체크박스 위젯
 */
UCLASS()
class GAMEPROJECT_BP_API UW_CheckMission : public UUserWidget
{
    GENERATED_BODY()

    public:
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission", meta = (ExposeOnSpawn = "true"))
    AActor* MissionActor = nullptr;
    UImage* RandomSyllablebox;
    UImage* MatchingPasswordbox;
    UImage* Screemingbox;

    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FName CompleteVarName = TEXT("bIsComplete");


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    bool bCheckedWhenActorInvalid = false;

protected:
   
    UPROPERTY(meta = (BindWidget))
    UCheckBox* CheckBox_Mission = nullptr;

    virtual void NativeConstruct() override;
    virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

private:
    bool ReadBoolFromMission(bool& OutValue) const;
    void UpdateCheckBox();
    void RightSyllableCheck();
    void MatchingPassword();
    void Screeming();
};
