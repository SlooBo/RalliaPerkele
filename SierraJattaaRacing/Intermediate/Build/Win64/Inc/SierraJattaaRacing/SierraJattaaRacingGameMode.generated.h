// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

#ifdef SIERRAJATTAARACING_SierraJattaaRacingGameMode_generated_h
#error "SierraJattaaRacingGameMode.generated.h already included, missing '#pragma once' in SierraJattaaRacingGameMode.h"
#endif
#define SIERRAJATTAARACING_SierraJattaaRacingGameMode_generated_h

#define ASierraJattaaRacingGameMode_EVENTPARMS
#define ASierraJattaaRacingGameMode_RPC_WRAPPERS
#define ASierraJattaaRacingGameMode_CALLBACK_WRAPPERS
#define ASierraJattaaRacingGameMode_INCLASS \
	private: \
	static void StaticRegisterNativesASierraJattaaRacingGameMode(); \
	friend SIERRAJATTAARACING_API class UClass* Z_Construct_UClass_ASierraJattaaRacingGameMode(); \
	public: \
	DECLARE_CLASS(ASierraJattaaRacingGameMode, AGameMode, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, SierraJattaaRacing, SIERRAJATTAARACING_API) \
	/** Standard constructor, called after all reflected properties have been initialized */    SIERRAJATTAARACING_API ASierraJattaaRacingGameMode(const class FPostConstructInitializeProperties& PCIP); \
	DECLARE_SERIALIZER(ASierraJattaaRacingGameMode) \
	/** Indicates whether the class is compiled into the engine */    enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#undef UCLASS_CURRENT_FILE_NAME
#define UCLASS_CURRENT_FILE_NAME ASierraJattaaRacingGameMode


#undef UCLASS
#undef UINTERFACE
#if UE_BUILD_DOCS
#define UCLASS(...)
#else
#define UCLASS(...) \
ASierraJattaaRacingGameMode_EVENTPARMS
#endif


#undef GENERATED_UCLASS_BODY
#undef GENERATED_IINTERFACE_BODY
#define GENERATED_UCLASS_BODY() \
public: \
	ASierraJattaaRacingGameMode_RPC_WRAPPERS \
	ASierraJattaaRacingGameMode_CALLBACK_WRAPPERS \
	ASierraJattaaRacingGameMode_INCLASS \
public:

