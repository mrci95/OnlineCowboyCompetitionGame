// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMouseMove;
#ifdef ONLINECOWBOYGAME_CowboyCharacter_generated_h
#error "CowboyCharacter.generated.h already included, missing '#pragma once' in CowboyCharacter.h"
#endif
#define ONLINECOWBOYGAME_CowboyCharacter_generated_h

#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_28_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FAimingServerState_Statics; \
	ONLINECOWBOYGAME_API static class UScriptStruct* StaticStruct();


template<> ONLINECOWBOYGAME_API UScriptStruct* StaticStruct<struct FAimingServerState>();

#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMouseMove_Statics; \
	ONLINECOWBOYGAME_API static class UScriptStruct* StaticStruct();


template<> ONLINECOWBOYGAME_API UScriptStruct* StaticStruct<struct FMouseMove>();

#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_SPARSE_DATA
#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_RPC_WRAPPERS \
	virtual bool Server_SendMove_Validate(FMouseMove ); \
	virtual void Server_SendMove_Implementation(FMouseMove Move); \
 \
	DECLARE_FUNCTION(execOnRep_ServerState); \
	DECLARE_FUNCTION(execServer_SendMove);


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	virtual bool Server_SendMove_Validate(FMouseMove ); \
	virtual void Server_SendMove_Implementation(FMouseMove Move); \
 \
	DECLARE_FUNCTION(execOnRep_ServerState); \
	DECLARE_FUNCTION(execServer_SendMove);


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_EVENT_PARMS \
	struct CowboyCharacter_eventServer_SendMove_Parms \
	{ \
		FMouseMove Move; \
	};


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_CALLBACK_WRAPPERS
#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACowboyCharacter(); \
	friend struct Z_Construct_UClass_ACowboyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACowboyCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineCowboyGame"), NO_API) \
	DECLARE_SERIALIZER(ACowboyCharacter) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ServerState=NETFIELD_REP_START, \
		NETFIELD_REP_END=ServerState	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_INCLASS \
private: \
	static void StaticRegisterNativesACowboyCharacter(); \
	friend struct Z_Construct_UClass_ACowboyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACowboyCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineCowboyGame"), NO_API) \
	DECLARE_SERIALIZER(ACowboyCharacter) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		ServerState=NETFIELD_REP_START, \
		NETFIELD_REP_END=ServerState	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACowboyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACowboyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACowboyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACowboyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACowboyCharacter(ACowboyCharacter&&); \
	NO_API ACowboyCharacter(const ACowboyCharacter&); \
public:


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACowboyCharacter(ACowboyCharacter&&); \
	NO_API ACowboyCharacter(const ACowboyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACowboyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACowboyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACowboyCharacter)


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CapsuleComponent() { return STRUCT_OFFSET(ACowboyCharacter, CapsuleComponent); } \
	FORCEINLINE static uint32 __PPO__CoboyMesh() { return STRUCT_OFFSET(ACowboyCharacter, CoboyMesh); } \
	FORCEINLINE static uint32 __PPO__TPPCameraRoot() { return STRUCT_OFFSET(ACowboyCharacter, TPPCameraRoot); } \
	FORCEINLINE static uint32 __PPO__TPPCamera() { return STRUCT_OFFSET(ACowboyCharacter, TPPCamera); } \
	FORCEINLINE static uint32 __PPO__TPPCameraRangeRadius() { return STRUCT_OFFSET(ACowboyCharacter, TPPCameraRangeRadius); } \
	FORCEINLINE static uint32 __PPO__DrawTppRangeCone() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppRangeCone); } \
	FORCEINLINE static uint32 __PPO__DrawTppConeDirectionLine() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppConeDirectionLine); } \
	FORCEINLINE static uint32 __PPO__DrawTppRandomInitialCameraViewLine() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppRandomInitialCameraViewLine); } \
	FORCEINLINE static uint32 __PPO__DrawTppConeRadiusLine() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppConeRadiusLine); } \
	FORCEINLINE static uint32 __PPO__DrawTppConeLimitEdgeLine() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppConeLimitEdgeLine); } \
	FORCEINLINE static uint32 __PPO__DrawTppCurrentCameraViewLine() { return STRUCT_OFFSET(ACowboyCharacter, DrawTppCurrentCameraViewLine); } \
	FORCEINLINE static uint32 __PPO__ServerState() { return STRUCT_OFFSET(ACowboyCharacter, ServerState); }


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_35_PROLOG \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_EVENT_PARMS


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_SPARSE_DATA \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_RPC_WRAPPERS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_CALLBACK_WRAPPERS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_INCLASS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_PRIVATE_PROPERTY_OFFSET \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_SPARSE_DATA \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_CALLBACK_WRAPPERS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_INCLASS_NO_PURE_DECLS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINECOWBOYGAME_API UClass* StaticClass<class ACowboyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
