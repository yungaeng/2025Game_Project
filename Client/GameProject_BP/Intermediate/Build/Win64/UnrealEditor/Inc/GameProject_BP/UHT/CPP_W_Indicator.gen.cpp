// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPP_W_Indicator.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_W_Indicator() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UCPP_W_Indicator();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UCPP_W_Indicator_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UImage_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(UCPP_W_Indicator::execSetTarget)
	{
		P_GET_OBJECT(AActor,Z_Param_NewTarget);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetTarget(Z_Param_NewTarget);
		P_NATIVE_END;
	}
	void UCPP_W_Indicator::StaticRegisterNativesUCPP_W_Indicator()
	{
		UClass* Class = UCPP_W_Indicator::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetTarget", &UCPP_W_Indicator::execSetTarget },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics
	{
		struct CPP_W_Indicator_eventSetTarget_Parms
		{
			AActor* NewTarget;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_NewTarget;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::NewProp_NewTarget = { "NewTarget", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CPP_W_Indicator_eventSetTarget_Parms, NewTarget), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::NewProp_NewTarget,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::Function_MetaDataParams[] = {
		{ "Category", "Indicator" },
		{ "ModuleRelativePath", "Public/CPP_W_Indicator.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UCPP_W_Indicator, nullptr, "SetTarget", nullptr, nullptr, Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::PropPointers), sizeof(Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::CPP_W_Indicator_eventSetTarget_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::CPP_W_Indicator_eventSetTarget_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UCPP_W_Indicator_SetTarget()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCPP_W_Indicator_SetTarget_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCPP_W_Indicator);
	UClass* Z_Construct_UClass_UCPP_W_Indicator_NoRegister()
	{
		return UCPP_W_Indicator::StaticClass();
	}
	struct Z_Construct_UClass_UCPP_W_Indicator_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IndicatorIcon_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IndicatorIcon;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetActor;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UCPP_W_Indicator_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UCPP_W_Indicator_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UCPP_W_Indicator_SetTarget, "SetTarget" }, // 803983750
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCPP_W_Indicator_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_W_Indicator.h" },
		{ "ModuleRelativePath", "Public/CPP_W_Indicator.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_IndicatorIcon_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_W_Indicator.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_IndicatorIcon = { "IndicatorIcon", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCPP_W_Indicator, IndicatorIcon), Z_Construct_UClass_UImage_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_IndicatorIcon_MetaData), Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_IndicatorIcon_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_TargetActor_MetaData[] = {
		{ "ModuleRelativePath", "Public/CPP_W_Indicator.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0020080000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCPP_W_Indicator, TargetActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_TargetActor_MetaData), Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_TargetActor_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCPP_W_Indicator_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_IndicatorIcon,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCPP_W_Indicator_Statics::NewProp_TargetActor,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UCPP_W_Indicator_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCPP_W_Indicator>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UCPP_W_Indicator_Statics::ClassParams = {
		&UCPP_W_Indicator::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UCPP_W_Indicator_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::Class_MetaDataParams), Z_Construct_UClass_UCPP_W_Indicator_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCPP_W_Indicator_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UCPP_W_Indicator()
	{
		if (!Z_Registration_Info_UClass_UCPP_W_Indicator.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCPP_W_Indicator.OuterSingleton, Z_Construct_UClass_UCPP_W_Indicator_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UCPP_W_Indicator.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<UCPP_W_Indicator>()
	{
		return UCPP_W_Indicator::StaticClass();
	}
	UCPP_W_Indicator::UCPP_W_Indicator(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCPP_W_Indicator);
	UCPP_W_Indicator::~UCPP_W_Indicator() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_W_Indicator_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_W_Indicator_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UCPP_W_Indicator, UCPP_W_Indicator::StaticClass, TEXT("UCPP_W_Indicator"), &Z_Registration_Info_UClass_UCPP_W_Indicator, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCPP_W_Indicator), 2149265003U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_W_Indicator_h_3259462545(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_W_Indicator_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_W_Indicator_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
