
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AudioDevice.h"
#include "Sound/SoundSubmix.h"
#include "ISubmixBufferListener.h"
#include "PitchDetectorComponent.generated.h"

class UMyFFTComponent;

USTRUCT(BlueprintType)
struct FPitchInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Frequency = 0.0f;                                     // 소리 주파수

    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    FString NoteName = "N/A";                                   // 음 이름

    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Confidence = 0.0f;                                    // 분석 정확도

    UPROPERTY(BlueprintReadOnly, Category = "Audio Analysis")
    float Volume = -60.0f;                                      // 소리 크기
};


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPitchDetected, const FPitchInfo&, PitchInfo);

UCLASS(ClassGroup = (Audio), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_BP_API UPitchDetectorComponent : public UActorComponent, public ISubmixBufferListener
{
    GENERATED_BODY()

    public:
    UPitchDetectorComponent();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    // 언리얼이 소리 데이터 줄 때 호출
    virtual void OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock);


    UFUNCTION(BlueprintCallable, Category = "Audio Analysis")
    FPitchInfo GetCurrentPitch() const;     // 현재 감지 된 음 높이 정보 (FPitchInfo)를 가져오는 함수

    UFUNCTION(BlueprintCallable, Category = "Audio Analysis")
    static FString FrequencyToNoteName(float Frequency); //음이름으로 바꾸는 함수 440Hz -> A4

    UPROPERTY(BlueprintAssignable, Category = "Audio Analysis")
    FOnPitchDetected OnPitchDetected;  // 소리를 감지하는 기능

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis", meta = (ClampMin = "512", ClampMax = "16384"))
    int32 FFTSize = 2048;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis", meta = (ClampMin = "0.0", ClampMax = "1.0"))
    float Threshold = 0.01f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Audio Analysis")
    USoundSubmix* TargetSubmix;

private:
    UPROPERTY()
    UMyFFTComponent* FFTComponent;

    bool bIsDetecting;

    FPitchInfo CurrentPitchInfo;

    TArray<float> WindowBuffer;

    TArray<float> ProcessBuffer;

    //분석에 쓸 윈도우 함수 계산
    void InitializeWindowFunction();

    // FFT를 사용해서 음의 높이 찾아내기
    float FindFundamentalFrequency(const TArray<FVector2D>& Spectrum, float SampleRate, float& OutConfidence);      

    //진폭을 데시벨로 변환
    float AmplitudeToDB(float Amplitude) const;


};