// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DuckBullet.generated.h"

/**
 * 
 */
UCLASS()
class SIERRAWORKS_API ADuckBullet : public AActor
{
	GENERATED_UCLASS_BODY()

		TSubobjectPtr<class USceneComponent> DummyRoot;
	virtual void Tick(float DeltaSeconds) override;
		void OnOverlap(AActor* OtherActor);

};
