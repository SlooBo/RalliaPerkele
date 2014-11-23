// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RocketTower.generated.h"

/**
*
*/
UCLASS()
class SIERRAWORKS_API ARocketTower : public AActor
{
	GENERATED_UCLASS_BODY()
		virtual void Tick(float DeltaSeconds) override;
	TSubobjectPtr<class USceneComponent> DummyRoot;
	void Shoot();
	TSubclassOf<class AActor> BulletBlueprint;

	float shootTimer;
};
