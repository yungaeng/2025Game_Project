// UPitchDetectorComponent.cpp
// 서브믹스 시스템을 활용한 개선된 피치 감지 컴포넌트

#include "PitchDetectorComponent.h"
#include "Engine/Engine.h"
#include "FFT1DComponent.h"
#include "Sound/SoundSubmix.h"
#include "AudioDevice.h"
#include "AudioMixerDevice.h"

// 상수 정의
constexpr float MIN_FREQUENCY = 20.0f;    // 분석할 최소 주파수 (Hz)
constexpr float MAX_FREQUENCY = 10000.0f;  // 분석할 최대 주파수 (Hz)
constexpr int32 DEFAULT_SAMPLE_RATE = 48000;  // 기본 샘플링 레이트
constexpr float A4_FREQUENCY = 440.0f;     // A4 음의 기준 주파수
constexpr int32 A4_MIDI_NOTE = 69;         // A4 음의 MIDI 노트 번호

UPitchDetectorComponent::UPitchDetectorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsDetecting = false;

    // 기본 서브믹스 설정
    TargetSubmix = nullptr; // BeginPlay에서 마스터 서브믹스로 설정될 것임
}

void UPitchDetectorComponent::BeginPlay()
{
    Super::BeginPlay();

    // FFT 컴포넌트 생성 (현재는 직접 만든 FFT 컴포넌트 사용)
    FFTComponent = NewObject<UFFT1DComponent>(this);
    FFTComponent->RegisterComponent();

    // 윈도우 함수 초기화
    InitializeWindowFunction();

    // 오디오 분석기 서브시스템 가져오기
    if (GEngine->GetActiveAudioDevice().GetAudioDevice())
    {
        GEngine->GetActiveAudioDevice().GetAudioDevice()->RegisterSoundSubmix(TargetSubmix, true);
        GEngine->GetActiveAudioDevice().GetAudioDevice()->RegisterSubmixBufferListener(this, TargetSubmix);

    }

    if (TargetSubmix)
    {
        TargetSubmix->OutputVolume = 0.0f;
        TargetSubmix->ParentSubmix = nullptr;
    }
    // 버퍼 초기화
    ProcessBuffer.SetNumZeroed(FFTSize);

    UE_LOG(LogTemp, Warning, TEXT("DoneINIT"));
}

void UPitchDetectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // 필요에 따라 추가 업데이트 로직 구현 가능
}


FPitchInfo UPitchDetectorComponent::GetCurrentPitch() const
{
    return CurrentPitchInfo;
}

void UPitchDetectorComponent::OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock)
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

void UPitchDetectorComponent::InitializeWindowFunction()
{
    // Hann 윈도우 함수 초기화
    WindowBuffer.SetNum(FFTSize);
    for (int32 i = 0; i < FFTSize; ++i)
    {
        // Hann 윈도우: 0.5 * (1 - cos(2PI * n / (N-1)))
        WindowBuffer[i] = 0.5f * (1.0f - FMath::Cos(2.0f * PI * i / (FFTSize - 1)));
    }
}

