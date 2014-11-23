// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DuckTower.generated.h"

/**
*
*/
UCLASS()

class SIERRAWORKS_API ADuckTower : public AActor
{
	GENERATED_UCLASS_BODY()
		float shootTimer;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	TSubobjectPtr<class USceneComponent> DummyRoot;
	void Shoot(float distance);
	TSubclassOf<class AActor> BulletBlueprint;


};
