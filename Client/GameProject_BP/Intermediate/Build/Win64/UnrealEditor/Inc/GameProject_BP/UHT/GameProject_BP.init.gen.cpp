// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameProject_BP_init() {}
	GAMEPROJECT_BP_API UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature();
	GAMEPROJECT_BP_API UFunction* Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature();
	static FPackageRegistrationInfo Z_Registration_Info_UPackage__Script_GameProject_BP;
	FORCENOINLINE UPackage* Z_Construct_UPackage__Script_GameProject_BP()
	{
		if (!Z_Registration_Info_UPackage__Script_GameProject_BP.OuterSingleton)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GameProject_BP_OnPitchDetected__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GameProject_BP_OnSoundAnalyzerClear__DelegateSignature,
			};
			static const UECodeGen_Private::FPackageParams PackageParams = {
				"/Script/GameProject_BP",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x859D29BB,
				0xEC632DBF,
				METADATA_PARAMS(0, nullptr)
			};
			UECodeGen_Private::ConstructUPackage(Z_Registration_Info_UPackage__Script_GameProject_BP.OuterSingleton, PackageParams);
		}
		return Z_Registration_Info_UPackage__Script_GameProject_BP.OuterSingleton;
	}
	static FRegisterCompiledInInfo Z_CompiledInDeferPackage_UPackage__Script_GameProject_BP(Z_Construct_UPackage__Script_GameProject_BP, TEXT("/Script/GameProject_BP"), Z_Registration_Info_UPackage__Script_GameProject_BP, CONSTRUCT_RELOAD_VERSION_INFO(FPackageReloadVersionInfo, 0x859D29BB, 0xEC632DBF));
PRAGMA_ENABLE_DEPRECATION_WARNINGS
