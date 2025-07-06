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
class UFFT1DComponent;

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
    virtual void OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock)
    {
        if (!FFTComponent || NumSamples == 0 || NumChannels == 0)
        {
            return;
        }

        // ProcessBuffer가 충분한 크기인지 확인
        if (ProcessBuffer.Num() < NumSamples)
        {
            ProcessBuffer.SetNumZeroed(NumSamples);
        }

        // 멀티 채널 오디오를 모노로 다운믹스
        for (int32 i = 0; i < NumSamples; ++i)
        {
            float Sum = 0.0f;
            for (int32 Channel = 0; Channel < NumChannels; ++Channel)
            {
                Sum += AudioData[i * NumChannels + Channel];
            }
            ProcessBuffer[i] = Sum / NumChannels;
        }

        // 윈도우 함수를 적용한 버퍼 생성
        TArray<float> WindowedBuffer;
        WindowedBuffer.SetNum(FFTSize);

        const int32 SamplesToProcess = FMath::Min(NumSamples, FFTSize);

        for (int32 i = 0; i < SamplesToProcess; ++i)
        {
            WindowedBuffer[i] = ProcessBuffer[i] * WindowBuffer[i];
        }

        // 남은 부분은 0으로 채움
        for (int32 i = SamplesToProcess; i < FFTSize; ++i)
        {
            WindowedBuffer[i] = 0.0f;
        }

        // FFT 수행
        TArray<FVector2D> FFTOutput;
        if (FFTComponent->PerformForwardFFT(WindowedBuffer, FFTOutput))
        {
            // 주요 주파수 찾기
            float Confidence = 0.0f;
            float Frequency = FindFundamentalFrequency(FFTOutput, SampleRate, Confidence);

            // 진폭 계산 (간단한 RMS 계산)
            float SumSquared = 0.0f;
            for (int32 i = 0; i < SamplesToProcess; ++i)
            {
                SumSquared += WindowedBuffer[i] * WindowedBuffer[i];
            }
            float RMS = FMath::Sqrt(SumSquared / SamplesToProcess);
            float VolumeDB = AmplitudeToDB(RMS);

            // 결과가 의미있는 경우 (임계값 및 주파수 범위 확인)
            if (Frequency >= MIN_FREQUENCY && Frequency <= MAX_FREQUENCY && Confidence > Threshold)
            {
                // 주파수를 음정 이름으로 변환
                FString NoteName = FrequencyToNoteName(Frequency);

                // 결과 업데이트
                CurrentPitchInfo.Frequency = Frequency;
                CurrentPitchInfo.NoteName = NoteName;
                CurrentPitchInfo.Confidence = Confidence;
                CurrentPitchInfo.Volume = VolumeDB;

                // 이벤트 발생 
                OnPitchDetected.Broadcast(CurrentPitchInfo);
            }
        }
    }


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
    UFFT1DComponent* FFTComponent;


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