// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/MissionBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMissionBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_AMissionBase();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_AMissionBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	DEFINE_FUNCTION(AMissionBase::execOnRep_IsComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_IsComplete();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMissionBase::execGetMissionID)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FName*)Z_Param__Result=P_THIS->GetMissionID();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMissionBase::execSetMissionComplete)
	{
		P_GET_UBOOL(Z_Param_bNewComplete);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetMissionComplete(Z_Param_bNewComplete);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMissionBase::execIsComplete)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsComplete();
		P_NATIVE_END;
	}
	void AMissionBase::StaticRegisterNativesAMissionBase()
	{
		UClass* Class = AMissionBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetMissionID", &AMissionBase::execGetMissionID },
			{ "IsComplete", &AMissionBase::execIsComplete },
			{ "OnRep_IsComplete", &AMissionBase::execOnRep_IsComplete },
			{ "SetMissionComplete", &AMissionBase::execSetMissionComplete },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMissionBase_GetMissionID_Statics
	{
		struct MissionBase_eventGetMissionID_Parms
		{
			FName ReturnValue;
		};
		static const UECodeGen_Private::FNamePropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(MissionBase_eventGetMissionID_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::Function_MetaDataParams[] = {
		{ "Category", "Mission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xaf\xb8\xec\x85\x98 ID \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xaf\xb8\xec\x85\x98 ID \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMissionBase, nullptr, "GetMissionID", nullptr, nullptr, Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::MissionBase_eventGetMissionID_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::MissionBase_eventGetMissionID_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMissionBase_GetMissionID()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMissionBase_GetMissionID_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMissionBase_IsComplete_Statics
	{
		struct MissionBase_eventIsComplete_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMissionBase_IsComplete_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((MissionBase_eventIsComplete_Parms*)Obj)->ReturnValue = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMissionBase_IsComplete_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MissionBase_eventIsComplete_Parms), &Z_Construct_UFunction_AMissionBase_IsComplete_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMissionBase_IsComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMissionBase_IsComplete_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMissionBase_IsComplete_Statics::Function_MetaDataParams[] = {
		{ "Category", "Mission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x99\x84\xeb\xa3\x8c \xec\x97\xac\xeb\xb6\x80 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x99\x84\xeb\xa3\x8c \xec\x97\xac\xeb\xb6\x80 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMissionBase_IsComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMissionBase, nullptr, "IsComplete", nullptr, nullptr, Z_Construct_UFunction_AMissionBase_IsComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_IsComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMissionBase_IsComplete_Statics::MissionBase_eventIsComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_IsComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMissionBase_IsComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_IsComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMissionBase_IsComplete_Statics::MissionBase_eventIsComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMissionBase_IsComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMissionBase_IsComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// RepNotify: \xed\x81\xb4\xeb\x9d\xbc \xeb\x8f\x99\xea\xb8\xb0\xed\x99\x94 \xed\x99\x95\xec\x9d\xb8\xec\x9a\xa9\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "RepNotify: \xed\x81\xb4\xeb\x9d\xbc \xeb\x8f\x99\xea\xb8\xb0\xed\x99\x94 \xed\x99\x95\xec\x9d\xb8\xec\x9a\xa9" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMissionBase, nullptr, "OnRep_IsComplete", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00080401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AMissionBase_OnRep_IsComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMissionBase_OnRep_IsComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics
	{
		struct MissionBase_eventSetMissionComplete_Parms
		{
			bool bNewComplete;
		};
		static void NewProp_bNewComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bNewComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::NewProp_bNewComplete_SetBit(void* Obj)
	{
		((MissionBase_eventSetMissionComplete_Parms*)Obj)->bNewComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::NewProp_bNewComplete = { "bNewComplete", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(MissionBase_eventSetMissionComplete_Parms), &Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::NewProp_bNewComplete_SetBit, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::NewProp_bNewComplete,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::Function_MetaDataParams[] = {
		{ "Category", "Mission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x99\x84\xeb\xa3\x8c \xec\xb2\x98\xeb\xa6\xac (\xec\x84\x9c\xeb\xb2\x84\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c \xed\x98\xb8\xec\xb6\x9c)\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x99\x84\xeb\xa3\x8c \xec\xb2\x98\xeb\xa6\xac (\xec\x84\x9c\xeb\xb2\x84\xec\x97\x90\xec\x84\x9c\xeb\xa7\x8c \xed\x98\xb8\xec\xb6\x9c)" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMissionBase, nullptr, "SetMissionComplete", nullptr, nullptr, Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::PropPointers), sizeof(Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::MissionBase_eventSetMissionComplete_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::Function_MetaDataParams), Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::MissionBase_eventSetMissionComplete_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AMissionBase_SetMissionComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AMissionBase_SetMissionComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AMissionBase);
	UClass* Z_Construct_UClass_AMissionBase_NoRegister()
	{
		return AMissionBase::StaticClass();
	}
	struct Z_Construct_UClass_AMissionBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MissionID_MetaData[];
#endif
		static const UECodeGen_Private::FNamePropertyParams NewProp_MissionID;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_bIsComplete_MetaData[];
#endif
		static void NewProp_bIsComplete_SetBit(void* Obj);
		static const UECodeGen_Private::FBoolPropertyParams NewProp_bIsComplete;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMissionBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AMissionBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMissionBase_GetMissionID, "GetMissionID" }, // 810226205
		{ &Z_Construct_UFunction_AMissionBase_IsComplete, "IsComplete" }, // 2335874219
		{ &Z_Construct_UFunction_AMissionBase_OnRep_IsComplete, "OnRep_IsComplete" }, // 3706564641
		{ &Z_Construct_UFunction_AMissionBase_SetMissionComplete, "SetMissionComplete" }, // 1549377104
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMissionBase_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MissionBase.h" },
		{ "ModuleRelativePath", "Public/MissionBase.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMissionBase_Statics::NewProp_MissionID_MetaData[] = {
		{ "Category", "Mission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xaf\xb8\xec\x85\x98 ID (Enum\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\x94\xea\xbe\xb8\xea\xb3\xa0 \xec\x8b\xb6\xeb\x8b\xa4\xeb\xa9\xb4 E_MissionID \xea\xb0\x99\xec\x9d\x80 Enum \xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4 \xea\xb5\x90\xec\xb2\xb4 \xea\xb0\x80\xeb\x8a\xa5)\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xaf\xb8\xec\x85\x98 ID (Enum\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb0\x94\xea\xbe\xb8\xea\xb3\xa0 \xec\x8b\xb6\xeb\x8b\xa4\xeb\xa9\xb4 E_MissionID \xea\xb0\x99\xec\x9d\x80 Enum \xed\x83\x80\xec\x9e\x85\xec\x9d\x84 \xeb\xa7\x8c\xeb\x93\xa4\xec\x96\xb4 \xea\xb5\x90\xec\xb2\xb4 \xea\xb0\x80\xeb\x8a\xa5)" },
#endif
	};
#endif
	const UECodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMissionBase_Statics::NewProp_MissionID = { "MissionID", nullptr, (EPropertyFlags)0x0020080000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AMissionBase, MissionID), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::NewProp_MissionID_MetaData), Z_Construct_UClass_AMissionBase_Statics::NewProp_MissionID_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete_MetaData[] = {
		{ "Category", "Mission" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x99\x84\xeb\xa3\x8c \xec\x97\xac\xeb\xb6\x80\n" },
#endif
		{ "ModuleRelativePath", "Public/MissionBase.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x99\x84\xeb\xa3\x8c \xec\x97\xac\xeb\xb6\x80" },
#endif
	};
#endif
	void Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete_SetBit(void* Obj)
	{
		((AMissionBase*)Obj)->bIsComplete = 1;
	}
	const UECodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete = { "bIsComplete", "OnRep_IsComplete", (EPropertyFlags)0x0020080100000034, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(AMissionBase), &Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete_MetaData), Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMissionBase_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMissionBase_Statics::NewProp_MissionID,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMissionBase_Statics::NewProp_bIsComplete,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMissionBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMissionBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AMissionBase_Statics::ClassParams = {
		&AMissionBase::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMissionBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::Class_MetaDataParams), Z_Construct_UClass_AMissionBase_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AMissionBase_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_AMissionBase()
	{
		if (!Z_Registration_Info_UClass_AMissionBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AMissionBase.OuterSingleton, Z_Construct_UClass_AMissionBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AMissionBase.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<AMissionBase>()
	{
		return AMissionBase::StaticClass();
	}

	void AMissionBase::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_bIsComplete(TEXT("bIsComplete"));

		const bool bIsValid = true
			&& Name_bIsComplete == ClassReps[(int32)ENetFields_Private::bIsComplete].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AMissionBase"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMissionBase);
	AMissionBase::~AMissionBase() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AMissionBase, AMissionBase::StaticClass, TEXT("AMissionBase"), &Z_Registration_Info_UClass_AMissionBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AMissionBase), 2712597436U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_2690960395(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
