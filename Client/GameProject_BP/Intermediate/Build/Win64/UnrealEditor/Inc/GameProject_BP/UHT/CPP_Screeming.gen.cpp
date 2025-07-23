// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPP_Screeming.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Screeming() {}
// Cross Module References
	AUDIOCAPTURE_API UClass* Z_Construct_UClass_UAudioCaptureComponent_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UAudioComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Screeming();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Screeming_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ASoundAnalyzerBase_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(ACPP_Screeming::execOnBoxEndOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnBoxEndOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACPP_Screeming::execOnBoxBeginOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnBoxBeginOverlap(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACPP_Screeming::execOnEnvelopeValue)
	{
		P_GET_OBJECT(UAudioComponent,Z_Param_AC);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Envelope);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnEnvelopeValue(Z_Param_AC,Z_Param_Envelope);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACPP_Screeming::execOnSoundAnalyzerCleared)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnSoundAnalyzerCleared();
		P_NATIVE_END;
	}
	void ACPP_Screeming::StaticRegisterNativesACPP_Screeming()
	{
		UClass* Class = ACPP_Screeming::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnBoxBeginOverlap", &ACPP_Screeming::execOnBoxBeginOverlap },
			{ "OnBoxEndOverlap", &ACPP_Screeming::execOnBoxEndOverlap },
			{ "OnEnvelopeValue", &ACPP_Screeming::execOnEnvelopeValue },
			{ "OnSoundAnalyzerCleared", &ACPP_Screeming::execOnSoundAnalyzerCleared },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics
	{
		struct CPP_Screeming_eventOnBoxBeginOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxBeginOverlap_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OverlappedComp_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OverlappedComp_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherComp_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherComp_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((CPP_Screeming_eventOnBoxBeginOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_Screeming_eventOnBoxBeginOverlap_Parms), &Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_SweepResult_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_SweepResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OverlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_OtherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Overlap ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Overlap =====" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Screeming, nullptr, "OnBoxBeginOverlap", nullptr, nullptr, Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::CPP_Screeming_eventOnBoxBeginOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::CPP_Screeming_eventOnBoxBeginOverlap_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics
	{
		struct CPP_Screeming_eventOnBoxEndOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OverlappedComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OverlappedComp;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UECodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxEndOverlap_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OverlappedComp_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OverlappedComp_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxEndOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxEndOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherComp_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherComp_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnBoxEndOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OverlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::NewProp_OtherBodyIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Screeming, nullptr, "OnBoxEndOverlap", nullptr, nullptr, Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::CPP_Screeming_eventOnBoxEndOverlap_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::CPP_Screeming_eventOnBoxEndOverlap_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics
	{
		struct CPP_Screeming_eventOnEnvelopeValue_Parms
		{
			const UAudioComponent* AC;
			float Envelope;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AC_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AC;
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Envelope;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_AC_MetaData[] = {
		{ "EditInline", "true" },
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_AC = { "AC", nullptr, (EPropertyFlags)0x0010000000080082, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnEnvelopeValue_Parms, AC), Z_Construct_UClass_UAudioComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_AC_MetaData), Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_AC_MetaData) };
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_Envelope = { "Envelope", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_Screeming_eventOnEnvelopeValue_Parms, Envelope), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_AC,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::NewProp_Envelope,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Envelope ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Envelope =====" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Screeming, nullptr, "OnEnvelopeValue", nullptr, nullptr, Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::CPP_Screeming_eventOnEnvelopeValue_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::CPP_Screeming_eventOnEnvelopeValue_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Screeming, nullptr, "OnSoundAnalyzerCleared", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Screeming);
	UClass* Z_Construct_UClass_ACPP_Screeming_NoRegister()
	{
		return ACPP_Screeming::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_Screeming_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsStart_MetaData[];
#endif
		static void NewProp_bIsStart_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsStart;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bAnalyzerCleared_MetaData[];
#endif
		static void NewProp_bAnalyzerCleared_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bAnalyzerCleared;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bMissionComplete_MetaData[];
#endif
		static void NewProp_bMissionComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bMissionComplete;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bPlayerInside_MetaData[];
#endif
		static void NewProp_bPlayerInside_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayerInside;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_HowLoud_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_HowLoud;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LoudThreshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_LoudThreshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MaxTime_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_MaxTime;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ClearTimeLimit_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_ClearTimeLimit;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bFirstClear_MetaData[];
#endif
		static void NewProp_bFirstClear_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bFirstClear;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdventurerClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AdventurerClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_EchoGenerateClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_EchoGenerateClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ProgressWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_ProgressWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompleteWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_CompleteWidgetClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SoundAnalyzer_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_SoundAnalyzer;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ScreemingWidgetInstance_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ScreemingWidgetInstance;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Root_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Root;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AudioCapture_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_AudioCapture;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_StaticMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_StaticMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Widget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Widget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompleteWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CompleteWidget;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Box_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Box;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Imposter_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_Imposter;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ImposterCamera_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ImposterCamera;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_Screeming_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ACPP_Screeming_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Screeming_OnBoxBeginOverlap, "OnBoxBeginOverlap" }, // 799124654
		{ &Z_Construct_UFunction_ACPP_Screeming_OnBoxEndOverlap, "OnBoxEndOverlap" }, // 4166994323
		{ &Z_Construct_UFunction_ACPP_Screeming_OnEnvelopeValue, "OnEnvelopeValue" }, // 835010803
		{ &Z_Construct_UFunction_ACPP_Screeming_OnSoundAnalyzerCleared, "OnSoundAnalyzerCleared" }, // 3694083342
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Screeming.h" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== State ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== State =====" },
#endif
	};
#endif
	void Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart_SetBit(void* Obj)
	{
		((ACPP_Screeming*)Obj)->bIsStart = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart = { "bIsStart", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Screeming), &Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	void Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared_SetBit(void* Obj)
	{
		((ACPP_Screeming*)Obj)->bAnalyzerCleared = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared = { "bAnalyzerCleared", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Screeming), &Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete_MetaData[] = {
		{ "Category", "State" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BP_SoundAnalyzer Clear\n" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BP_SoundAnalyzer Clear" },
#endif
	};
#endif
	void Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete_SetBit(void* Obj)
	{
		((ACPP_Screeming*)Obj)->bMissionComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete = { "bMissionComplete", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Screeming), &Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside_MetaData[] = {
		{ "Category", "State" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	void Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside_SetBit(void* Obj)
	{
		((ACPP_Screeming*)Obj)->bPlayerInside = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside = { "bPlayerInside", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Screeming), &Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_HowLoud_MetaData[] = {
		{ "Category", "Screeming" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Adventurer overlap?\n" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Adventurer overlap?" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_HowLoud = { "HowLoud", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, HowLoud), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_HowLoud_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_HowLoud_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_LoudThreshold_MetaData[] = {
		{ "Category", "Screeming" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_LoudThreshold = { "LoudThreshold", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, LoudThreshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_LoudThreshold_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_LoudThreshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_MaxTime_MetaData[] = {
		{ "Category", "Screeming" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_MaxTime = { "MaxTime", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, MaxTime), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_MaxTime_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_MaxTime_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ClearTimeLimit_MetaData[] = {
		{ "Category", "Screeming" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ClearTimeLimit = { "ClearTimeLimit", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, ClearTimeLimit), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ClearTimeLimit_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ClearTimeLimit_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear_MetaData[] = {
		{ "Category", "Screeming" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	void Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear_SetBit(void* Obj)
	{
		((ACPP_Screeming*)Obj)->bFirstClear = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear = { "bFirstClear", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_Screeming), &Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AdventurerClass_MetaData[] = {
		{ "Category", "Screeming|Refs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Classes / Assets ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Classes / Assets =====" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AdventurerClass = { "AdventurerClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, AdventurerClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AdventurerClass_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AdventurerClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_EchoGenerateClass_MetaData[] = {
		{ "Category", "Screeming|Refs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BP_Adventurer\n" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BP_Adventurer" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_EchoGenerateClass = { "EchoGenerateClass", nullptr, (EPropertyFlags)0x0024080000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, EchoGenerateClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_EchoGenerateClass_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_EchoGenerateClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ProgressWidgetClass_MetaData[] = {
		{ "Category", "Screeming|Refs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// AEchoGenerate BP\n" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "AEchoGenerate BP" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ProgressWidgetClass = { "ProgressWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, ProgressWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ProgressWidgetClass_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ProgressWidgetClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidgetClass_MetaData[] = {
		{ "Category", "Screeming|Refs" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// /Game/MyMission/TogetherScreeming/W_ScreemingWidget\n" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "/Game/MyMission/TogetherScreeming/W_ScreemingWidget" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidgetClass = { "CompleteWidgetClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, CompleteWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidgetClass_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidgetClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_SoundAnalyzer_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Analyzer ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Analyzer =====" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_SoundAnalyzer = { "SoundAnalyzer", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, SoundAnalyzer), Z_Construct_UClass_ASoundAnalyzerBase_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_SoundAnalyzer_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_SoundAnalyzer_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ScreemingWidgetInstance_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Widgets ===== */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Widgets =====" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ScreemingWidgetInstance = { "ScreemingWidgetInstance", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, ScreemingWidgetInstance), Z_Construct_UClass_UUserWidget_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ScreemingWidgetInstance_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ScreemingWidgetInstance_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Root_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Components ===== */" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Components =====" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Root = { "Root", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, Root), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Root_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Root_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AudioCapture_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AudioCapture = { "AudioCapture", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, AudioCapture), Z_Construct_UClass_UAudioCaptureComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AudioCapture_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AudioCapture_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_StaticMesh_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_StaticMesh = { "StaticMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, StaticMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_StaticMesh_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_StaticMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Widget_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Widget = { "Widget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, Widget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Widget_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Widget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidget_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa7\x84\xed\x96\x89 \xec\x9c\x84\xec\xa0\xaf \xed\x91\x9c\xec\x8b\x9c\xec\x9a\xa9\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa7\x84\xed\x96\x89 \xec\x9c\x84\xec\xa0\xaf \xed\x91\x9c\xec\x8b\x9c\xec\x9a\xa9" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidget = { "CompleteWidget", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, CompleteWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidget_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidget_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Box_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x99\x84\xeb\xa3\x8c \xec\x9c\x84\xec\xa0\xaf \xed\x91\x9c\xec\x8b\x9c\xec\x9a\xa9\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x99\x84\xeb\xa3\x8c \xec\x9c\x84\xec\xa0\xaf \xed\x91\x9c\xec\x8b\x9c\xec\x9a\xa9" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Box = { "Box", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Box_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Box_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Imposter_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/* ===== Other Refs ===== */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "===== Other Refs =====" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Imposter = { "Imposter", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, Imposter), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Imposter_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Imposter_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ImposterCamera_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Screeming.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ImposterCamera = { "ImposterCamera", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Screeming, ImposterCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ImposterCamera_MetaData), Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ImposterCamera_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Screeming_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bIsStart,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bAnalyzerCleared,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bMissionComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bPlayerInside,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_HowLoud,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_LoudThreshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_MaxTime,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ClearTimeLimit,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_bFirstClear,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AdventurerClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_EchoGenerateClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ProgressWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_SoundAnalyzer,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ScreemingWidgetInstance,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Root,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_AudioCapture,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_StaticMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Widget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_CompleteWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Box,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_Imposter,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Screeming_Statics::NewProp_ImposterCamera,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_Screeming_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Screeming>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Screeming_Statics::ClassParams = {
		&ACPP_Screeming::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACPP_Screeming_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Screeming_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Screeming_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACPP_Screeming()
	{
		if (!Z_Registration_Info_UClass_ACPP_Screeming.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Screeming.OuterSingleton, Z_Construct_UClass_ACPP_Screeming_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPP_Screeming.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPP_Screeming>()
	{
		return ACPP_Screeming::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Screeming);
	ACPP_Screeming::~ACPP_Screeming() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Screeming_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Screeming_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Screeming, ACPP_Screeming::StaticClass, TEXT("ACPP_Screeming"), &Z_Registration_Info_UClass_ACPP_Screeming, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Screeming), 2933273506U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Screeming_h_3605829731(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Screeming_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Screeming_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
