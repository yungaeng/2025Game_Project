// Fill out your copyright notice in the Description page of Project Settings.


#include "FFT1DComponent.h"

// UFFT1DComponent.cpp
// A CPU-based 1D FFT implementation for Unreal Engine 5
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UFFT1DComponent::UFFT1DComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame
    PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UFFT1DComponent::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void UFFT1DComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UFFT1DComponent::PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData)
{
    int32 N = InputData.Num();

    // Check if the input size is a power of 2
    if (!IsPowerOfTwo(N))
    {
        UE_LOG(LogTemp, Warning, TEXT("FFT requires input size to be a power of 2. Current size: %d"), N);
        return false;
    }

    // 간단한 복소수 배열 준비 (실수부 = 입력 데이터, 허수부 = 0)
    TArray<FSimpleComplex> ComplexData;
    ComplexData.SetNum(N);

    for (int32 i = 0; i < N; ++i)
    {
        ComplexData[i] = FSimpleComplex(InputData[i], 0.0f);
    }

    // FFT 수행
    FFT_CooleyTukey(ComplexData, N, false);

    // 복소수 결과를 Blueprint에서 쉽게 사용할 수 있도록 FVector2D로 변환
    OutputData.SetNum(N);
    for (int32 i = 0; i < N; ++i)
    {
        OutputData[i] = FVector2D(ComplexData[i].Real, ComplexData[i].Imag);
    }

    return true;
}

bool UFFT1DComponent::PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData)
{
    int32 N = InputData.Num();

    // Check if the input size is a power of 2
    if (!IsPowerOfTwo(N))
    {
        UE_LOG(LogTemp, Warning, TEXT("IFFT requires input size to be a power of 2. Current size: %d"), N);
        return false;
    }

    // 간단한 복소수 배열 준비
    TArray<FSimpleComplex> ComplexData;
    ComplexData.SetNum(N);

    for (int32 i = 0; i < N; ++i)
    {
        ComplexData[i] = FSimpleComplex(InputData[i].X, InputData[i].Y);
    }

    // 역 FFT 수행
    FFT_CooleyTukey(ComplexData, N, true);

    // 실수부만 취하고 정규화
    OutputData.SetNum(N);
    for (int32 i = 0; i < N; ++i)
    {
        // N으로 나누어 정규화
        OutputData[i] = ComplexData[i].Real / N;
    }

    return true;
}

bool UFFT1DComponent::IsPowerOfTwo(int32 x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

int32 UFFT1DComponent::NextPowerOfTwo(int32 x)
{
    if (x <= 0) return 1;
    if (IsPowerOfTwo(x)) return x;

    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1;
}

void UFFT1DComponent::FFT_CooleyTukey(TArray<FSimpleComplex>& X, int32 N, bool InverseFFT)
{
    // 비트 반전 순열 수행
    BitReversalPermutation(X, N);

    // Cooley-Tukey FFT 알고리즘 (반복 버전)
    for (int32 s = 1; s <= FMath::Log2(float(N)); ++s)
    {
        int32 m = 1 << s; // 2^s
        int32 m2 = m >> 1; // m/2

        // 회전 인자 (twiddle factor) 계산
        float angle = 2.0f * PI / m;
        if (InverseFFT)
        {
            angle = -angle; // 역 FFT의 경우 부호 반전
        }
        FSimpleComplex omega_m(FMath::Cos(angle), FMath::Sin(angle));

        for (int32 k = 0; k < N; k += m)
        {
            FSimpleComplex omega(1.0f, 0.0f); // omega_m^0

            for (int32 j = 0; j < m2; ++j)
            {
                FSimpleComplex t = omega * X[k + j + m2];
                FSimpleComplex u = X[k + j];

                // 나비 연산 (Butterfly operation)
                X[k + j] = u + t;
                X[k + j + m2] = u - t;

                // omega 업데이트
                omega = omega * omega_m;
            }
        }
    }
}

void UFFT1DComponent::BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N)
{
    // 더 효율적인 알고리즘을 사용한 비트 반전 순열 수행
    for (int32 i = 0; i < N; ++i)
    {
        int32 j = BitReverse(i, N);
        if (j > i)
        {
            // 원소 교환
            FSimpleComplex temp = X[i];
            X[i] = X[j];
            X[j] = temp;
        }
    }
}

int32 UFFT1DComponent::BitReverse(int32 Index, int32 N)
{
    int32 numBits = FMath::Log2(float(N));
    int32 reversed = 0;

    for (int32 i = 0; i < numBits; ++i)
    {
        reversed = (reversed << 1) | (Index & 1);
        Index >>= 1;
    }

    return reversed;
}