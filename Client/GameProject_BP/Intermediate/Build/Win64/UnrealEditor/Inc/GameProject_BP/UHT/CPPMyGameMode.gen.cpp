// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPPMyGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPPMyGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPPMyGameMode();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPPMyGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	void ACPPMyGameMode::StaticRegisterNativesACPPMyGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPPMyGameMode);
	UClass* Z_Construct_UClass_ACPPMyGameMode_NoRegister()
	{
		return ACPPMyGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ACPPMyGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPPMyGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "CPPMyGameMode.h" },
		{ "ModuleRelativePath", "Public/CPPMyGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPPMyGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPPMyGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPPMyGameMode_Statics::ClassParams = {
		&ACPPMyGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPPMyGameMode_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_ACPPMyGameMode()
	{
		if (!Z_Registration_Info_UClass_ACPPMyGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPPMyGameMode.OuterSingleton, Z_Construct_UClass_ACPPMyGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPPMyGameMode.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPPMyGameMode>()
	{
		return ACPPMyGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPPMyGameMode);
	ACPPMyGameMode::~ACPPMyGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPPMyGameMode, ACPPMyGameMode::StaticClass, TEXT("ACPPMyGameMode"), &Z_Registration_Info_UClass_ACPPMyGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPPMyGameMode), 387021589U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyGameMode_h_580153015(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
