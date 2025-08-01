// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPP_Computer.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Computer() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Computer();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Computer_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UWidgetComponent_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(ACPP_Computer::execCreateRandomNumbers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateRandomNumbers();
		P_NATIVE_END;
	}
	void ACPP_Computer::StaticRegisterNativesACPP_Computer()
	{
		UClass* Class = ACPP_Computer::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateRandomNumbers", &ACPP_Computer::execCreateRandomNumbers },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACPP_Computer, nullptr, "CreateRandomNumbers", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics::Function_MetaDataParams), Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Computer);
	UClass* Z_Construct_UClass_ACPP_Computer_NoRegister()
	{
		return ACPP_Computer::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_Computer_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComponent;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ComputerWidget_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ComputerWidget;
		static const UECodeGen_Private::FIntPropertyParams NewProp_RandomDigits_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_RandomDigits_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_RandomDigits;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_AnswerActorClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_AnswerActorClass;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_SoundAnalyzerTag_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_SoundAnalyzerTag;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_Computer_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_ACPP_Computer_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACPP_Computer_CreateRandomNumbers, "CreateRandomNumbers" }, // 1888382818
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Computer.h" },
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::NewProp_MeshComponent_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_MeshComponent = { "MeshComponent", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Computer, MeshComponent), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::NewProp_MeshComponent_MetaData), Z_Construct_UClass_ACPP_Computer_Statics::NewProp_MeshComponent_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::NewProp_ComputerWidget_MetaData[] = {
		{ "Category", "UI" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_ComputerWidget = { "ComputerWidget", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Computer, ComputerWidget), Z_Construct_UClass_UWidgetComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::NewProp_ComputerWidget_MetaData), Z_Construct_UClass_ACPP_Computer_Statics::NewProp_ComputerWidget_MetaData) };
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits_Inner = { "RandomDigits", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits_MetaData[] = {
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits = { "RandomDigits", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Computer, RandomDigits), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits_MetaData), Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::NewProp_AnswerActorClass_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_AnswerActorClass = { "AnswerActorClass", nullptr, (EPropertyFlags)0x0014000000000001, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Computer, AnswerActorClass), Z_Construct_UClass_UClass, Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::NewProp_AnswerActorClass_MetaData), Z_Construct_UClass_ACPP_Computer_Statics::NewProp_AnswerActorClass_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer_Statics::NewProp_SoundAnalyzerTag_MetaData[] = {
		{ "Category", "Config" },
		{ "ModuleRelativePath", "Public/CPP_Computer.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_ACPP_Computer_Statics::NewProp_SoundAnalyzerTag = { "SoundAnalyzerTag", nullptr, (EPropertyFlags)0x0010000000010001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPP_Computer, SoundAnalyzerTag), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::NewProp_SoundAnalyzerTag_MetaData), Z_Construct_UClass_ACPP_Computer_Statics::NewProp_SoundAnalyzerTag_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPP_Computer_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_MeshComponent,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_ComputerWidget,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_RandomDigits,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_AnswerActorClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPP_Computer_Statics::NewProp_SoundAnalyzerTag,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_Computer_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Computer>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Computer_Statics::ClassParams = {
		&ACPP_Computer::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACPP_Computer_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Computer_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACPP_Computer()
	{
		if (!Z_Registration_Info_UClass_ACPP_Computer.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Computer.OuterSingleton, Z_Construct_UClass_ACPP_Computer_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPP_Computer.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPP_Computer>()
	{
		return ACPP_Computer::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Computer);
	ACPP_Computer::~ACPP_Computer() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Computer, ACPP_Computer::StaticClass, TEXT("ACPP_Computer"), &Z_Registration_Info_UClass_ACPP_Computer, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Computer), 1552117444U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer_h_1614638162(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
