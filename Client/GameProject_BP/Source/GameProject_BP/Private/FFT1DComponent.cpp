

#include "FFT1DComponent.h"
#include "Math/UnrealMathUtility.h"

UFFT1DComponent::UFFT1DComponent()
{
    // Set this component to be initialized when the game starts, and to be ticked every frame
    PrimaryComponentTick.bCanEverTick = true;
}

void UFFT1DComponent::BeginPlay()
{
    Super::BeginPlay();
}

void UFFT1DComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

bool UFFT1DComponent::PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData)
{
    int32 N = InputData.Num();

    //2의 제곱이 아니면 반환하도록
    if (!IsPowerOfTwo(N))
    {
        UE_LOG(LogTemp, Warning, TEXT("FFT requires input size to be a power of 2. Current size: %d"), N);
        return false;
    }

    //실수-> 복소수
    TArray<FSimpleComplex> ComplexData;
    ComplexData.SetNum(N);

    for (int32 i = 0; i < N; ++i)
    {
        ComplexData[i] = FSimpleComplex(InputData[i], 0.0f);
    }

    FFT_CooleyTukey(ComplexData, N, false);


    //블프를 위해 바꾸기
    OutputData.SetNum(N);
    for (int32 i = 0; i < N; ++i)
    {
        OutputData[i] = FVector2D(ComplexData[i].Real, ComplexData[i].Imag);
    }

    return true;
}

// 주파수 → 시간 도메인 복원
bool UFFT1DComponent::PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData)
{
    int32 N = InputData.Num();

    if (!IsPowerOfTwo(N))
    {
        UE_LOG(LogTemp, Warning, TEXT("IFFT requires input size to be a power of 2. Current size: %d"), N);
        return false;
    }

    TArray<FSimpleComplex> ComplexData;
    ComplexData.SetNum(N);

    for (int32 i = 0; i < N; ++i)
    {
        ComplexData[i] = FSimpleComplex(InputData[i].X, InputData[i].Y);
    }

    FFT_CooleyTukey(ComplexData, N, true);

    OutputData.SetNum(N);
    for (int32 i = 0; i < N; ++i)
    {
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
    BitReversalPermutation(X, N);

    for (int32 s = 1; s <= FMath::Log2(float(N)); ++s)
    {
        int32 m = 1 << s; //2를 곱한다.      // 연산되는 데이터 묶음의 크기
        int32 m2 = m >> 1;  //2를 나눈다.   //버터플라이 연산 데이터 묶음의 크기


        float angle = 2.0f * PI / m;         // 회전 인자의 각도를 계산하는 공식

        if (InverseFFT)
        {
            angle = -angle; 
        }
        FSimpleComplex omega_m(FMath::Cos(angle), FMath::Sin(angle));

        for (int32 k = 0; k < N; k += m)
        {
            FSimpleComplex omega(1.0f, 0.0f); 

            for (int32 j = 0; j < m2; ++j)
            {
                FSimpleComplex t = omega * X[k + j + m2];
                FSimpleComplex u = X[k + j];

                
                X[k + j] = u + t;
                X[k + j + m2] = u - t;

              
                omega = omega * omega_m;
            }
        }
    }
}


// 입력 배열의 순서를 비트 반전된 인덱스 순서로 재배열
// 버터플라이 연산을 하기 위해

void UFFT1DComponent::BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N)
{
    for (int32 i = 0; i < N; ++i)
    {
        int32 j = BitReverse(i, N);
        if (j > i)
        {
            FSimpleComplex temp = X[i];
            X[i] = X[j];
            X[j] = temp;
        }
    }
}

int32 UFFT1DComponent::BitReverse(int32 Index, int32 N)
{
    int32 numBits = FMath::Log2(float(N));      //비트 갯수 계산
    int32 reversed = 0;

    for (int32 i = 0; i < numBits; ++i)
    {
        reversed = (reversed << 1) | (Index & 1);
        Index >>= 1;
    }

    return reversed;
}