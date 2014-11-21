// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SierraJattaaRacing.h"
#include "SierraJattaaRacingGameMode.h"
#include "SierraJattaaRacingPawn.h"
#include "SierraJattaaRacingHUD.h"

ASierraJattaaRacingGameMode::ASierraJattaaRacingGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DefaultPawnClass = ASierraJattaaRacingPawn::StaticClass();
	HUDClass = ASierraJattaaRacingHUD::StaticClass();
}
