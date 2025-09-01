#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MissionBase.generated.h"

UCLASS()
class GAMEPROJECT_BP_API AMissionBase : public AActor
{
    GENERATED_BODY()

    public:
    AMissionBase();

protected:
    // 미션 ID
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission")
    FName MissionID;

    // 완료 여부
    UPROPERTY(ReplicatedUsing = OnRep_IsComplete, BlueprintReadOnly, Category = "Mission")
    bool bIsComplete = false;

public:
    // 완료 여부 가져오기
    UFUNCTION(BlueprintCallable, Category = "Mission")
    bool IsComplete() const { return bIsComplete; }

    // 완료 처리 
    UFUNCTION(BlueprintCallable, Category = "Mission")
    void SetMissionComplete(bool bNewComplete);

    // 미션 ID 가져오기
    UFUNCTION(BlueprintCallable, Category = "Mission")
    FName GetMissionID() const { return MissionID; }

protected:
    
    UFUNCTION()
    void OnRep_IsComplete();

    // 리플리케이션 설정
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
};
