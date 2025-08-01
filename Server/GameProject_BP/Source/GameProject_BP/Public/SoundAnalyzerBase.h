#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SoundAnalyzerBase.generated.h"

// BP에서 사용할 멀티캐스트 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSoundAnalyzerClear);

UCLASS(Abstract) // 직접 배치 안 할 거면 Abstract로
class GAMEPROJECT_BP_API ASoundAnalyzerBase : public AActor
{
    GENERATED_BODY()

    public:
    // BP에서 Bind Event 노드로 바인딩할 수 있게 UPROPERTY 지정
    UPROPERTY(BlueprintAssignable, Category = "SoundAnalyzer")
    FOnSoundAnalyzerClear OnSoundAnalyzerClear;

    // C++이나 BP에서 호출할 클리어 함수
    UFUNCTION(BlueprintCallable, Category = "SoundAnalyzer")
    void BroadcastCleared()
    {
        OnSoundAnalyzerClear.Broadcast();
    }
};
