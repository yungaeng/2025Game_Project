// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/MyFFTComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyFFTComponent() {}
// Cross Module References
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UMyFFTComponent();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UMyFFTComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(UMyFFTComponent::execNextPowerOfTwo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(int32*)Z_Param__Result=UMyFFTComponent::NextPowerOfTwo(Z_Param_x);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyFFTComponent::execIsPowerOfTwo)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=UMyFFTComponent::IsPowerOfTwo(Z_Param_x);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyFFTComponent::execPerformInverseFFT)
	{
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_InputData);
		P_GET_TARRAY_REF(float,Z_Param_Out_OutputData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PerformInverseFFT(Z_Param_Out_InputData,Z_Param_Out_OutputData);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UMyFFTComponent::execPerformForwardFFT)
	{
		P_GET_TARRAY_REF(float,Z_Param_Out_InputData);
		P_GET_TARRAY_REF(FVector2D,Z_Param_Out_OutputData);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->PerformForwardFFT(Z_Param_Out_InputData,Z_Param_Out_OutputData);
		P_NATIVE_END;
	}
	void UMyFFTComponent::StaticRegisterNativesUMyFFTComponent()
	{
		UClass* Class = UMyFFTComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "IsPowerOfTwo", &UMyFFTComponent::execIsPowerOfTwo },
			{ "NextPowerOfTwo", &UMyFFTComponent::execNextPowerOfTwo },
			{ "PerformForwardFFT", &UMyFFTComponent::execPerformForwardFFT },
			{ "PerformInverseFFT", &UMyFFTComponent::execPerformInverseFFT },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics
	{
		struct MyFFTComponent_eventIsPowerOfTwo_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventIsPowerOfTwo_Parms, x), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyFFTComponent_eventIsPowerOfTwo_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyFFTComponent_eventIsPowerOfTwo_Parms), &Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// x\xea\xb0\x80 2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1\xec\x9d\xb8\xec\xa7\x80 \xec\xb2\xb4\xed\x81\xac \n" },
#endif
		{ "ModuleRelativePath", "Public/MyFFTComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "x\xea\xb0\x80 2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1\xec\x9d\xb8\xec\xa7\x80 \xec\xb2\xb4\xed\x81\xac" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyFFTComponent, nullptr, "IsPowerOfTwo", nullptr, nullptr, Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::MyFFTComponent_eventIsPowerOfTwo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::MyFFTComponent_eventIsPowerOfTwo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics
	{
		struct MyFFTComponent_eventNextPowerOfTwo_Parms
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
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventNextPowerOfTwo_Parms, x), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventNextPowerOfTwo_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::NewProp_x,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// x\xeb\xb3\xb4\xeb\x8b\xa4 \xed\x81\xac\xea\xb1\xb0\xeb\x82\x98 \xea\xb0\x99\xec\x9d\x80 2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1 \xec\xa4\x91 \xea\xb0\x80\xec\x9e\xa5 \xec\x9e\x91\xec\x9d\x80 \xea\xb0\x92 \xeb\xa6\xac\xed\x84\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/MyFFTComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "x\xeb\xb3\xb4\xeb\x8b\xa4 \xed\x81\xac\xea\xb1\xb0\xeb\x82\x98 \xea\xb0\x99\xec\x9d\x80 2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1 \xec\xa4\x91 \xea\xb0\x80\xec\x9e\xa5 \xec\x9e\x91\xec\x9d\x80 \xea\xb0\x92 \xeb\xa6\xac\xed\x84\xb4" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyFFTComponent, nullptr, "NextPowerOfTwo", nullptr, nullptr, Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::MyFFTComponent_eventNextPowerOfTwo_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::MyFFTComponent_eventNextPowerOfTwo_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics
	{
		struct MyFFTComponent_eventPerformForwardFFT_Parms
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
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData_Inner = { "InputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData = { "InputData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventPerformForwardFFT_Parms, InputData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData), Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData_MetaData) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_OutputData_Inner = { "OutputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_OutputData = { "OutputData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventPerformForwardFFT_Parms, OutputData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyFFTComponent_eventPerformForwardFFT_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyFFTComponent_eventPerformForwardFFT_Parms), &Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_InputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_OutputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_OutputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
		{ "ModuleRelativePath", "Public/MyFFTComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyFFTComponent, nullptr, "PerformForwardFFT", nullptr, nullptr, Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::MyFFTComponent_eventPerformForwardFFT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::MyFFTComponent_eventPerformForwardFFT_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics
	{
		struct MyFFTComponent_eventPerformInverseFFT_Parms
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
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData_Inner = { "InputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData = { "InputData", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventPerformInverseFFT_Parms, InputData), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData), Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_OutputData_Inner = { "OutputData", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_OutputData = { "OutputData", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MyFFTComponent_eventPerformInverseFFT_Parms, OutputData), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MyFFTComponent_eventPerformInverseFFT_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MyFFTComponent_eventPerformInverseFFT_Parms), &Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_InputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_OutputData_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_OutputData,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::Function_MetaDataParams[] = {
		{ "Category", "Signal Processing" },
		{ "ModuleRelativePath", "Public/MyFFTComponent.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UMyFFTComponent, nullptr, "PerformInverseFFT", nullptr, nullptr, Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::PropPointers), sizeof(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::MyFFTComponent_eventPerformInverseFFT_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::Function_MetaDataParams), Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::MyFFTComponent_eventPerformInverseFFT_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UMyFFTComponent);
	UClass* Z_Construct_UClass_UMyFFTComponent_NoRegister()
	{
		return UMyFFTComponent::StaticClass();
	}
	struct Z_Construct_UClass_UMyFFTComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UMyFFTComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyFFTComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UMyFFTComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UMyFFTComponent_IsPowerOfTwo, "IsPowerOfTwo" }, // 1749241909
		{ &Z_Construct_UFunction_UMyFFTComponent_NextPowerOfTwo, "NextPowerOfTwo" }, // 4173270122
		{ &Z_Construct_UFunction_UMyFFTComponent_PerformForwardFFT, "PerformForwardFFT" }, // 913046684
		{ &Z_Construct_UFunction_UMyFFTComponent_PerformInverseFFT, "PerformInverseFFT" }, // 368470769
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UMyFFTComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UMyFFTComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "MyFFTComponent.h" },
		{ "ModuleRelativePath", "Public/MyFFTComponent.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UMyFFTComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UMyFFTComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UMyFFTComponent_Statics::ClassParams = {
		&UMyFFTComponent::StaticClass,
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
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UMyFFTComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UMyFFTComponent_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_UMyFFTComponent()
	{
		if (!Z_Registration_Info_UClass_UMyFFTComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UMyFFTComponent.OuterSingleton, Z_Construct_UClass_UMyFFTComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UMyFFTComponent.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<UMyFFTComponent>()
	{
		return UMyFFTComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UMyFFTComponent);
	UMyFFTComponent::~UMyFFTComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_MyFFTComponent_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_MyFFTComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UMyFFTComponent, UMyFFTComponent::StaticClass, TEXT("UMyFFTComponent"), &Z_Registration_Info_UClass_UMyFFTComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UMyFFTComponent), 813793081U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_MyFFTComponent_h_2745881800(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_MyFFTComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_MyFFTComponent_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