float UPitchDetectorComponent::FindFundamentalFrequency(const TArray<FVector2D>& Spectrum, float SampleRate, float& OutConfidence)
{
    // 스펙트럼 크기 확인
    if (Spectrum.Num() < 2)
    {
        OutConfidence = 0.0f;
        return 0.0f;
    }

    const int32 SpectrumSize = Spectrum.Num();

    // 주파수 빈 간격 계산 (Hz per bin)
    const float BinSize = SampleRate / SpectrumSize;

    // 관심 있는 주파수 범위에 대한 빈 인덱스 계산
    const int32 MinBin = FMath::Max(1, FMath::FloorToInt(MIN_FREQUENCY / BinSize));
    const int32 MaxBin = FMath::Min(SpectrumSize / 2, FMath::CeilToInt(MAX_FREQUENCY / BinSize));

    // 스펙트럼 진폭 계산
    TArray<float> Amplitudes;
    Amplitudes.SetNum(SpectrumSize);

    for (int32 i = 0; i < SpectrumSize; ++i)
    {
        // 복소수 진폭 계산 (절대값)
        Amplitudes[i] = FMath::Sqrt(Spectrum[i].X * Spectrum[i].X + Spectrum[i].Y * Spectrum[i].Y);
    }

    // 최대 진폭 찾기
    float MaxAmplitude = 0.0f;
    int32 MaxAmplitudeIndex = 0;

    for (int32 i = MinBin; i <= MaxBin; ++i)
    {
        if (Amplitudes[i] > MaxAmplitude)
        {
            MaxAmplitude = Amplitudes[i];
            MaxAmplitudeIndex = i;
        }
    }

    // 주파수 보간 (Quadratic Interpolation) 적용 - 더 정확한 피크 찾기
    float InterpolatedIndex = MaxAmplitudeIndex;
    if (MaxAmplitudeIndex > 0 && MaxAmplitudeIndex < SpectrumSize - 1)
    {
        float Alpha = Amplitudes[MaxAmplitudeIndex - 1];
        float Beta = Amplitudes[MaxAmplitudeIndex];
        float Gamma = Amplitudes[MaxAmplitudeIndex + 1];
        float Adjustment = 0.5f * (Alpha - Gamma) / (Alpha - 2.0f * Beta + Gamma);

        // 보간 범위 제한 (-0.5 ~ 0.5)
        Adjustment = FMath::Clamp(Adjustment, -0.5f, 0.5f);
        InterpolatedIndex = MaxAmplitudeIndex + Adjustment;
    }

    // 감지된 주파수 계산
    float Frequency = InterpolatedIndex * BinSize;

    // 신뢰도 계산 (주변 평균 대비 피크의 상대적 높이)
    float SurroundingAverage = 0.0f;
    int32 SurroundingCount = 0;

    const int32 SurroundingRange = 5; // 주변 빈 범위

    for (int32 i = FMath::Max(0, MaxAmplitudeIndex - SurroundingRange);
        i <= FMath::Min(SpectrumSize - 1, MaxAmplitudeIndex + SurroundingRange); ++i)
    {
        if (FMath::Abs(i - MaxAmplitudeIndex) > 1) // 직접적인 이웃은 제외
        {
            SurroundingAverage += Amplitudes[i];
            SurroundingCount++;
        }
    }

    if (SurroundingCount > 0)
    {
        SurroundingAverage /= SurroundingCount;
        OutConfidence = (MaxAmplitude - SurroundingAverage) / (MaxAmplitude + 1e-6f); // 0-1 범위로 정규화
    }
    else
    {
        OutConfidence = 0.0f;
    }

    // 노이즈 임계값 적용
    if (MaxAmplitude < Threshold || OutConfidence < Threshold)
    {
        Frequency = 0.0f;
        OutConfidence = 0.0f;
    }

    return Frequency;
}

FString UPitchDetectorComponent::FrequencyToNoteName(float Frequency)
{
    if (Frequency <= 0.0f)
    {
        return TEXT("N/A");
    }

    // A4 = 440Hz를 기준으로 음정 계산
    float SemitonesFromA4 = 12.0f * FMath::Log2(Frequency / A4_FREQUENCY);
    int32 SemitonesRounded = FMath::RoundToInt(SemitonesFromA4);

    // 0.25 (1/4) 음 이내인지 확인하여 센트 값을 계산
    float Cents = 100.0f * (SemitonesFromA4 - SemitonesRounded);

    // MIDI 노트 번호 계산
    int32 MidiNote = A4_MIDI_NOTE + SemitonesRounded;

    // 옥타브와 음 이름 계산
    const TCHAR* NoteNames[] = { TEXT("C"), TEXT("C"), TEXT("D"), TEXT("D"), TEXT("E"), TEXT("F"),
                                TEXT("F"), TEXT("G"), TEXT("G"), TEXT("A"), TEXT("A"), TEXT("B") };

    int32 NoteIndex = (MidiNote) % 12; // C를 0으로 만들기 위한 조정 (MIDI에서 C0 = 12)
    

    // 음정 이름 생성
    FString NoteName = NoteNames[NoteIndex];

    

    return NoteName;
}

float UPitchDetectorComponent::AmplitudeToDB(float Amplitude) const
{
    // 진폭을 데시벨로 변환 (기준: 1.0)
    // dB = 20 * log10(amplitude)
    constexpr float MIN_DB = -60.0f; // 최소 dB 값

    return FMath::Max(20.0f * FMath::LogX(10.0f, Amplitude * 10000), MIN_DB);
}