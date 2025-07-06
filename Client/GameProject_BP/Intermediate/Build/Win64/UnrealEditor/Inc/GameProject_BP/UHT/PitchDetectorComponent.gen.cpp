// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GameProject_BP/Public/PitchDetectorComponent.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePitchDetectorComponent() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	ENGINE_API UClass* Z_Construct_UClass_USoundSubmix_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UFFT1DComponent_NoRegister();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UPitchDetectorComponent();
	GAMEPROJECT_BP_API UClass* Z_Construct_UClass_UPitchDetectorComponent_NoRegister();
	GAMEPROJECT_BP_API UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature();
	GAMEPROJECT_BP_API UScriptStruct* Z_Construct_UScriptStruct_FPitchInfo();
	UPackage* Z_Construct_UPackage__Script_GameProject_BP();
// End Cross Module References
	static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_PitchInfo;
class UScriptStruct* FPitchInfo::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_PitchInfo.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_PitchInfo.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FPitchInfo, (UObject*)Z_Construct_UPackage__Script_GameProject_BP(), TEXT("PitchInfo"));
	}
	return Z_Registration_Info_UScriptStruct_PitchInfo.OuterSingleton;
}
template<> GAMEPROJECT_BP_API UScriptStruct* StaticStruct<FPitchInfo>()
{
	return FPitchInfo::StaticStruct();
}
	struct Z_Construct_UScriptStruct_FPitchInfo_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Frequency_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_NoteName_MetaData[];
#endif
		static const UECodeGen_Private::FStrPropertyParams NewProp_NoteName;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Confidence_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Confidence;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Volume_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Volume;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UECodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPitchInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\x9d\x8c\xec\xa0\x95 \xec\xa0\x95\xeb\xb3\xb4\xeb\xa5\xbc \xeb\x8b\xb4\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\x9d\x8c\xec\xa0\x95 \xec\xa0\x95\xeb\xb3\xb4\xeb\xa5\xbc \xeb\x8b\xb4\xeb\x8a\x94 \xea\xb5\xac\xec\xa1\xb0\xec\xb2\xb4" },
#endif
	};
#endif
	void* Z_Construct_UScriptStruct_FPitchInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FPitchInfo>();
	}
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Frequency_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98 (Hz)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98 (Hz)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPitchInfo, Frequency), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Frequency_MetaData), Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Frequency_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_NoteName_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\x8c\xec\xa0\x95\xec\x9d\x98 \xec\x9d\xb4\xeb\xa6\x84 (C4, A3 \xeb\x93\xb1)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\x8c\xec\xa0\x95\xec\x9d\x98 \xec\x9d\xb4\xeb\xa6\x84 (C4, A3 \xeb\x93\xb1)" },
#endif
	};
