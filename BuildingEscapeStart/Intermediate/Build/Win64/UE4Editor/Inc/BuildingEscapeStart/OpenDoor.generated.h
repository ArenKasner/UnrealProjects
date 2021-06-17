// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BUILDINGESCAPESTART_OpenDoor_generated_h
#error "OpenDoor.generated.h already included, missing '#pragma once' in OpenDoor.h"
#endif
#define BUILDINGESCAPESTART_OpenDoor_generated_h

#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_SPARSE_DATA
#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_RPC_WRAPPERS
#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend struct Z_Construct_UClass_UOpenDoor_Statics; \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BuildingEscapeStart"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor)


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUOpenDoor(); \
	friend struct Z_Construct_UClass_UOpenDoor_Statics; \
public: \
	DECLARE_CLASS(UOpenDoor, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BuildingEscapeStart"), NO_API) \
	DECLARE_SERIALIZER(UOpenDoor)


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UOpenDoor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UOpenDoor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public:


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UOpenDoor(UOpenDoor&&); \
	NO_API UOpenDoor(const UOpenDoor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UOpenDoor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UOpenDoor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UOpenDoor)


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__TargetYaw() { return STRUCT_OFFSET(UOpenDoor, TargetYaw); } \
	FORCEINLINE static uint32 __PPO__PressurePlate() { return STRUCT_OFFSET(UOpenDoor, PressurePlate); } \
	FORCEINLINE static uint32 __PPO__ActorThatOpens() { return STRUCT_OFFSET(UOpenDoor, ActorThatOpens); } \
	FORCEINLINE static uint32 __PPO__DoorCloseDelay() { return STRUCT_OFFSET(UOpenDoor, DoorCloseDelay); } \
	FORCEINLINE static uint32 __PPO__DoorCloseSpeed() { return STRUCT_OFFSET(UOpenDoor, DoorCloseSpeed); } \
	FORCEINLINE static uint32 __PPO__DoorOpenSpeed() { return STRUCT_OFFSET(UOpenDoor, DoorOpenSpeed); }


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_12_PROLOG
#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_PRIVATE_PROPERTY_OFFSET \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_SPARSE_DATA \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_RPC_WRAPPERS \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_INCLASS \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_PRIVATE_PROPERTY_OFFSET \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_SPARSE_DATA \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_INCLASS_NO_PURE_DECLS \
	BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BUILDINGESCAPESTART_API UClass* StaticClass<class UOpenDoor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BuildingEscapeStart_Source_BuildingEscapeStart_OpenDoor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
