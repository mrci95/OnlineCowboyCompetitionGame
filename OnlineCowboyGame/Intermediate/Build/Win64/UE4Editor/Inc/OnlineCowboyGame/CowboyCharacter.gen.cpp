// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineCowboyGame/CowboyCharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCowboyCharacter() {}
// Cross Module References
	ONLINECOWBOYGAME_API UScriptStruct* Z_Construct_UScriptStruct_FAimingServerState();
	UPackage* Z_Construct_UPackage__Script_OnlineCowboyGame();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ONLINECOWBOYGAME_API UScriptStruct* Z_Construct_UScriptStruct_FMouseMove();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector2D();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_ACowboyCharacter_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_ACowboyCharacter();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FAimingServerState::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ONLINECOWBOYGAME_API uint32 Get_Z_Construct_UScriptStruct_FAimingServerState_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAimingServerState, Z_Construct_UPackage__Script_OnlineCowboyGame(), TEXT("AimingServerState"), sizeof(FAimingServerState), Get_Z_Construct_UScriptStruct_FAimingServerState_Hash());
	}
	return Singleton;
}
template<> ONLINECOWBOYGAME_API UScriptStruct* StaticStruct<FAimingServerState>()
{
	return FAimingServerState::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAimingServerState(FAimingServerState::StaticStruct, TEXT("/Script/OnlineCowboyGame"), TEXT("AimingServerState"), false, nullptr, nullptr);
static struct FScriptStruct_OnlineCowboyGame_StaticRegisterNativesFAimingServerState
{
	FScriptStruct_OnlineCowboyGame_StaticRegisterNativesFAimingServerState()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AimingServerState")),new UScriptStruct::TCppStructOps<FAimingServerState>);
	}
} ScriptStruct_OnlineCowboyGame_StaticRegisterNativesFAimingServerState;
	struct Z_Construct_UScriptStruct_FAimingServerState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Transform_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Transform;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAimingServerState_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAimingServerState_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAimingServerState>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAimingServerState_Statics::NewProp_Transform_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FAimingServerState_Statics::NewProp_Transform = { "Transform", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAimingServerState, Transform), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(Z_Construct_UScriptStruct_FAimingServerState_Statics::NewProp_Transform_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAimingServerState_Statics::NewProp_Transform_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAimingServerState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAimingServerState_Statics::NewProp_Transform,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAimingServerState_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineCowboyGame,
		nullptr,
		&NewStructOps,
		"AimingServerState",
		sizeof(FAimingServerState),
		alignof(FAimingServerState),
		Z_Construct_UScriptStruct_FAimingServerState_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAimingServerState_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAimingServerState_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAimingServerState_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAimingServerState()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAimingServerState_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineCowboyGame();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AimingServerState"), sizeof(FAimingServerState), Get_Z_Construct_UScriptStruct_FAimingServerState_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAimingServerState_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAimingServerState_Hash() { return 2950976495U; }
class UScriptStruct* FMouseMove::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern ONLINECOWBOYGAME_API uint32 Get_Z_Construct_UScriptStruct_FMouseMove_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMouseMove, Z_Construct_UPackage__Script_OnlineCowboyGame(), TEXT("MouseMove"), sizeof(FMouseMove), Get_Z_Construct_UScriptStruct_FMouseMove_Hash());
	}
	return Singleton;
}
template<> ONLINECOWBOYGAME_API UScriptStruct* StaticStruct<FMouseMove>()
{
	return FMouseMove::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMouseMove(FMouseMove::StaticStruct, TEXT("/Script/OnlineCowboyGame"), TEXT("MouseMove"), false, nullptr, nullptr);
static struct FScriptStruct_OnlineCowboyGame_StaticRegisterNativesFMouseMove
{
	FScriptStruct_OnlineCowboyGame_StaticRegisterNativesFMouseMove()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MouseMove")),new UScriptStruct::TCppStructOps<FMouseMove>);
	}
} ScriptStruct_OnlineCowboyGame_StaticRegisterNativesFMouseMove;
	struct Z_Construct_UScriptStruct_FMouseMove_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DeltaTime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DeltaTime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Move_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Move;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMouseMove_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMouseMove_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMouseMove>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_DeltaTime_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_DeltaTime = { "DeltaTime", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMouseMove, DeltaTime), METADATA_PARAMS(Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_DeltaTime_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_DeltaTime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_Move_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FMouseMove, Move), Z_Construct_UScriptStruct_FVector2D, METADATA_PARAMS(Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_Move_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_Move_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FMouseMove_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_DeltaTime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FMouseMove_Statics::NewProp_Move,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMouseMove_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineCowboyGame,
		nullptr,
		&NewStructOps,
		"MouseMove",
		sizeof(FMouseMove),
		alignof(FMouseMove),
		Z_Construct_UScriptStruct_FMouseMove_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMouseMove_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMouseMove_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMouseMove_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMouseMove()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMouseMove_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_OnlineCowboyGame();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MouseMove"), sizeof(FMouseMove), Get_Z_Construct_UScriptStruct_FMouseMove_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMouseMove_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMouseMove_Hash() { return 1354924012U; }
	DEFINE_FUNCTION(ACowboyCharacter::execOnRep_ServerState)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnRep_ServerState();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ACowboyCharacter::execServer_SendMove)
	{
		P_GET_STRUCT(FMouseMove,Z_Param_Move);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->Server_SendMove_Validate(Z_Param_Move))
		{
			RPC_ValidateFailed(TEXT("Server_SendMove_Validate"));
			return;
		}
		P_THIS->Server_SendMove_Implementation(Z_Param_Move);
		P_NATIVE_END;
	}
	static FName NAME_ACowboyCharacter_Server_SendMove = FName(TEXT("Server_SendMove"));
	void ACowboyCharacter::Server_SendMove(FMouseMove Move)
	{
		CowboyCharacter_eventServer_SendMove_Parms Parms;
		Parms.Move=Move;
		ProcessEvent(FindFunctionChecked(NAME_ACowboyCharacter_Server_SendMove),&Parms);
	}
	void ACowboyCharacter::StaticRegisterNativesACowboyCharacter()
	{
		UClass* Class = ACowboyCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnRep_ServerState", &ACowboyCharacter::execOnRep_ServerState },
			{ "Server_SendMove", &ACowboyCharacter::execServer_SendMove },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACowboyCharacter, nullptr, "OnRep_ServerState", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00040401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics
	{
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Move;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::NewProp_Move = { "Move", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventServer_SendMove_Parms, Move), Z_Construct_UScriptStruct_FMouseMove, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::NewProp_Move,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACowboyCharacter, nullptr, "Server_SendMove", nullptr, nullptr, sizeof(CowboyCharacter_eventServer_SendMove_Parms), Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80240CC1, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACowboyCharacter_Server_SendMove()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACowboyCharacter_Server_SendMove_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ACowboyCharacter_NoRegister()
	{
		return ACowboyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ACowboyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ServerState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TPPCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TPPCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TPPCameraRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TPPCameraRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TPPAimuthGimbal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TPPAimuthGimbal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CoboyMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CoboyMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CapsuleComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CapsuleComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACowboyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineCowboyGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACowboyCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACowboyCharacter_OnRep_ServerState, "OnRep_ServerState" }, // 3462142398
		{ &Z_Construct_UFunction_ACowboyCharacter_Server_SendMove, "Server_SendMove" }, // 1947159420
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CowboyCharacter.h" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ServerState_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ServerState = { "ServerState", "OnRep_ServerState", (EPropertyFlags)0x0040000100000020, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, ServerState), Z_Construct_UScriptStruct_FAimingServerState, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ServerState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ServerState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera = { "TPPCamera", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot = { "TPPCameraRoot", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPCameraRoot), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal = { "TPPAimuthGimbal", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPAimuthGimbal), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyMesh_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyMesh = { "CoboyMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CoboyMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent = { "CapsuleComponent", nullptr, (EPropertyFlags)0x001000000008001c, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CapsuleComponent), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ServerState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ACowboyCharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ACowboyCharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ACowboyCharacter_Statics::ClassParams = {
		&ACowboyCharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ACowboyCharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ACowboyCharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ACowboyCharacter, 375714166);
	template<> ONLINECOWBOYGAME_API UClass* StaticClass<ACowboyCharacter>()
	{
		return ACowboyCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACowboyCharacter(Z_Construct_UClass_ACowboyCharacter, &ACowboyCharacter::StaticClass, TEXT("/Script/OnlineCowboyGame"), TEXT("ACowboyCharacter"), false, nullptr, nullptr, nullptr);

	void ACowboyCharacter::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_ServerState(TEXT("ServerState"));

		const bool bIsValid = true
			&& Name_ServerState == ClassReps[(int32)ENetFields_Private::ServerState].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in ACowboyCharacter"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACowboyCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
