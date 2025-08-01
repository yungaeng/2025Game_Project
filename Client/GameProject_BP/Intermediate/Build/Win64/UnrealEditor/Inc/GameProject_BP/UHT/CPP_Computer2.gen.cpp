// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPP_Computer2.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPP_Computer2() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Computer2();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPP_Computer2_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	void ACPP_Computer2::StaticRegisterNativesACPP_Computer2()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPP_Computer2);
	UClass* Z_Construct_UClass_ACPP_Computer2_NoRegister()
	{
		return ACPP_Computer2::StaticClass();
	}
	struct Z_Construct_UClass_ACPP_Computer2_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPP_Computer2_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer2_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPP_Computer2_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "CPP_Computer2.h" },
		{ "ModuleRelativePath", "Public/CPP_Computer2.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPP_Computer2_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPP_Computer2>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPP_Computer2_Statics::ClassParams = {
		&ACPP_Computer2::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPP_Computer2_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPP_Computer2_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ACPP_Computer2()
	{
		if (!Z_Registration_Info_UClass_ACPP_Computer2.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPP_Computer2.OuterSingleton, Z_Construct_UClass_ACPP_Computer2_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPP_Computer2.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPP_Computer2>()
	{
		return ACPP_Computer2::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPP_Computer2);
	ACPP_Computer2::~ACPP_Computer2() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer2_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer2_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPP_Computer2, ACPP_Computer2::StaticClass, TEXT("ACPP_Computer2"), &Z_Registration_Info_UClass_ACPP_Computer2, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPP_Computer2), 1637180909U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer2_h_3387004253(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer2_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPP_Computer2_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
