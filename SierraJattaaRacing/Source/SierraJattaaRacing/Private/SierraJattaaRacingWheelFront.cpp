// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SierraJattaaRacing.h"
#include "SierraJattaaRacingWheelFront.h"

USierraJattaaRacingWheelFront::USierraJattaaRacingWheelFront(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	ShapeRadius = 35.f;
	ShapeWidth = 10.0f;
	bAffectedByHandbrake = false;
	SteerAngle = 50.f;
}
