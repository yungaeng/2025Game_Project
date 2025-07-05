// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "PitchDetectorComponent.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FPitchInfo;
#ifdef GAMEPROJECT_BP_PitchDetectorComponent_generated_h
#error "PitchDetectorComponent.generated.h already included, missing '#pragma once' in PitchDetectorComponent.h"
#endif
#define GAMEPROJECT_BP_PitchDetectorComponent_generated_h

#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_20_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FPitchInfo_Statics; \
	GAMEPROJECT_BP_API static class UScriptStruct* StaticStruct();


template<> GAMEPROJECT_BP_API UScriptStruct* StaticStruct<struct FPitchInfo>();

#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_40_DELEGATE \
GAMEPROJECT_BP_API void FOnPitchDetected_DelegateWrapper(const FMulticastScriptDelegate& OnPitchDetected, FPitchInfo const& PitchInfo);


#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_SPARSE_DATA
#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execFrequencyToNoteName); \
	DECLARE_FUNCTION(execGetCurrentPitch);


#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_ACCESSORS
#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPitchDetectorComponent(); \
	friend struct Z_Construct_UClass_UPitchDetectorComponent_Statics; \
public: \
	DECLARE_CLASS(UPitchDetectorComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GameProject_BP"), NO_API) \
	DECLARE_SERIALIZER(UPitchDetectorComponent)


#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPitchDetectorComponent(UPitchDetectorComponent&&); \
	NO_API UPitchDetectorComponent(const UPitchDetectorComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPitchDetectorComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPitchDetectorComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPitchDetectorComponent) \
	NO_API virtual ~UPitchDetectorComponent();


#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_42_PROLOG
#define FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_SPARSE_DATA \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_ACCESSORS \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h_45_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPROJECT_BP_API UClass* StaticClass<class UPitchDetectorComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Desktop_cc_copy_GameProject_BP_Source_GameProject_BP_Public_PitchDetectorComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
