
#include "PitchDetectorComponent.h"
#include "Engine/Engine.h"
#include "MyFFTComponent.h"
#include "Sound/SoundSubmix.h"
#include "AudioDevice.h"
#include "AudioMixerDevice.h"

constexpr float MIN_FREQUENCY = 20.0f;    // 분석할 최소 주파수 (Hz)
constexpr float MAX_FREQUENCY = 10000.0f;  // 분석할 최대 주파수 (Hz)
constexpr int32 DEFAULT_SAMPLE_RATE = 48000;  // 기본 샘플링 레이트
constexpr float A4_FREQUENCY = 440.0f;     // A4 음의 기준 주파수
constexpr int32 A4_MIDI_NOTE = 69;         // A4 음의 MIDI 노트 번호

UPitchDetectorComponent::UPitchDetectorComponent()
{
    PrimaryComponentTick.bCanEverTick = true;
    bIsDetecting = false;

    TargetSubmix = nullptr; 
}

void UPitchDetectorComponent::BeginPlay()
{
    Super::BeginPlay();

    
    FFTComponent = NewObject<UMyFFTComponent>(this);
    FFTComponent->RegisterComponent();

    InitializeWindowFunction();

    //현재 사용중인 오디오 장치를 가져옴
    if (GEngine->GetActiveAudioDevice().GetAudioDevice())
    {
        GEngine->GetActiveAudioDevice().GetAudioDevice()->RegisterSoundSubmix(TargetSubmix, true);
        GEngine->GetActiveAudioDevice().GetAudioDevice()->RegisterSubmixBufferListener(this, TargetSubmix);
    }
    

    // 소리를 받아오기 위함 설정
    if (TargetSubmix)
    {
        TargetSubmix->OutputVolume = 0.0f;      //스피커에는 소리가 안나오게
        TargetSubmix->ParentSubmix = nullptr;   // 다른 서브믹스에서 소리 안나오게 하기
    }
    ProcessBuffer.SetNumZeroed(FFTSize);

}

void UPitchDetectorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}


FPitchInfo UPitchDetectorComponent::GetCurrentPitch() const
{
    return CurrentPitchInfo;
}

//소리가 들어올때마다 자동 호출
void UPitchDetectorComponent::OnNewSubmixBuffer(const USoundSubmix* OwningSubmix, float* AudioData, int32 NumSamples, int32 NumChannels, const int32 SampleRate, double AudioClock)
{
    if (!FFTComponent || NumSamples == 0 || NumChannels == 0)
    {
        return;
    }

    // 소리 데이터를 받아서 ProcessBufer에 저장
    if (ProcessBuffer.Num() < NumSamples)
    {
        ProcessBuffer.SetNumZeroed(NumSamples);
    }

    // 다채널을 모노 채널로 바꿈
    for (int32 i = 0; i < NumSamples; ++i)
    {
        float Sum = 0.0f;
        for (int32 Channel = 0; Channel < NumChannels; ++Channel)
        {
            Sum += AudioData[i * NumChannels + Channel];
        }
        ProcessBuffer[i] = Sum / NumChannels;
    }

   
    TArray<float> WindowedBuffer;
    WindowedBuffer.SetNum(FFTSize);

    const int32 SamplesToProcess = FMath::Min(NumSamples, FFTSize);

    // 윈도우 함수를 곱해서 부드럽게
   // 앞뒤를 잘라서 튀는걸 방지
    for (int32 i = 0; i < SamplesToProcess; ++i)
    {
        WindowedBuffer[i] = ProcessBuffer[i] * WindowBuffer[i];
    }

    //남으면 0으로 채우기
    for (int32 i = SamplesToProcess; i < FFTSize; ++i)
    {
        WindowedBuffer[i] = 0.0f;
    }

    TArray<FVector2D> FFTOutput;

    // 윈도우 처리된 FFT분석
    if (FFTComponent->PerformForwardFFT(WindowedBuffer, FFTOutput))
    {
        float Confidence = 0.0f;

        //FFTOutput 결과에서 가장 강한 주파수를 찾아내기
        float Frequency = FindFundamentalFrequency(FFTOutput, SampleRate, Confidence);

        // 소리 크기 계산
        float SumSquared = 0.0f;
        for (int32 i = 0; i < SamplesToProcess; ++i)
        {
            SumSquared += WindowedBuffer[i] * WindowedBuffer[i];        // 소리는 +- 다 있어서 제곱해서 더하기
        }
        float RMS = FMath::Sqrt(SumSquared / SamplesToProcess);
        float VolumeDB = AmplitudeToDB(RMS); // amplitude를 데시벨로 바꿈

        if (Frequency >= MIN_FREQUENCY && Frequency <= MAX_FREQUENCY && Confidence > Threshold)
        {
            FString NoteName = FrequencyToNoteName(Frequency);

            CurrentPitchInfo.Frequency = Frequency;
            CurrentPitchInfo.NoteName = NoteName;
            CurrentPitchInfo.Confidence = Confidence;
            CurrentPitchInfo.Volume = VolumeDB;

            OnPitchDetected.Broadcast(CurrentPitchInfo);
        }
    }
}

