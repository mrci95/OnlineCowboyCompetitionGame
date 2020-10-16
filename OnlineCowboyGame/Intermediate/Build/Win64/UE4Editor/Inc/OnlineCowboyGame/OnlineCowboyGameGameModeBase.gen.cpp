// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OnlineCowboyGame/OnlineCowboyGameGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeOnlineCowboyGameGameModeBase() {}
// Cross Module References
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_AOnlineCowboyGameGameModeBase_NoRegister();
	ONLINECOWBOYGAME_API UClass* Z_Construct_UClass_AOnlineCowboyGameGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_OnlineCowboyGame();
// End Cross Module References
	void AOnlineCowboyGameGameModeBase::StaticRegisterNativesAOnlineCowboyGameGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AOnlineCowboyGameGameModeBase_NoRegister()
	{
		return AOnlineCowboyGameGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_OnlineCowboyGame,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "OnlineCowboyGameGameModeBase.h" },
		{ "ModuleRelativePath", "OnlineCowboyGameGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AOnlineCowboyGameGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::ClassParams = {
		&AOnlineCowboyGameGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AOnlineCowboyGameGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AOnlineCowboyGameGameModeBase, 1119142311);
	template<> ONLINECOWBOYGAME_API UClass* StaticClass<AOnlineCowboyGameGameModeBase>()
	{
		return AOnlineCowboyGameGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AOnlineCowboyGameGameModeBase(Z_Construct_UClass_AOnlineCowboyGameGameModeBase, &AOnlineCowboyGameGameModeBase::StaticClass, TEXT("/Script/OnlineCowboyGame"), TEXT("AOnlineCowboyGameGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AOnlineCowboyGameGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
