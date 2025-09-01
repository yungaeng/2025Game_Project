// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "MissionBase.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAMEPROJECT_BP_MissionBase_generated_h
#error "MissionBase.generated.h already included, missing '#pragma once' in MissionBase.h"
#endif
#define GAMEPROJECT_BP_MissionBase_generated_h

#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_SPARSE_DATA
#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS
#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnRep_IsComplete); \
	DECLARE_FUNCTION(execGetMissionID); \
	DECLARE_FUNCTION(execSetMissionComplete); \
	DECLARE_FUNCTION(execIsComplete);


#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_ACCESSORS
#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMissionBase(); \
	friend struct Z_Construct_UClass_AMissionBase_Statics; \
public: \
	DECLARE_CLASS(AMissionBase, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GameProject_BP"), NO_API) \
	DECLARE_SERIALIZER(AMissionBase) \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		bIsComplete=NETFIELD_REP_START, \
		NETFIELD_REP_END=bIsComplete	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMissionBase(AMissionBase&&); \
	NO_API AMissionBase(const AMissionBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMissionBase); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMissionBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMissionBase) \
	NO_API virtual ~AMissionBase();


#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_7_PROLOG
#define FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_SPARSE_DATA \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_EDITOR_ONLY_SPARSE_DATA_PROPERTY_ACCESSORS \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_ACCESSORS \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_INCLASS_NO_PURE_DECLS \
	FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h_10_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAMEPROJECT_BP_API UClass* StaticClass<class AMissionBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_user_Desktop_2025Game_Project_Client_GameProject_BP_Source_GameProject_BP_Public_MissionBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
