#include "W_CheckMission.h"
#include "UObject/UnrealType.h" // FBoolProperty

void UW_CheckMission::NativeConstruct()
{
    Super::NativeConstruct();
    UpdateCheckBox();
    RightSyllableCheck();
    MatchingPassword();
    Screeming();
}

void UW_CheckMission::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    UpdateCheckBox();
    RightSyllableCheck();
    MatchingPassword();
    Screeming();
}

bool UW_CheckMission::ReadBoolFromMission(bool& OutValue) const
{
    if (!MissionActor) return false;

    if (FProperty* FoundProp = MissionActor->GetClass()->FindPropertyByName(CompleteVarName))
    {
        if (FBoolProperty* BoolProp = CastField<FBoolProperty>(FoundProp))
        {
            void* ContainerPtr = FoundProp->ContainerPtrToValuePtr<void>(MissionActor);
            OutValue = BoolProp->GetPropertyValue(ContainerPtr);
            return true;
        }
    }
    return false;
}

void UW_CheckMission::UpdateCheckBox()
{
    if (!CheckBox_Mission) return;

    bool bValue = bCheckedWhenActorInvalid;
    const bool bOk = ReadBoolFromMission(bValue);
   
    CheckBox_Mission->SetIsChecked(bValue);
}

void UW_CheckMission::RightSyllableCheck()
{
    if (RandomSyllablebox)
    {
     
        FLinearColor NewColor = FLinearColor(0.f, 1.f, 0.f, 1.f);
        RandomSyllablebox->SetColorAndOpacity(NewColor);
    }
}


void UW_CheckMission::MatchingPassword()
{
    if (MatchingPasswordbox)
    {

        FLinearColor NewColor = FLinearColor(0.f, 1.f, 0.f, 1.f);
        MatchingPasswordbox->SetColorAndOpacity(NewColor);
    }
}

void UW_CheckMission::Screeming()
{
    if (Screemingbox)
    {

        FLinearColor NewColor = FLinearColor(0.f, 1.f, 0.f, 1.f);
        Screemingbox->SetColorAndOpacity(NewColor);
    }
}