#endif
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_NoteName = { "NoteName", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPitchInfo, NoteName), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_NoteName_MetaData), Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_NoteName_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Confidence_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98\xec\x9d\x98 \xec\x8b\xa0\xeb\xa2\xb0\xeb\x8f\x84 (0-1)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98\xec\x9d\x98 \xec\x8b\xa0\xeb\xa2\xb0\xeb\x8f\x84 (0-1)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Confidence = { "Confidence", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPitchInfo, Confidence), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Confidence_MetaData), Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Confidence_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Volume_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\x8c\xec\xa0\x95\xec\x9d\x98 \xec\x84\xb8\xea\xb8\xb0/\xeb\xb3\xbc\xeb\xa5\xa8 (dB)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\x8c\xec\xa0\x95\xec\x9d\x98 \xec\x84\xb8\xea\xb8\xb0/\xeb\xb3\xbc\xeb\xa5\xa8 (dB)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Volume = { "Volume", nullptr, (EPropertyFlags)0x0010000000000014, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FPitchInfo, Volume), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Volume_MetaData), Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Volume_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FPitchInfo_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Frequency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_NoteName,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Confidence,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FPitchInfo_Statics::NewProp_Volume,
	};
	const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FPitchInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
		nullptr,
		&NewStructOps,
		"PitchInfo",
		Z_Construct_UScriptStruct_FPitchInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::PropPointers),
		sizeof(FPitchInfo),
		alignof(FPitchInfo),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FPitchInfo_Statics::Struct_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FPitchInfo_Statics::PropPointers) < 2048);
	UScriptStruct* Z_Construct_UScriptStruct_FPitchInfo()
	{
		if (!Z_Registration_Info_UScriptStruct_PitchInfo.InnerSingleton)
		{
			UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_PitchInfo.InnerSingleton, Z_Construct_UScriptStruct_FPitchInfo_Statics::ReturnStructParams);
		}
		return Z_Registration_Info_UScriptStruct_PitchInfo.InnerSingleton;
	}
	struct Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics
	{
		struct _Script_GameProject_BP_eventOnPitchDetected_Parms
		{
			FPitchInfo PitchInfo;
		};
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_PitchInfo_MetaData[];
#endif
		static const UECodeGen_Private::FStructPropertyParams NewProp_PitchInfo;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::NewProp_PitchInfo_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::NewProp_PitchInfo = { "PitchInfo", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(_Script_GameProject_BP_eventOnPitchDetected_Parms, PitchInfo), Z_Construct_UScriptStruct_FPitchInfo, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::NewProp_PitchInfo_MetaData), Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::NewProp_PitchInfo_MetaData) }; // 1422901608
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::NewProp_PitchInfo,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::Function_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\x8c\xec\xa0\x95\xec\x9d\xb4 \xea\xb0\x90\xec\xa7\x80\xeb\x90\x98\xec\x97\x88\xec\x9d\x84 \xeb\x95\x8c \xeb\xb0\x9c\xec\x83\x9d\xed\x95\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\x8c\xec\xa0\x95\xec\x9d\xb4 \xea\xb0\x90\xec\xa7\x80\xeb\x90\x98\xec\x97\x88\xec\x9d\x84 \xeb\x95\x8c \xeb\xb0\x9c\xec\x83\x9d\xed\x95\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\xeb\xa5\xbc \xec\x9c\x84\xed\x95\x9c \xeb\x8d\xb8\xeb\xa6\xac\xea\xb2\x8c\xec\x9d\xb4\xed\x8a\xb8" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GameProject_BP, nullptr, "OnPitchDetected__DelegateSignature", nullptr, nullptr, Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::PropPointers), sizeof(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::_Script_GameProject_BP_eventOnPitchDetected_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::Function_MetaDataParams), Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::_Script_GameProject_BP_eventOnPitchDetected_Parms) < MAX_uint16);
	UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
