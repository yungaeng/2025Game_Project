// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyFFTComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAMEPROJECT_BP_API UMyFFTComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:

	// 복소수 클래스
	struct FSimpleComplex
	{
		float Real; // 실수부
		float Imag; // 허수부

		//생성자
		FSimpleComplex() : Real(0.0f), Imag(0.0f) {}
		FSimpleComplex(float InReal, float InImag) :Real(InReal), Imag(InImag) {}

		// 복소수 덧셈
		FSimpleComplex operator+(const FSimpleComplex& Other) const
		{
			return FSimpleComplex(Real + Other.Real, Imag + Other.Imag);
		}

		//복소수 뺄셈
		FSimpleComplex operator-(const FSimpleComplex& Other) const
		{
			return FSimpleComplex(Real - Other.Real, Imag - Other.Imag);
		}

		// 복소수 곱셈(a + bi)(c + di) = (ac - bd) + (ad + bc)i
		FSimpleComplex operator*(const FSimpleComplex & Other) const
		{
			return FSimpleComplex(
				Real * Other.Real - Imag * Other.Imag,
				Real * Other.Imag + Imag * Other.Real
			);
		}

		//스칼라 나눗셈
		FSimpleComplex operator/(float Scalar) const
		{
			return FSimpleComplex(Real / Scalar, Imag / Scalar);
		}

		//켤레 복소수
		FSimpleComplex Conjugate() const
		{
			return FSimpleComplex(Real, -Imag);
		}

		

		// 복소수 크기
		float Magnitude() const
		{
			return FMath::Sqrt(Real * Real + Imag * Imag);
		}

	};

public:

	//생성자 (컴포넌트 기본값 세팅)
	UMyFFTComponent();
	
	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;





	UFUNCTION(BlueprintCallable, Category = "Signal Processing")
	bool PerformForwardFFT(const TArray<float>& InputData, TArray<FVector2D>& OutputData);

	UFUNCTION(BlueprintCallable, Category = "Signal Processing")
	bool PerformInverseFFT(const TArray<FVector2D>& InputData, TArray<float>& OutputData);





	// x가 2의 거듭제곱인지 체크 
	UFUNCTION(BlueprintPure, Category = "Signal Processing")
	static bool IsPowerOfTwo(int32 x);

	// x보다 크거나 같은 2의 거듭제곱 중 가장 작은 값 리턴
	UFUNCTION(BlueprintPure, Category = "Signal Processing")
	static int32 NextPowerOfTwo(int32 x);








private:
	
	// Cooley-Tukey FFT 알고리즘
	void FFT_CooleyTukey(TArray<FSimpleComplex>& X, int32 N, bool InverseFFT);
	
	// 입력 데이터를 비트 반전 순서로 재정렬
	void BitReversalPermutation(TArray<FSimpleComplex>& X, int32 N);


	int32 BitReverse(int32 Index, int32 N);
	

	
		
};
