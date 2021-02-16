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
	DEFINE_FUNCTION(AOnlineCowboyGameGameModeBase::execSetFPP)
	{
		P_GET_UBOOL(Z_Param_FPPAvailable);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetFPP(Z_Param_FPPAvailable);
		P_NATIVE_END;
	}
	void AOnlineCowboyGameGameModeBase::StaticRegisterNativesAOnlineCowboyGameGameModeBase()
	{
		UClass* Class = AOnlineCowboyGameGameModeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "SetFPP", &AOnlineCowboyGameGameModeBase::execSetFPP },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics
	{
		struct OnlineCowboyGameGameModeBase_eventSetFPP_Parms
		{
			bool FPPAvailable;
		};
		static void NewProp_FPPAvailable_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_FPPAvailable;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::NewProp_FPPAvailable_SetBit(void* Obj)
	{
		((OnlineCowboyGameGameModeBase_eventSetFPP_Parms*)Obj)->FPPAvailable = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::NewProp_FPPAvailable = { "FPPAvailable", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(OnlineCowboyGameGameModeBase_eventSetFPP_Parms), &Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::NewProp_FPPAvailable_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::NewProp_FPPAvailable,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "OnlineCowboyGameGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AOnlineCowboyGameGameModeBase, nullptr, "SetFPP", nullptr, nullptr, sizeof(OnlineCowboyGameGameModeBase_eventSetFPP_Parms), Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020601, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AOnlineCowboyGameGameModeBase_NoRegister()
	{
		return AOnlineCowboyGameGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AOnlineCowboyGameGameModeBase_SetFPP, "SetFPP" }, // 2933034718
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AOnlineCowboyGameGameModeBase_Statics::Class_MetaDataParams[] = {
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AOnlineCowboyGameGameModeBase, 1777403736);
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
