// Fill out your copyright notice in the Description page of Project Settings.


#include "MyFFTComponent.h"
#include "Math/UnrealMathUtility.h"

// Sets default values for this component's properties
UMyFFTComponent::UMyFFTComponent()
{
	
	PrimaryComponentTick.bCanEverTick = true;		// 매 프레임 틱 실행 가능하게 설정

	
}


// Called when the game starts
void UMyFFTComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void UMyFFTComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}



bool UMyFFTComponent::PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData)
{
    int32 N = NextPowerOfTwo(InputData.Num());

    if (!IsPowerOfTwo(N))
    {
        UE_LOG(LogTemp, Warning, TEXT("FFT requires input size to be a power of 2. Current size: %d"), N);
        return false;
    }


    TArray<FSimpleComplex> ComplexData;
    ComplexData.SetNum(N);

    for (int32 i = 0; i < InputData.Num(); ++i)
    {
        ComplexData[i] = FSimpleComplex(InputData[i], 0.0f);
    }
    // FFT 수행
    FFT_CooleyTukey(ComplexData, N, false);

   
    // 복소수 결과를 FVector2D로 변환

    OutputData.SetNum(N);
    for (int32 i = 0; i < N; ++i)
    {
        OutputData[i] = FVector2D(ComplexData[i].Real, ComplexData[i].Imag);
    }

    return true;
}

bool UMyFFTComponent::PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData)
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



// fft가 2의 제곱인지 확인하는 비트연산
bool UMyFFTComponent::IsPowerOfTwo(int32 x)
{
    return x > 0 && (x & (x - 1)) == 0;
}

// x보다 크거나 같은 2의 거듭제곱 중 가장 작은 값 리턴
int32 UMyFFTComponent::NextPowerOfTwo(int32 x)
{
    if (x <= 0)     
        return 1; // 0 이하이면 무조건 1 리턴
    if (IsPowerOfTwo(x)) 
        return x; // 이미 2의 거듭제곱이면 그대로 리턴

    x--;

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return x + 1; // 1 더해서 다음 2의 거듭제곱 반환

}


void UMyFFTComponent::FFT_CooleyTukey(TArray<FSimpleComplex>& X, int32 N, bool InverseFFT)
{

    //입력 데이터를 비트 반전 순서로 재정렬
    // 재정렬 해야만 알고리즘(버터플라이연산)이 작동한다.
    BitReversalPermutation(X, N);

    //버터플라이 연산
    for (int32 s = 1; s <= FMath::Log2(float(N)); ++s)
    {
        int32 m = 1 < s;
        int32 m2 = m >> 1;

        //회전 인자 계산
        float angle = 2.0f * PI / m;
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
    if (InverseFFT)
    {
        for (int32 i = 0; i < N; ++i)
        {
            X[i] = X[i] / float(N);
        }
    }

}




int32 UMyFFTComponent::BitReverse(int32 Index, int32 N)     //비트반전
{
    int32 numBits = FMath::Log2(float(N));
    int32 reversed = 0;
    for (int32 i = 0; i < numBits; ++i)
    {
        reversed = (reversed << 1) | (Index & 1);
        Index >>=1;
    }
    return reversed;
}

void UMyFFTComponent::BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N)    // 비트 반전된 인덱스 순서로 재배치
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
	






