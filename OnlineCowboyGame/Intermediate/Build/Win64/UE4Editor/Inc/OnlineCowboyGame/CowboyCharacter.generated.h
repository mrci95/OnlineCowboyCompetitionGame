// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef ONLINECOWBOYGAME_CowboyCharacter_generated_h
#error "CowboyCharacter.generated.h already included, missing '#pragma once' in CowboyCharacter.h"
#endif
#define ONLINECOWBOYGAME_CowboyCharacter_generated_h

#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_SPARSE_DATA
#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnCowobyHit);


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnCowobyHit);


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACowboyCharacter(); \
	friend struct Z_Construct_UClass_ACowboyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACowboyCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineCowboyGame"), NO_API) \
	DECLARE_SERIALIZER(ACowboyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<ACowboyCharacter*>(this); }


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_INCLASS \
private: \
	static void StaticRegisterNativesACowboyCharacter(); \
	friend struct Z_Construct_UClass_ACowboyCharacter_Statics; \
public: \
	DECLARE_CLASS(ACowboyCharacter, APawn, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/OnlineCowboyGame"), NO_API) \
	DECLARE_SERIALIZER(ACowboyCharacter) \
	virtual UObject* _getUObject() const override { return const_cast<ACowboyCharacter*>(this); }


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_STANDARD_CONSTRUCTORS \
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


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACowboyCharacter(ACowboyCharacter&&); \
	NO_API ACowboyCharacter(const ACowboyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACowboyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACowboyCharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ACowboyCharacter)


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__DeathCamTarget() { return STRUCT_OFFSET(ACowboyCharacter, DeathCamTarget); } \
	FORCEINLINE static uint32 __PPO__MatchIntroViewRenderTarget2D() { return STRUCT_OFFSET(ACowboyCharacter, MatchIntroViewRenderTarget2D); }


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_26_PROLOG
#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_PRIVATE_PROPERTY_OFFSET \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_SPARSE_DATA \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_RPC_WRAPPERS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_INCLASS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_PRIVATE_PROPERTY_OFFSET \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_SPARSE_DATA \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_INCLASS_NO_PURE_DECLS \
	OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> ONLINECOWBOYGAME_API UClass* StaticClass<class ACowboyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID OnlineCowboyGame_Source_OnlineCowboyGame_CowboyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
