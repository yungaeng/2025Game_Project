#include "W_CheckMission.h"
#include "UObject/UnrealType.h" // FBoolProperty

void UW_CheckMission::NativeConstruct()
{
    Super::NativeConstruct();
    UpdateCheckBox();
}

void UW_CheckMission::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
    Super::NativeTick(MyGeometry, InDeltaTime);
    UpdateCheckBox();
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
    // bOk가 false면 bCheckedWhenActorInvalid 값 사용
    CheckBox_Mission->SetIsChecked(bValue);
}
