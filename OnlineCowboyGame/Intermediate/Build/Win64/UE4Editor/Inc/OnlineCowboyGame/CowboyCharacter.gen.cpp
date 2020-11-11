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
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_ACowboyCharacter_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_ACowboyCharacter();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_OnlineCowboyGame();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_AWeaponBase_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UFPPAimingComponent_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UTPPAimingComponent_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UViewComponent_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UMovementReplicator_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UCowboyMovement_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USkeletalMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_UGameStateInterface_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ACowboyCharacter::execOnCowobyHit)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_HitComp);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_STRUCT(FVector,Z_Param_NormalImpulse);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_Hit);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCowobyHit(Z_Param_HitComp,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_NormalImpulse,Z_Param_Out_Hit);
		P_NATIVE_END;
	}
	void ACowboyCharacter::StaticRegisterNativesACowboyCharacter()
	{
		UClass* Class = ACowboyCharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnCowobyHit", &ACowboyCharacter::execOnCowobyHit },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics
	{
		struct CowboyCharacter_eventOnCowobyHit_Parms
		{
			UPrimitiveComponent* HitComp;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			FVector NormalImpulse;
			FHitResult Hit;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Hit_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Hit;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_NormalImpulse;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HitComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_Hit_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_Hit = { "Hit", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventOnCowobyHit_Parms, Hit), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_Hit_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_Hit_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_NormalImpulse = { "NormalImpulse", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventOnCowobyHit_Parms, NormalImpulse), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventOnCowobyHit_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventOnCowobyHit_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_HitComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_HitComp = { "HitComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(CowboyCharacter_eventOnCowobyHit_Parms, HitComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_HitComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_HitComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_Hit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_NormalImpulse,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::NewProp_HitComp,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ACowboyCharacter, nullptr, "OnCowobyHit", nullptr, nullptr, sizeof(CowboyCharacter_eventOnCowobyHit_Parms), Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00C40401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit_Statics::FuncParams);
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TPPWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TPPWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPPWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPPWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Weapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_Weapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPPAimingComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPPAimingComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TPPAimingComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_TPPAimingComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ViewComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ViewComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CowboyMovementReplicator_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CowboyMovementReplicator;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CowboyMovementComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CowboyMovementComponent;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPPCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPPCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPPCameraRoot_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPPCameraRoot;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FPPAimuthGimbal_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FPPAimuthGimbal;
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
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CowboyFppMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CowboyFppMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CoboyTppMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CoboyTppMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CapsuleComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CapsuleComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FImplementedInterfaceParams InterfaceParams[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ACowboyCharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineCowboyGame,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ACowboyCharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ACowboyCharacter_OnCowobyHit, "OnCowobyHit" }, // 176935617
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CowboyCharacter.h" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPWeapon_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPWeapon = { "TPPWeapon", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPWeapon), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPWeapon_MetaData[] = {
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPWeapon = { "FPPWeapon", nullptr, (EPropertyFlags)0x0010000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, FPPWeapon), Z_Construct_UClass_AWeaponBase_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_Weapon_MetaData[] = {
		{ "Category", "Setup" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_Weapon = { "Weapon", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, Weapon), Z_Construct_UClass_AWeaponBase_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_Weapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_Weapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimingComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimingComponent = { "FPPAimingComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, FPPAimingComponent), Z_Construct_UClass_UFPPAimingComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimingComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimingComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimingComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimingComponent = { "TPPAimingComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPAimingComponent), Z_Construct_UClass_UTPPAimingComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimingComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimingComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ViewComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ViewComponent = { "ViewComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, ViewComponent), Z_Construct_UClass_UViewComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ViewComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ViewComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementReplicator_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementReplicator = { "CowboyMovementReplicator", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CowboyMovementReplicator), Z_Construct_UClass_UMovementReplicator_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementReplicator_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementReplicator_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementComponent = { "CowboyMovementComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CowboyMovementComponent), Z_Construct_UClass_UCowboyMovement_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementComponent_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCamera_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCamera = { "FPPCamera", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, FPPCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCameraRoot_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCameraRoot = { "FPPCameraRoot", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, FPPCameraRoot), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCameraRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCameraRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimuthGimbal_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimuthGimbal = { "FPPAimuthGimbal", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, FPPAimuthGimbal), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimuthGimbal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimuthGimbal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera = { "TPPCamera", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot = { "TPPCameraRoot", nullptr, (EPropertyFlags)0x00100000000a000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPCameraRoot), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal = { "TPPAimuthGimbal", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, TPPAimuthGimbal), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyFppMesh_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyFppMesh = { "CowboyFppMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CowboyFppMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyFppMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyFppMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyTppMesh_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyTppMesh = { "CoboyTppMesh", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CoboyTppMesh), Z_Construct_UClass_USkeletalMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyTppMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyTppMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData[] = {
		{ "Category", "CowboyCharacter" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent = { "CapsuleComponent", nullptr, (EPropertyFlags)0x00100000000a0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ACowboyCharacter, CapsuleComponent), Z_Construct_UClass_UCapsuleComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_Weapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimingComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimingComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_ViewComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementReplicator,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyMovementComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPCameraRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_FPPAimuthGimbal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPCameraRoot,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_TPPAimuthGimbal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CowboyFppMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CoboyTppMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ACowboyCharacter_Statics::NewProp_CapsuleComponent,
	};
		const UE4CodeGen_Private::FImplementedInterfaceParams Z_Construct_UClass_ACowboyCharacter_Statics::InterfaceParams[] = {
			{ Z_Construct_UClass_UGameStateInterface_NoRegister, (int32)VTABLE_OFFSET(ACowboyCharacter, IGameStateInterface), false },
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
		InterfaceParams,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers),
		UE_ARRAY_COUNT(InterfaceParams),
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
	IMPLEMENT_CLASS(ACowboyCharacter, 164605627);
	template<> ONLINECOWBOYGAME_API UClass* StaticClass<ACowboyCharacter>()
	{
		return ACowboyCharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ACowboyCharacter(Z_Construct_UClass_ACowboyCharacter, &ACowboyCharacter::StaticClass, TEXT("/Script/OnlineCowboyGame"), TEXT("ACowboyCharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ACowboyCharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
