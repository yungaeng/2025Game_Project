// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/FFT1DComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFFT1DComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UFFT1DComponent();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UFFT1DComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(UFFT1DComponent::execNextPowerOfTwo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UFFT1DComponent::NextPowerOfTwo(Z_Param_x);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFFT1DComponent::execIsPowerOfTwo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UFFT1DComponent::IsPowerOfTwo(Z_Param_x);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFFT1DComponent::execPerformInverseFFT)
	{
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_InputData);
		P_GET_TARRAY_REF(float,Z_Param_Out_OutputData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PerformInverseFFT(Z_Param_Out_InputData,Z_Param_Out_OutputData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UFFT1DComponent::execPerformForwardFFT)
	{
		P_GET_TARRAY_REF(float,Z_Param_Out_InputData);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_OutputData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PerformForwardFFT(Z_Param_Out_InputData,Z_Param_Out_OutputData);
		P_NATIVE_END;
	}
	void UFFT1DComponent::StaticRegisterNativesUFFT1DComponent()
	{
		UClass* Class = UFFT1DComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsPowerOfTwo", &UFFT1DComponent::execIsPowerOfTwo },
			{ "NextPowerOfTwo", &UFFT1DComponent::execNextPowerOfTwo },
			{ "PerformForwardFFT", &UFFT1DComponent::execPerformForwardFFT },
			{ "PerformInverseFFT", &UFFT1DComponent::execPerformInverseFFT },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics
	{
		struct FFT1DComponent_eventIsPowerOfTwo_Parms
		{
			int32 x;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_x;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventIsPowerOfTwo_Parms, x), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FFT1DComponent_eventIsPowerOfTwo_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFT1DComponent_eventIsPowerOfTwo_Parms), &Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Checks if a number is a power of 2\n     * @param x - The number to check\n     * @return True if x is a power of 2, false otherwise\n     */" },
#endif
		{ "ModuleRelativePath", "Public/FFT1DComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Checks if a number is a power of 2\n@param x - The number to check\n@return True if x is a power of 2, false otherwise" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFFT1DComponent, nullptr, "IsPowerOfTwo", nullptr, nullptr, Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::FFT1DComponent_eventIsPowerOfTwo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::FFT1DComponent_eventIsPowerOfTwo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics
	{
		struct FFT1DComponent_eventNextPowerOfTwo_Parms
		{
			int32 x;
			int32 ReturnValue;
		};
		static const UECodeGen_Private::FIntPropertyParams NewProp_x;
		static const UECodeGen_Private::FIntPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventNextPowerOfTwo_Parms, x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventNextPowerOfTwo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Gets the next power of 2 that is greater than or equal to x\n     * @param x - The number to start from\n     * @return The next power of 2\n     */" },
#endif
		{ "ModuleRelativePath", "Public/FFT1DComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Gets the next power of 2 that is greater than or equal to x\n@param x - The number to start from\n@return The next power of 2" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFFT1DComponent, nullptr, "NextPowerOfTwo", nullptr, nullptr, Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::FFT1DComponent_eventNextPowerOfTwo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::FFT1DComponent_eventNextPowerOfTwo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics
	{
		struct FFT1DComponent_eventPerformForwardFFT_Parms
		{
			TArray<float> InputData;
			TArray<FVector2D> OutputData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_InputData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InputData;
		static const UECodeGen_Private::FStructPropertyParams NewProp_OutputData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutputData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData_Inner = { "InputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData = { "InputData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventPerformForwardFFT_Parms, InputData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData), Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_OutputData_Inner = { "OutputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_OutputData = { "OutputData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventPerformForwardFFT_Parms, OutputData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FFT1DComponent_eventPerformForwardFFT_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFT1DComponent_eventPerformForwardFFT_Parms), &Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_InputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_OutputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_OutputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Performs a Forward FFT on the input data\n     * @param InputData - The input data (must have a length that is a power of 2)\n     * @param OutputData - The output data (complex values)\n     * @return True if successful, false otherwise\n     */" },
#endif
		{ "ModuleRelativePath", "Public/FFT1DComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performs a Forward FFT on the input data\n@param InputData - The input data (must have a length that is a power of 2)\n@param OutputData - The output data (complex values)\n@return True if successful, false otherwise" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFFT1DComponent, nullptr, "PerformForwardFFT", nullptr, nullptr, Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::FFT1DComponent_eventPerformForwardFFT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::FFT1DComponent_eventPerformForwardFFT_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics
	{
		struct FFT1DComponent_eventPerformInverseFFT_Parms
		{
			TArray<FVector2D> InputData;
			TArray<float> OutputData;
			bool ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_InputData_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_InputData_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_InputData;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_OutputData_Inner;
		static const UECodeGen_Private::FArrayPropertyParams NewProp_OutputData;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData_Inner = { "InputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData = { "InputData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventPerformInverseFFT_Parms, InputData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData), Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_OutputData_Inner = { "OutputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_OutputData = { "OutputData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FFT1DComponent_eventPerformInverseFFT_Parms, OutputData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((FFT1DComponent_eventPerformInverseFFT_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FFT1DComponent_eventPerformInverseFFT_Parms), &Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_InputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_OutputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_OutputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n     * Performs an Inverse FFT on the input data\n     * @param InputData - The input data (complex values)\n     * @param OutputData - The output data (real values)\n     * @return True if successful, false otherwise\n     */" },
#endif
		{ "ModuleRelativePath", "Public/FFT1DComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Performs an Inverse FFT on the input data\n@param InputData - The input data (complex values)\n@param OutputData - The output data (real values)\n@return True if successful, false otherwise" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UFFT1DComponent, nullptr, "PerformInverseFFT", nullptr, nullptr, Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::PropPointers), sizeof(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::FFT1DComponent_eventPerformInverseFFT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::Function_MetaDataParams), Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::FFT1DComponent_eventPerformInverseFFT_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UFFT1DComponent);
	UClass* Z_Construct_UClass_UFFT1DComponent_NoRegister()
	{
		return UFFT1DComponent::StaticClass();
	}
	struct Z_Construct_UClass_UFFT1DComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UFFT1DComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFFT1DComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UFFT1DComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UFFT1DComponent_IsPowerOfTwo, "IsPowerOfTwo" }, // 1159068754
		{ &Z_Construct_UFunction_UFFT1DComponent_NextPowerOfTwo, "NextPowerOfTwo" }, // 2548702226
		{ &Z_Construct_UFunction_UFFT1DComponent_PerformForwardFFT, "PerformForwardFFT" }, // 323447092
		{ &Z_Construct_UFunction_UFFT1DComponent_PerformInverseFFT, "PerformInverseFFT" }, // 3941869461
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UFFT1DComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UFFT1DComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "FFT1DComponent.h" },
		{ "ModuleRelativePath", "Public/FFT1DComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UFFT1DComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UFFT1DComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UFFT1DComponent_Statics::ClassParams = {
		&UFFT1DComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UFFT1DComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UFFT1DComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UFFT1DComponent()
	{
		if (!Z_Registration_Info_UClass_UFFT1DComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UFFT1DComponent.OuterSingleton, Z_Construct_UClass_UFFT1DComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UFFT1DComponent.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<UFFT1DComponent>()
	{
		return UFFT1DComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UFFT1DComponent);
	UFFT1DComponent::~UFFT1DComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_FFT1DComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_FFT1DComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UFFT1DComponent, UFFT1DComponent::StaticClass, TEXT("UFFT1DComponent"), &Z_Registration_Info_UClass_UFFT1DComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UFFT1DComponent), 4192462683U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_FFT1DComponent_h_105893799(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_FFT1DComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_FFT1DComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
