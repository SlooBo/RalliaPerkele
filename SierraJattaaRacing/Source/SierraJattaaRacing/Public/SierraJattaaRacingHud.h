// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/HUD.h"
#include "SierraJattaaRacingHUD.generated.h"


UCLASS(config = Game)
class ASierraJattaaRacingHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	/** Font used to render the vehicle info */
	UPROPERTY()
	UFont* HUDFont;

	// Begin AHUD interface
	virtual void DrawHUD() override;
	// End AHUD interface

private:

};