void FOnPitchDetected_DelegateWrapper(const FMulticastScriptDelegate& OnPitchDetected, FPitchInfo const& PitchInfo)
{
	struct _Script_GameProject_BP_eventOnPitchDetected_Parms
	{
		FPitchInfo PitchInfo;
	};
	_Script_GameProject_BP_eventOnPitchDetected_Parms Parms;
	Parms.PitchInfo=PitchInfo;
	OnPitchDetected.ProcessMulticastDelegate<UObject>(&Parms);
}
	DEFINE_FUNCTION(UPitchDetectorComponent::execFrequencyToNoteName)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_Frequency);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FString*)Z_Param__Result=UPitchDetectorComponent::FrequencyToNoteName(Z_Param_Frequency);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UPitchDetectorComponent::execGetCurrentPitch)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FPitchInfo*)Z_Param__Result=P_THIS->GetCurrentPitch();
		P_NATIVE_END;
	}
	void UPitchDetectorComponent::StaticRegisterNativesUPitchDetectorComponent()
	{
		UClass* Class = UPitchDetectorComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "FrequencyToNoteName", &UPitchDetectorComponent::execFrequencyToNoteName },
			{ "GetCurrentPitch", &UPitchDetectorComponent::execGetCurrentPitch },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics
	{
		struct PitchDetectorComponent_eventFrequencyToNoteName_Parms
		{
			float Frequency;
			FString ReturnValue;
		};
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Frequency;
		static const UECodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::NewProp_Frequency = { "Frequency", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PitchDetectorComponent_eventFrequencyToNoteName_Parms, Frequency), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PitchDetectorComponent_eventFrequencyToNoteName_Parms, ReturnValue), METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::NewProp_Frequency,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::Function_MetaDataParams[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98\xeb\xa5\xbc \xec\x9d\x8c\xec\xa0\x95 \xec\x9d\xb4\xeb\xa6\x84\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\xa3\xbc\xed\x8c\x8c\xec\x88\x98\xeb\xa5\xbc \xec\x9d\x8c\xec\xa0\x95 \xec\x9d\xb4\xeb\xa6\x84\xec\x9c\xbc\xeb\xa1\x9c \xeb\xb3\x80\xed\x99\x98" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPitchDetectorComponent, nullptr, "FrequencyToNoteName", nullptr, nullptr, Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PitchDetectorComponent_eventFrequencyToNoteName_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::PitchDetectorComponent_eventFrequencyToNoteName_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics
	{
		struct PitchDetectorComponent_eventGetCurrentPitch_Parms
		{
			FPitchInfo ReturnValue;
		};
		static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(PitchDetectorComponent_eventGetCurrentPitch_Parms, ReturnValue), Z_Construct_UScriptStruct_FPitchInfo, METADATA_PARAMS(0, nullptr) }; // 1422901608
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::Function_MetaDataParams[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xed\x98\x84\xec\x9e\xac \xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\x9d\x8c\xec\xa0\x95 \xec\xa0\x95\xeb\xb3\xb4 \xeb\xb0\x98\xed\x99\x98\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xea\xb0\x90\xec\xa7\x80\xeb\x90\x9c \xec\x9d\x8c\xec\xa0\x95 \xec\xa0\x95\xeb\xb3\xb4 \xeb\xb0\x98\xed\x99\x98" },
#endif
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPitchDetectorComponent, nullptr, "GetCurrentPitch", nullptr, nullptr, Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PropPointers), sizeof(Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PitchDetectorComponent_eventGetCurrentPitch_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::Function_MetaDataParams), Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::PitchDetectorComponent_eventGetCurrentPitch_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UPitchDetectorComponent);
	UClass* Z_Construct_UClass_UPitchDetectorComponent_NoRegister()
	{
		return UPitchDetectorComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPitchDetectorComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_OnPitchDetected_MetaData[];
#endif
		static const UECodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnPitchDetected;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FFTSize_MetaData[];
#endif
		static const UECodeGen_Private::FIntPropertyParams NewProp_FFTSize;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_Threshold_MetaData[];
#endif
		static const UECodeGen_Private::FFloatPropertyParams NewProp_Threshold;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_TargetSubmix_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_TargetSubmix;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_FFTComponent_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_FFTComponent;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPitchDetectorComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GameProject_BP,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_UPitchDetectorComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPitchDetectorComponent_FrequencyToNoteName, "FrequencyToNoteName" }, // 3900205772
		{ &Z_Construct_UFunction_UPitchDetectorComponent_GetCurrentPitch, "GetCurrentPitch" }, // 4079660151
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Audio" },
		{ "IncludePath", "PitchDetectorComponent.h" },
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_OnPitchDetected_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x9d\x8c\xec\xa0\x95\xec\x9d\xb4 \xea\xb0\x90\xec\xa7\x80\xeb\x90\x98\xec\x97\x88\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x9d\x8c\xec\xa0\x95\xec\x9d\xb4 \xea\xb0\x90\xec\xa7\x80\xeb\x90\x98\xec\x97\x88\xec\x9d\x84 \xeb\x95\x8c \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
#endif
	};