//스펙트럼 누출을 막기 위한 함수 
//컴퓨터가 소리를 분석하려면 일정한 길이로 자르는데 (2048) 갑자기 끊기면 이상해지기 때문에 그걸 막기 위해
void UPitchDetectorComponent::InitializeWindowFunction()
{
    WindowBuffer.SetNum(FFTSize);
    for (int32 i = 0; i < FFTSize; ++i)
    {
        // Hann 윈도우 함수를 계산
        WindowBuffer[i] = 0.5f * (1.0f - FMath::Cos(2.0f * PI * i / (FFTSize - 1)));
    }
}

// 음높이 주파수를 찾기
float UPitchDetectorComponent::FindFundamentalFrequency(const TArray<FVector2D>& Spectrum, float SampleRate, float& OutConfidence)
{
    if (Spectrum.Num() < 2)
    {
        OutConfidence = 0.0f;
        return 0.0f;
    }

    const int32 SpectrumSize = Spectrum.Num();

    const float BinSize = SampleRate / SpectrumSize;

    const int32 MinBin = FMath::Max(1, FMath::FloorToInt(MIN_FREQUENCY / BinSize));
    const int32 MaxBin = FMath::Min(SpectrumSize / 2, FMath::CeilToInt(MAX_FREQUENCY / BinSize));

    TArray<float> Amplitudes;
    Amplitudes.SetNum(SpectrumSize);

    for (int32 i = 0; i < SpectrumSize; ++i)
    {
        Amplitudes[i] = FMath::Sqrt(Spectrum[i].X * Spectrum[i].X + Spectrum[i].Y * Spectrum[i].Y);
    }

    float MaxAmplitude = 0.0f;
    int32 MaxAmplitudeIndex = 0;


    //가장 강한 주파수 찾기
    for (int32 i = MinBin; i <= MaxBin; ++i)
    {
        if (Amplitudes[i] > MaxAmplitude)
        {
            MaxAmplitude = Amplitudes[i];
            MaxAmplitudeIndex = i;
        }
    }

    //보간
    // FFT는 정해진 간격만 보여주기 때문에 보간으로 사이값추정
    float InterpolatedIndex = MaxAmplitudeIndex;
    if (MaxAmplitudeIndex > 0 && MaxAmplitudeIndex < SpectrumSize - 1)
    {
        float Alpha = Amplitudes[MaxAmplitudeIndex - 1];
        float Beta = Amplitudes[MaxAmplitudeIndex];
        float Gamma = Amplitudes[MaxAmplitudeIndex + 1];
        float Adjustment = 0.5f * (Alpha - Gamma) / (Alpha - 2.0f * Beta + Gamma);

        Adjustment = FMath::Clamp(Adjustment, -0.5f, 0.5f);
        InterpolatedIndex = MaxAmplitudeIndex + Adjustment;
    }

    //보간한 인덱스를 실제 주파수로 변환
    float Frequency = InterpolatedIndex * BinSize;

    float SurroundingAverage = 0.0f;
    int32 SurroundingCount = 0;

    const int32 SurroundingRange = 5; 

    for (int32 i = FMath::Max(0, MaxAmplitudeIndex - SurroundingRange);
        i <= FMath::Min(SpectrumSize - 1, MaxAmplitudeIndex + SurroundingRange); ++i)
    {
        if (FMath::Abs(i - MaxAmplitudeIndex) > 1) 
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

    if (MaxAmplitude < Threshold || OutConfidence < Threshold)
    {
        Frequency = 0.0f;
        OutConfidence = 0.0f;
    }

    return Frequency;
}

//주파수를 음이름으로 바꾸기
FString UPitchDetectorComponent::FrequencyToNoteName(float Frequency)
{
    if (Frequency <= 0.0f)
    {
        return TEXT("N/A");
    }

    float SemitonesFromA4 = 12.0f * FMath::Log2(Frequency / A4_FREQUENCY);
    int32 SemitonesRounded = FMath::RoundToInt(SemitonesFromA4);

    float Cents = 100.0f * (SemitonesFromA4 - SemitonesRounded);

    int32 MidiNote = A4_MIDI_NOTE + SemitonesRounded;

    const TCHAR* NoteNames[] = { TEXT("C"), TEXT("C#"), TEXT("D"), TEXT("D#"), TEXT("E"), TEXT("F"),
                                TEXT("F#"), TEXT("G"), TEXT("G#"), TEXT("A"), TEXT("A#"), TEXT("B") };

    int32 NoteIndex = (MidiNote) % 12; 
    int32 Octave = (MidiNote - NoteIndex) / 12 - 1; 

    FString NoteName;

    if (FMath::Abs(Cents) < 25.0f) 
    {
        NoteName = FString::Printf(TEXT("%s%d"), NoteNames[NoteIndex], Octave);
    }
    else 
    {
        const TCHAR* Direction = Cents > 0.0f ? TEXT("+") : TEXT("");
        NoteName = FString::Printf(TEXT("%s%d (%s%.0f¢)"),
            NoteNames[NoteIndex], Octave, Direction, Cents);
    }

    return NoteName;
}



//소리 크기를 데시벨로 바꾸기
//Amplitude는 너무 작아서 데시벨로 바꾸기
float UPitchDetectorComponent::AmplitudeToDB(float Amplitude) const
{
    constexpr float MIN_DB = -60.0f; 

    return FMath::Max(20.0f * FMath::LogX(10.0f, Amplitude * 10000), MIN_DB);
}

