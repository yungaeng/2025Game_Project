// UPitchDetectorComponent.h
// 서브믹스 시스템을 활용한 개선된 피치 감지 컴포넌트

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AudioDevice.h"
#include "Sound/SoundSubmix.h"
#include "ISubmixBufferListener.h"
#include "PitchDetectorComponent.generated.h"

// FFT 컴포넌트 전방 선언
class UMyFFTComponent;

// 감지된 음정 정보를 담는 구조체
USTRUCT(BlueprintType)
struct FPitchInfo
{
    GENERATED_BODY()

    // 감지된 주파수 (Hz)
    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Frequency = 0.0f;

    // 음정의 이름 (C4, A3 등)
    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    FString NoteName = "N/A";

    // 감지된 주파수의 신뢰도 (0-1)
    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Confidence = 0.0f;

    // 음정의 세기/볼륨 (dB)
    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Volume = -60.0f;
};

// 음정이 감지되었을 때 발생하는 이벤트를 위한 델리게이트
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPitchDetected, const FPitchInfo&, PitchInfo);

UCLASS(ClassGroup = (Audio), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_BP_API UPitchDetectorComponent : public UActorComponent, public ISubmixBufferListener
{
    GENERATED_BODY()

    public:
    UPitchDetectorComponent();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // ISubmixBufferListener 인터페이스 구현
    virtual void OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock);


    // 현재 감지된 음정 정보 반환
    UFUNCTION(BlueprintCallable, Category = "Audio Analysis")
    FPitchInfo GetCurrentPitch() const;

    // 주파수를 음정 이름으로 변환
    UFUNCTION(BlueprintCallable, Category = "Audio Analysis")
    static FString FrequencyToNoteName(float Frequency);

    // 음정이 감지되었을 때 호출되는 이벤트
    UPROPERTY(BlueprintAssignable, Category = "Audio Analysis")
    FOnPitchDetected OnPitchDetected;

    // 사용할 FFT 크기 (2의 거듭제곱이어야 함, 예: 1024, 2048, 4096)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis", meta = (ClampMin = "512", ClampMax = "16384"))
    int32 FFTSize = 2048;

    // 분석 감도 조절 (낮을수록 더 민감)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Threshold = 0.01f;

    // 마이크 입력을 처리할 서브믹스 (보통 MasterSubmix 또는 VoiceChatSubmix)
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis")
    USoundSubmix* TargetSubmix;

private:
    // FFT 컴포넌트
    UPROPERTY()
    UMyFFTComponent* FFTComponent;


    // 오디오 분석 옵션
    //FAudioAnalysisOptions AnalysisOptions;

    // 피치 감지 상태
    bool bIsDetecting;

    // 마지막 감지된 음정 정보
    FPitchInfo CurrentPitchInfo;

    // 윈도우 함수 버퍼
    TArray<float> WindowBuffer;

    // 오디오 버퍼 (멀티 채널 오디오를 모노로 변환)
    TArray<float> ProcessBuffer;

    // 윈도우 함수 초기화 (Hann 윈도우)
    void InitializeWindowFunction();

    // 스펙트럼에서 주요 피크 찾기
    float FindFundamentalFrequency(const TArray<FVector2D>& Spectrum, float SampleRate, float& OutConfidence);

    // 진폭을 데시벨로 변환
    float AmplitudeToDB(float Amplitude) const;


};