// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/CPPMyController.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCPPMyController() {}
// Cross Module References
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ENGINE_API UClass* Z_Construct_UClass_APawn_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_APlayerController();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputAction_NoRegister();
	ENHANCEDINPUT_API UClass* Z_Construct_UClass_UInputMappingContext_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPPMyController();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_ACPPMyController_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UCPP_W_Indicator_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	void ACPPMyController::StaticRegisterNativesACPPMyController()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ACPPMyController);
	UClass* Z_Construct_UClass_ACPPMyController_NoRegister()
	{
		return ACPPMyController::StaticClass();
	}
	struct Z_Construct_UClass_ACPPMyController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_DefaultMappingContext_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_DefaultMappingContext;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MoveAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MoveAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_LookAction_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_LookAction;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_BP_IndicatorWidgetClass_MetaData[];
#endif
		static const UECodeGen_Private::FClassPropertyParams NewProp_BP_IndicatorWidgetClass;
		static const UECodeGen_Private::FObjectPropertyParams NewProp_IndicatorWidgets_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_IndicatorWidgets_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_IndicatorWidgets;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_ControlledPawn_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_ControlledPawn;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACPPMyController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APlayerController,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "CPPMyController.h" },
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_DefaultMappingContext_MetaData[] = {
		{ "Category", "Input" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//\xec\x9e\x85\xeb\xa0\xa5 \xea\xb4\x80\xeb\xa0\xa8\n" },
#endif
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9e\x85\xeb\xa0\xa5 \xea\xb4\x80\xeb\xa0\xa8" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_DefaultMappingContext = { "DefaultMappingContext", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, DefaultMappingContext), Z_Construct_UClass_UInputMappingContext_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_DefaultMappingContext_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_DefaultMappingContext_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_MoveAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_MoveAction = { "MoveAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, MoveAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_MoveAction_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_MoveAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_LookAction_MetaData[] = {
		{ "Category", "Input" },
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_LookAction = { "LookAction", nullptr, (EPropertyFlags)0x0010000000010015, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, LookAction), Z_Construct_UClass_UInputAction_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_LookAction_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_LookAction_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_BP_IndicatorWidgetClass_MetaData[] = {
		{ "Category", "UI" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "//Indicator \xec\x9c\x84\xec\xa0\xaf \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4\n" },
#endif
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Indicator \xec\x9c\x84\xec\xa0\xaf \xed\x81\xb4\xeb\x9e\x98\xec\x8a\xa4" },
#endif
	};
#endif
	const UECodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_BP_IndicatorWidgetClass = { "BP_IndicatorWidgetClass", nullptr, (EPropertyFlags)0x0014000000010015, UECodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, BP_IndicatorWidgetClass), Z_Construct_UClass_UClass, Z_Construct_UClass_UCPP_W_Indicator_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_BP_IndicatorWidgetClass_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_BP_IndicatorWidgetClass_MetaData) };
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets_Inner = { "IndicatorWidgets", nullptr, (EPropertyFlags)0x0000000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_UCPP_W_Indicator_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x97\xac\xeb\x9f\xac \xed\x83\x80\xea\xb2\x9f\xec\x9a\xa9 \xec\x9c\x84\xec\xa0\xaf\xeb\x93\xa4 \xec\xa0\x80\xec\x9e\xa5\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x97\xac\xeb\x9f\xac \xed\x83\x80\xea\xb2\x9f\xec\x9a\xa9 \xec\x9c\x84\xec\xa0\xaf\xeb\x93\xa4 \xec\xa0\x80\xec\x9e\xa5" },
#endif
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets = { "IndicatorWidgets", nullptr, (EPropertyFlags)0x0040008000000008, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, IndicatorWidgets), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACPPMyController_Statics::NewProp_ControlledPawn_MetaData[] = {
		{ "ModuleRelativePath", "Public/CPPMyController.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACPPMyController_Statics::NewProp_ControlledPawn = { "ControlledPawn", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ACPPMyController, ControlledPawn), Z_Construct_UClass_APawn_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::NewProp_ControlledPawn_MetaData), Z_Construct_UClass_ACPPMyController_Statics::NewProp_ControlledPawn_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACPPMyController_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_DefaultMappingContext,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_MoveAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_LookAction,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_BP_IndicatorWidgetClass,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_IndicatorWidgets,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACPPMyController_Statics::NewProp_ControlledPawn,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACPPMyController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACPPMyController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ACPPMyController_Statics::ClassParams = {
		&ACPPMyController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ACPPMyController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::Class_MetaDataParams), Z_Construct_UClass_ACPPMyController_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ACPPMyController_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ACPPMyController()
	{
		if (!Z_Registration_Info_UClass_ACPPMyController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ACPPMyController.OuterSingleton, Z_Construct_UClass_ACPPMyController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ACPPMyController.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<ACPPMyController>()
	{
		return ACPPMyController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACPPMyController);
	ACPPMyController::~ACPPMyController() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ACPPMyController, ACPPMyController::StaticClass, TEXT("ACPPMyController"), &Z_Registration_Info_UClass_ACPPMyController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ACPPMyController), 2778721334U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyController_h_2403338992(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_CPPMyController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
