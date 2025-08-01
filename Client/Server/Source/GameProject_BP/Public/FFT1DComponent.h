// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FFT1DComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_BP_API UFFT1DComponent : public UActorComponent
{
    GENERATED_BODY()

    public:
    /**
     * 간단한 복소수 클래스
     * Chaos 라이브러리의 FComplex를 사용하지 않고 직접 구현한 가벼운 복소수 클래스
     */
    struct FSimpleComplex
    {
        float Real;
        float Imag;

        // 생성자
        FSimpleComplex() : Real(0.0f), Imag(0.0f) {}
        FSimpleComplex(float InReal, float InImag) : Real(InReal), Imag(InImag) {}

        // 복소수 덧셈
        FSimpleComplex operator+(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(Real + Other.Real, Imag + Other.Imag);
        }

        // 복소수 뺄셈
        FSimpleComplex operator-(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(Real - Other.Real, Imag - Other.Imag);
        }

        // 복소수 곱셈 (a+bi)(c+di) = (ac-bd) + (ad+bc)i
        FSimpleComplex operator*(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(
                Real * Other.Real - Imag * Other.Imag,
                Real * Other.Imag + Imag * Other.Real
            );
        }

        // 스칼라 나눗셈
        FSimpleComplex operator/(float Scalar) const
        {
            return FSimpleComplex(Real / Scalar, Imag / Scalar);
        }

        // 켤레 복소수 반환
        FSimpleComplex Conjugate() const
        {
            return FSimpleComplex(Real, -Imag);
        }

        // 복소수의 크기(magnitude) 계산
        float Magnitude() const
        {
            return FMath::Sqrt(Real * Real + Imag * Imag);
        }
    };

public:
    // Sets default values for this component's properties
    UFFT1DComponent();

    // Called when the game starts
    virtual void BeginPlay() override;

    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    /**
     * Performs a Forward FFT on the input data
     * @param InputData - The input data (must have a length that is a power of 2)
     * @param OutputData - The output data (complex values)
     * @return True if successful, false otherwise
     */
    UFUNCTION(BlueprintCallable, Category = "Signal Processing")
    bool PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData);

    /**
     * Performs an Inverse FFT on the input data
     * @param InputData - The input data (complex values)
     * @param OutputData - The output data (real values)
     * @return True if successful, false otherwise
     */
    UFUNCTION(BlueprintCallable, Category = "Signal Processing")
    bool PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData);

    /**
     * Checks if a number is a power of 2
     * @param x - The number to check
     * @return True if x is a power of 2, false otherwise
     */
    UFUNCTION(BlueprintPure, Category = "Signal Processing")
    static bool IsPowerOfTwo(int32 x);

    /**
     * Gets the next power of 2 that is greater than or equal to x
     * @param x - The number to start from
     * @return The next power of 2
     */
    UFUNCTION(BlueprintPure, Category = "Signal Processing")
    static int32 NextPowerOfTwo(int32 x);

private:
    /**
     * Recursive implementation of the Cooley-Tukey FFT algorithm
     * @param X - Complex data array
     * @param N - Size of the array (must be a power of 2)
     * @param InverseFFT - Whether to perform an inverse FFT
     */
    void FFT_CooleyTukey(TArray<FSimpleComplex>& X, int32 N, bool InverseFFT);

    /**
     * Bit-reversal permutation (in-place)
     * @param X - Complex data array
     * @param N - Size of the array (must be a power of 2)
     */
    void BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N);

    /**
     * Converts a bit-reversed index to a normal index
     * @param Index - The bit-reversed index
     * @param N - The size of the array
     * @return The normal index
     */
    int32 BitReverse(int32 Index, int32 N);
};