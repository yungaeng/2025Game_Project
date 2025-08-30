// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPP_ToolCollecter.h"
#include "../../Source/Runtime/Engine/Classes/Engine/HitResult.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_ToolCollecter() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_ToolCollecter();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_ToolCollecter_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(ACPP_ToolCollecter::execOnOverlapEnd)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapEnd(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACPP_ToolCollecter::execOnOverlapBegin)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnOverlapBegin(Z_Param_OverlappedComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACPP_ToolCollecter::execUpdateCollectorCount)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateCollectorCount();
		P_NATIVE_END;
	}
	struct CPP_ToolCollecter_eventBP_UpdateWidget_Parms
	{
		int32 CollectedCount;
		bool bMissionComplete;
	};
	static FName NAME_ACPP_ToolCollecter_BP_UpdateWidget = FName(TEXT("BP_UpdateWidget"));
	void ACPP_ToolCollecter::BP_UpdateWidget(int32 CollectedCount, bool bMissionComplete)
	{
		CPP_ToolCollecter_eventBP_UpdateWidget_Parms Parms;
		Parms.CollectedCount=CollectedCount;
		Parms.bMissionComplete=bMissionComplete ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ACPP_ToolCollecter_BP_UpdateWidget),&Parms);
	}
	void ACPP_ToolCollecter::StaticRegisterNativesACPP_ToolCollecter()
	{
		UClass* Class = ACPP_ToolCollecter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnOverlapBegin", &ACPP_ToolCollecter::execOnOverlapBegin },
			{ "OnOverlapEnd", &ACPP_ToolCollecter::execOnOverlapEnd },
			{ "UpdateCollectorCount", &ACPP_ToolCollecter::execUpdateCollectorCount },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics
	{
		static const UECodeGen_Private::FIntPropertyParams NewProp_CollectedCount;
		static void NewProp_bMissionComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bMissionComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_CollectedCount = { "CollectedCount", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventBP_UpdateWidget_Parms, CollectedCount), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_bMissionComplete_SetBit(void* Obj)
	{
		((CPP_ToolCollecter_eventBP_UpdateWidget_Parms*)Obj)->bMissionComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_bMissionComplete = { "bMissionComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_ToolCollecter_eventBP_UpdateWidget_Parms), &Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_bMissionComplete_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_CollectedCount,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::NewProp_bMissionComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Collector" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Blueprint event to update widget visuals */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Blueprint event to update widget visuals" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_ToolCollecter, nullptr, "BP_UpdateWidget", nullptr, nullptr, Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::PropPointers), sizeof(CPP_ToolCollecter_eventBP_UpdateWidget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::PropPointers) < 2048);
	static_assert(sizeof(CPP_ToolCollecter_eventBP_UpdateWidget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics
	{
		struct CPP_ToolCollecter_eventOnOverlapBegin_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapBegin_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OverlappedComp_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapBegin_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapBegin_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherComp_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapBegin_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
	void Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((CPP_ToolCollecter_eventOnOverlapBegin_Parms*)Obj)->bFromSweep = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CPP_ToolCollecter_eventOnOverlapBegin_Parms), &Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapBegin_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_SweepResult_MetaData) }; // 1891709922
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OverlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_OtherBodyIndex,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_bFromSweep,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_ToolCollecter, nullptr, "OnOverlapBegin", nullptr, nullptr, Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::CPP_ToolCollecter_eventOnOverlapBegin_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00480401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::CPP_ToolCollecter_eventOnOverlapBegin_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics
	{
		struct CPP_ToolCollecter_eventOnOverlapEnd_Parms
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
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OverlappedComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OverlappedComp = { "OverlappedComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapEnd_Parms, OverlappedComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OverlappedComp_MetaData), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OverlappedComp_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapEnd_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapEnd_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherComp_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_ToolCollecter_eventOnOverlapEnd_Parms, OtherBodyIndex), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OverlappedComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherComp,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::NewProp_OtherBodyIndex,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_ToolCollecter, nullptr, "OnOverlapEnd", nullptr, nullptr, Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::PropPointers), sizeof(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::CPP_ToolCollecter_eventOnOverlapEnd_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::CPP_ToolCollecter_eventOnOverlapEnd_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics::Function_MetaDataParams[] = {
		{ "Category", "Collector" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** Increment and update the widget's collected tools count */" },
#endif
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Increment and update the widget's collected tools count" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_ToolCollecter, nullptr, "UpdateCollectorCount", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_ToolCollecter);
	UClass* Z_Construct_UClass_ACPP_ToolCollecter_NoRegister()
	{
		return ACPP_ToolCollecter::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_ToolCollecter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToolMesh_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolMesh;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CollisionBox_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CollisionBox;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ToolWidgetComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ToolWidgetComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompleteWidgetComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CompleteWidgetComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AdventurerBPClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AdventurerBPClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsThisMissionComplete_MetaData[];
#endif
		static void NewProp_IsThisMissionComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsThisMissionComplete;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IsOnCollector_MetaData[];
#endif
		static void NewProp_IsOnCollector_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_IsOnCollector;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_ToolCollecter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ACPP_ToolCollecter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_ToolCollecter_BP_UpdateWidget, "BP_UpdateWidget" }, // 3883875609
		{ &Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapBegin, "OnOverlapBegin" }, // 2813524298
		{ &Z_Construct_UFunction_ACPP_ToolCollecter_OnOverlapEnd, "OnOverlapEnd" }, // 668674557
		{ &Z_Construct_UFunction_ACPP_ToolCollecter_UpdateCollectorCount, "UpdateCollectorCount" }, // 1668967838
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_ToolCollecter.h" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolMesh_MetaData[] = {
		{ "Category", "Components" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// Components\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Components" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolMesh = { "ToolMesh", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_ToolCollecter, ToolMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolMesh_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolMesh_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CollisionBox_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CollisionBox = { "CollisionBox", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_ToolCollecter, CollisionBox), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CollisionBox_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CollisionBox_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolWidgetComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolWidgetComponent = { "ToolWidgetComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_ToolCollecter, ToolWidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolWidgetComponent_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolWidgetComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CompleteWidgetComponent_MetaData[] = {
		{ "Category", "Components" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CompleteWidgetComponent = { "CompleteWidgetComponent", nullptr, (EPropertyFlags)0x00200800000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_ToolCollecter, CompleteWidgetComponent), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CompleteWidgetComponent_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CompleteWidgetComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_AdventurerBPClass_MetaData[] = {
		{ "Category", "Collector" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_AdventurerBPClass = { "AdventurerBPClass", nullptr, (EPropertyFlags)0x0024080000010001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_ToolCollecter, AdventurerBPClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_AdventurerBPClass_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_AdventurerBPClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete_MetaData[] = {
		{ "Category", "Collector" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	void Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete_SetBit(void* Obj)
	{
		((ACPP_ToolCollecter*)Obj)->IsThisMissionComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete = { "IsThisMissionComplete", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_ToolCollecter), &Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector_MetaData[] = {
		{ "Category", "Collector" },
		{ "ModuleRelativePath", "Public/CPP_ToolCollecter.h" },
	};
#endif
	void Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector_SetBit(void* Obj)
	{
		((ACPP_ToolCollecter*)Obj)->IsOnCollector = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector = { "IsOnCollector", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(ACPP_ToolCollecter), &Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector_MetaData), Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_ToolCollecter_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolMesh,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CollisionBox,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_ToolWidgetComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_CompleteWidgetComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_AdventurerBPClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsThisMissionComplete,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_ToolCollecter_Statics::NewProp_IsOnCollector,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_ToolCollecter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_ToolCollecter>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_ToolCollecter_Statics::ClassParams = {
		&ACPP_ToolCollecter::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACPP_ToolCollecter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_ToolCollecter_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_ToolCollecter_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACPP_ToolCollecter()
	{
		if (!Z_Registration_Info_UClass_ACPP_ToolCollecter.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_ToolCollecter.OuterSingleton, Z_Construct_UClass_ACPP_ToolCollecter_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPP_ToolCollecter.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPP_ToolCollecter>()
	{
		return ACPP_ToolCollecter::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_ToolCollecter);
	ACPP_ToolCollecter::~ACPP_ToolCollecter() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_ToolCollecter_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_ToolCollecter_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_ToolCollecter, ACPP_ToolCollecter::StaticClass, TEXT("ACPP_ToolCollecter"), &Z_Registration_Info_UClass_ACPP_ToolCollecter, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_ToolCollecter), 1319730753U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_ToolCollecter_h_794413930(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_ToolCollecter_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_ToolCollecter_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
