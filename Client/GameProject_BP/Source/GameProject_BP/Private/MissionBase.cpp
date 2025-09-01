#include "MissionBase.h"
#include "Net/UnrealNetwork.h"

AMissionBase::AMissionBase()
{
    bReplicates = true; // 액터 전체 복제
}

void AMissionBase::SetMissionComplete(bool bNewComplete)
{
    if (HasAuthority()) // 서버에서만 값 변경
    {
        bIsComplete = bNewComplete;
        // RepNotify 호출 → 클라 반영
        OnRep_IsComplete();
    }
}

void AMissionBase::OnRep_IsComplete()
{
    // 클라에서 미션 완료 여부가 바뀔 때마다 실행
    UE_LOG(LogTemp, Log, TEXT("Mission %s complete = %s"),
        *MissionID.ToString(),
        bIsComplete ? TEXT("True") : TEXT("False"));
}

void AMissionBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AMissionBase, bIsComplete);
}
