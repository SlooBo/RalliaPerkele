// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SierraJattaaRacing.h"
#include "SierraJattaaRacingHUD.h"
#include "SierraJattaaRacingPawn.h"
#include "GameFramework/WheeledVehicle.h"
#include "Engine/Canvas.h"
#include "Vehicles/WheeledVehicleMovementComponent.h"
#include "Engine/Font.h"
#include "CanvasItem.h"
// Needed for VR Headset
#include "Engine.h"
#include "IHeadMountedDisplay.h"


#define LOCTEXT_NAMESPACE "VehicleHUD"

ASierraJattaaRacingHUD::ASierraJattaaRacingHUD(const class FPostConstructInitializeProperties& PCIP) 
	: Super(PCIP)
{
	static ConstructorHelpers::FObjectFinder<UFont> Font(TEXT("/Engine/EngineFonts/RobotoDistanceField"));
	HUDFont = Font.Object;
}

void ASierraJattaaRacingHUD::DrawHUD()
{
	Super::DrawHUD();

	// Calculate ratio from 720p
	const float HUDXRatio = Canvas->SizeX / 1280.f;
	const float HUDYRatio = Canvas->SizeY / 720.f;

	// We dont want the onscreen hud when using a HMD device	
	if ((GEngine->HMDDevice.IsValid() == false ) || ((GEngine->HMDDevice.IsValid() == true) && (GEngine->HMDDevice->IsStereoEnabled() == false)))
	{
		// Get our vehicle so we can check if we are in car. If we are we don't want onscreen HUD
		ASierraJattaaRacingPawn* Vehicle = Cast<ASierraJattaaRacingPawn>(GetOwningPawn());
		if ((Vehicle != nullptr) && (Vehicle->bInCarCameraActive == false))
		{
			FVector2D ScaleVec(HUDYRatio * 1.4f, HUDYRatio * 1.4f);

			// Speed
			FCanvasTextItem SpeedTextItem(FVector2D(HUDXRatio * 805.f, HUDYRatio * 455), Vehicle->SpeedDisplayString, HUDFont, FLinearColor::White);
			SpeedTextItem.Scale = ScaleVec;
			Canvas->DrawItem(SpeedTextItem);

			// Gear
			FCanvasTextItem GearTextItem(FVector2D(HUDXRatio * 805.f, HUDYRatio * 500.f), Vehicle->GearDisplayString, HUDFont, Vehicle->bInReverseGear == false ? Vehicle->GearDisplayColor : Vehicle->GearDisplayReverseColor);
			GearTextItem.Scale = ScaleVec;
			Canvas->DrawItem(GearTextItem);
		}
	}
}


#undef LOCTEXT_NAMESPACE