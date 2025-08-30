// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/SoundAnalyzerBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSoundAnalyzerBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ASoundAnalyzerBase();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ASoundAnalyzerBase_NoRegister();
	GAMEPROJECT_BP_API UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BP\xec\x97\x90\xec\x84\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xeb\xa9\x80\xed\x8b\xb0\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Public/SoundAnalyzerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BP\xec\x97\x90\xec\x84\x9c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 \xeb\xa9\x80\xed\x8b\xb0\xec\xba\x90\xec\x8a\xa4\xed\x8a\xb8 \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GameProject_BP, nullptr, "OnSoundAnalyzerClear__DelegateSignature", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnSoundAnalyzerClear_DelegateWrapper(const FMulticastScriptDelegate& OnSoundAnalyzerClear)
{
	OnSoundAnalyzerClear.ProcessMulticastDelegate<UObject>(NULL);
}
	DEFINE_FUNCTION(ASoundAnalyzerBase::execBroadcastCleared)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BroadcastCleared();
		P_NATIVE_END;
	}
	void ASoundAnalyzerBase::StaticRegisterNativesASoundAnalyzerBase()
	{
		UClass* Class = ASoundAnalyzerBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BroadcastCleared", &ASoundAnalyzerBase::execBroadcastCleared },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics::Function_MetaDataParams[] = {
		{ "Category", "SoundAnalyzer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// C++\xec\x9d\xb4\xeb\x82\x98 BP\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\xed\x95\xa0 \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xed\x95\xa8\xec\x88\x98\n" },
#endif
		{ "ModuleRelativePath", "Public/SoundAnalyzerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "C++\xec\x9d\xb4\xeb\x82\x98 BP\xec\x97\x90\xec\x84\x9c \xed\x98\xb8\xec\xb6\x9c\xed\x95\xa0 \xed\x81\xb4\xeb\xa6\xac\xec\x96\xb4 \xed\x95\xa8\xec\x88\x98" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASoundAnalyzerBase, nullptr, "BroadcastCleared", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics::Function_MetaDataParams), Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ASoundAnalyzerBase);
	UClass* Z_Construct_UClass_ASoundAnalyzerBase_NoRegister()
	{
		return ASoundAnalyzerBase::StaticClass();
	}
	struct Z_Construct_UClass_ASoundAnalyzerBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnSoundAnalyzerClear_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnSoundAnalyzerClear;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASoundAnalyzerBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ASoundAnalyzerBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASoundAnalyzerBase_BroadcastCleared, "BroadcastCleared" }, // 3402976882
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoundAnalyzerBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "SoundAnalyzerBase.h" },
		{ "ModuleRelativePath", "Public/SoundAnalyzerBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASoundAnalyzerBase_Statics::NewProp_OnSoundAnalyzerClear_MetaData[] = {
		{ "Category", "SoundAnalyzer" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// BP\xec\x97\x90\xec\x84\x9c Bind Event \xeb\x85\xb8\xeb\x93\x9c\xeb\xa1\x9c \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xea\xb2\x8c UPROPERTY \xec\xa7\x80\xec\xa0\x95\n" },
#endif
		{ "ModuleRelativePath", "Public/SoundAnalyzerBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "BP\xec\x97\x90\xec\x84\x9c Bind Event \xeb\x85\xb8\xeb\x93\x9c\xeb\xa1\x9c \xeb\xb0\x94\xec\x9d\xb8\xeb\x94\xa9\xed\x95\xa0 \xec\x88\x98 \xec\x9e\x88\xea\xb2\x8c UPROPERTY \xec\xa7\x80\xec\xa0\x95" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ASoundAnalyzerBase_Statics::NewProp_OnSoundAnalyzerClear = { "OnSoundAnalyzerClear", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ASoundAnalyzerBase, OnSoundAnalyzerClear), Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::NewProp_OnSoundAnalyzerClear_MetaData), Z_Construct_UClass_ASoundAnalyzerBase_Statics::NewProp_OnSoundAnalyzerClear_MetaData) }; // 1598994314
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASoundAnalyzerBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASoundAnalyzerBase_Statics::NewProp_OnSoundAnalyzerClear,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASoundAnalyzerBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASoundAnalyzerBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ASoundAnalyzerBase_Statics::ClassParams = {
		&ASoundAnalyzerBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASoundAnalyzerBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::PropPointers),
		0,
		0x009000A5u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::Class_MetaDataParams), Z_Construct_UClass_ASoundAnalyzerBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ASoundAnalyzerBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ASoundAnalyzerBase()
	{
		if (!Z_Registration_Info_UClass_ASoundAnalyzerBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ASoundAnalyzerBase.OuterSingleton, Z_Construct_UClass_ASoundAnalyzerBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ASoundAnalyzerBase.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ASoundAnalyzerBase>()
	{
		return ASoundAnalyzerBase::StaticClass();
	}
	ASoundAnalyzerBase::ASoundAnalyzerBase(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASoundAnalyzerBase);
	ASoundAnalyzerBase::~ASoundAnalyzerBase() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_SoundAnalyzerBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_SoundAnalyzerBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ASoundAnalyzerBase, ASoundAnalyzerBase::StaticClass, TEXT("ASoundAnalyzerBase"), &Z_Registration_Info_UClass_ASoundAnalyzerBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ASoundAnalyzerBase), 1906712652U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_SoundAnalyzerBase_h_542861689(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_SoundAnalyzerBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_SoundAnalyzerBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
