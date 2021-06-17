// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BuildingEscapeStart/BuildingEscapeStartGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBuildingEscapeStartGameModeBase() {}
// Cross Module References
	BUILDINGESCAPESTART_API UClass* Z_Construct_UClass_ABuildingEscapeStartGameModeBase_NoRegister();
	BUILDINGESCAPESTART_API UClass* Z_Construct_UClass_ABuildingEscapeStartGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_BuildingEscapeStart();
// End Cross Module References
	void ABuildingEscapeStartGameModeBase::StaticRegisterNativesABuildingEscapeStartGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_ABuildingEscapeStartGameModeBase_NoRegister()
	{
		return ABuildingEscapeStartGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_BuildingEscapeStart,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "BuildingEscapeStartGameModeBase.h" },
		{ "ModuleRelativePath", "BuildingEscapeStartGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABuildingEscapeStartGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::ClassParams = {
		&ABuildingEscapeStartGameModeBase::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABuildingEscapeStartGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABuildingEscapeStartGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABuildingEscapeStartGameModeBase, 1403355764);
	template<> BUILDINGESCAPESTART_API UClass* StaticClass<ABuildingEscapeStartGameModeBase>()
	{
		return ABuildingEscapeStartGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABuildingEscapeStartGameModeBase(Z_Construct_UClass_ABuildingEscapeStartGameModeBase, &ABuildingEscapeStartGameModeBase::StaticClass, TEXT("/Script/BuildingEscapeStart"), TEXT("ABuildingEscapeStartGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABuildingEscapeStartGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
