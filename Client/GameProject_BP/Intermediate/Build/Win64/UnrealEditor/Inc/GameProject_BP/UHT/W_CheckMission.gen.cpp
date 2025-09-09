// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/W_CheckMission.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeW_CheckMission() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UW_CheckMission();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UW_CheckMission_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UCheckBox_NoRegister();
	UMG_API UClass* Z_Construct_UClass_UUserWidget();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	void UW_CheckMission::StaticRegisterNativesUW_CheckMission()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UW_CheckMission);
	UClass* Z_Construct_UClass_UW_CheckMission_NoRegister()
	{
		return UW_CheckMission::StaticClass();
	}
	struct Z_Construct_UClass_UW_CheckMission_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MissionActor_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MissionActor;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CompleteVarName_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_CompleteVarName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bCheckedWhenActorInvalid_MetaData[];
#endif
		static void NewProp_bCheckedWhenActorInvalid_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bCheckedWhenActorInvalid;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_CheckBox_Mission_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_CheckBox_Mission;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UW_CheckMission_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UUserWidget,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UW_CheckMission_Statics::Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * \xeb\x8b\xa8\xec\x9d\xbc \xeb\xaf\xb8\xec\x85\x98 \xec\xb2\xb4\xed\x81\xac\xeb\xb0\x95\xec\x8a\xa4 \xec\x9c\x84\xec\xa0\xaf\n */" },
#endif
		{ "IncludePath", "W_CheckMission.h" },
		{ "ModuleRelativePath", "Public/W_CheckMission.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\x8b\xa8\xec\x9d\xbc \xeb\xaf\xb8\xec\x85\x98 \xec\xb2\xb4\xed\x81\xac\xeb\xb0\x95\xec\x8a\xa4 \xec\x9c\x84\xec\xa0\xaf" },
#endif
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UW_CheckMission_Statics::NewProp_MissionActor_MetaData[] = {
		{ "Category", "Mission" },
		{ "ExposeOnSpawn", "true" },
		{ "ModuleRelativePath", "Public/W_CheckMission.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_CheckMission_Statics::NewProp_MissionActor = { "MissionActor", nullptr, (EPropertyFlags)0x0011000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_CheckMission, MissionActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::NewProp_MissionActor_MetaData), Z_Construct_UClass_UW_CheckMission_Statics::NewProp_MissionActor_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CompleteVarName_MetaData[] = {
		{ "Category", "Mission" },
		{ "ModuleRelativePath", "Public/W_CheckMission.h" },
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CompleteVarName = { "CompleteVarName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_CheckMission, CompleteVarName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CompleteVarName_MetaData), Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CompleteVarName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid_MetaData[] = {
		{ "Category", "Mission" },
		{ "ModuleRelativePath", "Public/W_CheckMission.h" },
	};
#endif
	void Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid_SetBit(void* Obj)
	{
		((UW_CheckMission*)Obj)->bCheckedWhenActorInvalid = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid = { "bCheckedWhenActorInvalid", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(UW_CheckMission), &Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid_MetaData), Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CheckBox_Mission_MetaData[] = {
		{ "BindWidget", "" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/W_CheckMission.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CheckBox_Mission = { "CheckBox_Mission", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UW_CheckMission, CheckBox_Mission), Z_Construct_UClass_UCheckBox_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CheckBox_Mission_MetaData), Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CheckBox_Mission_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UW_CheckMission_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_CheckMission_Statics::NewProp_MissionActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CompleteVarName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_CheckMission_Statics::NewProp_bCheckedWhenActorInvalid,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UW_CheckMission_Statics::NewProp_CheckBox_Mission,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UW_CheckMission_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UW_CheckMission>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UW_CheckMission_Statics::ClassParams = {
		&UW_CheckMission::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_UW_CheckMission_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::PropPointers),
		0,
		0x00B010A0u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::Class_MetaDataParams), Z_Construct_UClass_UW_CheckMission_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UW_CheckMission_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UW_CheckMission()
	{
		if (!Z_Registration_Info_UClass_UW_CheckMission.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UW_CheckMission.OuterSingleton, Z_Construct_UClass_UW_CheckMission_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UW_CheckMission.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<UW_CheckMission>()
	{
		return UW_CheckMission::StaticClass();
	}
	UW_CheckMission::UW_CheckMission(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UW_CheckMission);
	UW_CheckMission::~UW_CheckMission() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_W_CheckMission_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_W_CheckMission_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UW_CheckMission, UW_CheckMission::StaticClass, TEXT("UW_CheckMission"), &Z_Registration_Info_UClass_UW_CheckMission, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UW_CheckMission), 356706976U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_W_CheckMission_h_4267914712(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_W_CheckMission_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_W_CheckMission_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
