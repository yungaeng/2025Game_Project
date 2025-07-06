
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FFT1DComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GAMEPROJECT_BP_API UFFT1DComponent : public UActorComponent
{
    GENERATED_BODY()

    public:
   
    struct FSimpleComplex
    {
        float Real;  //실수 부분

        float Imag; //허수 부분


        //생성자
        FSimpleComplex() : Real(0.0f), Imag(0.0f) {}
        FSimpleComplex(float InReal, float InImag) : Real(InReal), Imag(InImag) {}


        // 복소수 계산 연산자 오버로딩

       //1. 복소수 덧셈
       //(a+bi)+(c+di)=(a+c)+(b+d)i
        FSimpleComplex operator+(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(Real + Other.Real, Imag + Other.Imag);
        }


       
        //2. 복소수 뺄셈
        // (a+bi)-(c+di)=(a-c)+(b-d)i 
        FSimpleComplex operator-(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(Real - Other.Real, Imag - Other.Imag);
        }

        //3. 복소수 곱셈
        //(a + bi)*(c + di) = (ac-bd)+(ad + bc)i
        FSimpleComplex operator*(const FSimpleComplex& Other) const
        {
            return FSimpleComplex(
                Real * Other.Real - Imag * Other.Imag,
                Real * Other.Imag + Imag * Other.Real
            );
        }
       

        //4. 복소수 스칼라 나눗셈
        //a+bi)/k=(a/k)+(b/k)i
        FSimpleComplex operator/(float Scalar) const
        {
            return FSimpleComplex(Real / Scalar, Imag / Scalar);
        }

        //5. 켤레 복소수
        // Conj(a+bi)=a-bi
        FSimpleComplex Conjugate() const
        {
            return FSimpleComplex(Real, -Imag);
        }

        //6. 크기 절댓값으로

        float Magnitude() const
        {
            return FMath::Sqrt(Real * Real + Imag * Imag);
        }
    };

public:
    UFFT1DComponent();

    virtual void BeginPlay() override;

    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

    //신호(실수) -> 주파수(복소수)
    UFUNCTION(BlueprintCallable, Category = "Signal Processing")
    bool PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData);

    //주파수-> 신호
    UFUNCTION(BlueprintCallable, Category = "Signal Processing")
    bool PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData);

    // 2의 제곱인지 확인
    UFUNCTION(BlueprintPure, Category = "Signal Processing")
    static bool IsPowerOfTwo(int32 x);

    // 크거나 같은 제곱 반환
    UFUNCTION(BlueprintPure, Category = "Signal Processing")
    static int32 NextPowerOfTwo(int32 x);

private:

    void FFT_CooleyTukey(TArray<FSimpleComplex>& X, int32 N, bool InverseFFT);
    void BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N);
    int32 BitReverse(int32 Index, int32 N);
};