#endif
	const UECodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_OnPitchDetected = { "OnPitchDetected", nullptr, (EPropertyFlags)0x0010000010080000, UECodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPitchDetectorComponent, OnPitchDetected), Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_OnPitchDetected_MetaData), Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_OnPitchDetected_MetaData) }; // 4097297797
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTSize_MetaData[] = {
		{ "Category", "Audio Analysis" },
		{ "ClampMax", "16384" },
		{ "ClampMin", "512" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 FFT \xed\x81\xac\xea\xb8\xb0 (2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1\xec\x9d\xb4\xec\x96\xb4\xec\x95\xbc \xed\x95\xa8, \xec\x98\x88: 1024, 2048, 4096)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xec\x82\xac\xec\x9a\xa9\xed\x95\xa0 FFT \xed\x81\xac\xea\xb8\xb0 (2\xec\x9d\x98 \xea\xb1\xb0\xeb\x93\xad\xec\xa0\x9c\xea\xb3\xb1\xec\x9d\xb4\xec\x96\xb4\xec\x95\xbc \xed\x95\xa8, \xec\x98\x88: 1024, 2048, 4096)" },
#endif
	};
#endif
	const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTSize = { "FFTSize", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPitchDetectorComponent, FFTSize), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTSize_MetaData), Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTSize_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_Threshold_MetaData[] = {
		{ "Category", "Audio Analysis" },
		{ "ClampMax", "1.0" },
		{ "ClampMin", "0.0" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xb6\x84\xec\x84\x9d \xea\xb0\x90\xeb\x8f\x84 \xec\xa1\xb0\xec\xa0\x88 (\xeb\x82\xae\xec\x9d\x84\xec\x88\x98\xeb\xa1\x9d \xeb\x8d\x94 \xeb\xaf\xbc\xea\xb0\x90)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xb6\x84\xec\x84\x9d \xea\xb0\x90\xeb\x8f\x84 \xec\xa1\xb0\xec\xa0\x88 (\xeb\x82\xae\xec\x9d\x84\xec\x88\x98\xeb\xa1\x9d \xeb\x8d\x94 \xeb\xaf\xbc\xea\xb0\x90)" },
#endif
	};
#endif
	const UECodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_Threshold = { "Threshold", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPitchDetectorComponent, Threshold), METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_Threshold_MetaData), Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_Threshold_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_TargetSubmix_MetaData[] = {
		{ "Category", "Audio Analysis" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// \xeb\xa7\x88\xec\x9d\xb4\xed\x81\xac \xec\x9e\x85\xeb\xa0\xa5\xec\x9d\x84 \xec\xb2\x98\xeb\xa6\xac\xed\x95\xa0 \xec\x84\x9c\xeb\xb8\x8c\xeb\xaf\xb9\xec\x8a\xa4 (\xeb\xb3\xb4\xed\x86\xb5 MasterSubmix \xeb\x98\x90\xeb\x8a\x94 VoiceChatSubmix)\n" },
#endif
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xeb\xa7\x88\xec\x9d\xb4\xed\x81\xac \xec\x9e\x85\xeb\xa0\xa5\xec\x9d\x84 \xec\xb2\x98\xeb\xa6\xac\xed\x95\xa0 \xec\x84\x9c\xeb\xb8\x8c\xeb\xaf\xb9\xec\x8a\xa4 (\xeb\xb3\xb4\xed\x86\xb5 MasterSubmix \xeb\x98\x90\xeb\x8a\x94 VoiceChatSubmix)" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_TargetSubmix = { "TargetSubmix", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPitchDetectorComponent, TargetSubmix), Z_Construct_UClass_USoundSubmix_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_TargetSubmix_MetaData), Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_TargetSubmix_MetaData) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTComponent_MetaData[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "// FFT \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8\n" },
#endif
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/PitchDetectorComponent.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "FFT \xec\xbb\xb4\xed\x8f\xac\xeb\x84\x8c\xed\x8a\xb8" },
#endif
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTComponent = { "FFTComponent", nullptr, (EPropertyFlags)0x0040000000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UPitchDetectorComponent, FFTComponent), Z_Construct_UClass_UFFT1DComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTComponent_MetaData), Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTComponent_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPitchDetectorComponent_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_OnPitchDetected,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTSize,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_Threshold,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_TargetSubmix,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPitchDetectorComponent_Statics::NewProp_FFTComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPitchDetectorComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPitchDetectorComponent>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_UPitchDetectorComponent_Statics::ClassParams = {
		&UPitchDetectorComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPitchDetectorComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::Class_MetaDataParams), Z_Construct_UClass_UPitchDetectorComponent_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UPitchDetectorComponent_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_UPitchDetectorComponent()
	{
		if (!Z_Registration_Info_UClass_UPitchDetectorComponent.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UPitchDetectorComponent.OuterSingleton, Z_Construct_UClass_UPitchDetectorComponent_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_UPitchDetectorComponent.OuterSingleton;
	}
	template<> GAMEPROJECT_BP_API UClass* StaticClass<UPitchDetectorComponent>()
	{
		return UPitchDetectorComponent::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPitchDetectorComponent);
	UPitchDetectorComponent::~UPitchDetectorComponent() {}
	struct Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics
	{
		static const FStructRegisterCompiledInInfo ScriptStructInfo[];
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FStructRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ScriptStructInfo[] = {
		{ FPitchInfo::StaticStruct, Z_Construct_UScriptStruct_FPitchInfo_Statics::NewStructOps, TEXT("PitchInfo"), &Z_Registration_Info_UScriptStruct_PitchInfo, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FPitchInfo), 1422901608U) },
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_UPitchDetectorComponent, UPitchDetectorComponent::StaticClass, TEXT("UPitchDetectorComponent"), &Z_Registration_Info_UClass_UPitchDetectorComponent, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UPitchDetectorComponent), 504617937U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_2723019871(TEXT("/Script/GameProject_BP"),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ClassInfo),
		Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_user_Desktop_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_Statics::ScriptStructInfo),
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
