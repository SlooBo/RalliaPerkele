// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "SierraJattaaRacing.h"
#include "SierraJattaaRacingWheelRear.h"

USierraJattaaRacingWheelRear::USierraJattaaRacingWheelRear(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	ShapeRadius = 35.f;
	ShapeWidth = 10.0f;
	bAffectedByHandbrake = true;
	SteerAngle = 0.f;
}
