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
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCapsuleComponent_NoRegister();
// End Cross Module References
	void ACowboyCharacter::StaticRegisterNativesACowboyCharacter()
	{
	}
	UClass* Z_Construct_UClass_ACowboyCharacter_NoRegister()
	{
		return ACowboyCharacter::StaticClass();
	}
	struct Z_Construct_UClass_ACowboyCharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ACowboyCharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "CowboyCharacter.h" },
		{ "ModuleRelativePath", "CowboyCharacter.h" },
	};
#endif
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
		nullptr,
		Z_Construct_UClass_ACowboyCharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
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
	IMPLEMENT_CLASS(ACowboyCharacter, 2061031049);
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
