// Fill out your copyright notice in the Description page of Project Settings.

#include "SierraWorks.h"
#include "DuckBullet.h"


ADuckBullet::ADuckBullet(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	DummyRoot = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));
	RootComponent = DummyRoot;
	PrimaryActorTick.bCanEverTick = true;
	/** called when something overlaps the sphere component */
	OnActorBeginOverlap.AddDynamic(this, &ADuckBullet::OnOverlap);


}


void ADuckBullet::Tick(float DeltaSeconds)
{
}
void ADuckBullet::OnOverlap(AActor* OtherActor)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hello World!"));
}