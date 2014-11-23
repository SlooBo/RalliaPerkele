// Fill out your copyright notice in the Description page of Project Settings.

#include "SierraWorks.h"
#include "RocketTower.h"


ARocketTower::ARocketTower(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//static ConstructorHelpers::FObjectFinder<UBlueprint>MyObj(TEXT("Blueprint'/Game/Blueprints/Rokkit'"));
	static ConstructorHelpers::FObjectFinder<UBlueprint>MyObj(TEXT("Blueprint'/Game/Blueprints/Rocket'"));
	BulletBlueprint = (UClass*)MyObj.Object->GeneratedClass;

	shootTimer = 2.0f;
	DummyRoot = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));
	RootComponent = DummyRoot;
	PrimaryActorTick.bCanEverTick = true;
}

void ARocketTower::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	/*
	AActor *actor = GetAttachParentActor();
	FVector actor2 = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorLocation();
	FRotator newRotation = FRotationMatrix::MakeFromX(actor2 - actor->GetActorLocation()).Rotator();
	GetAttachParentActor()->SetActorRotation(newRotation);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, actor->GetName());
	*//*
	FVector actor2 = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorLocation();
	FVector actor = GetAttachParentActor()->GetActorLocation();
	FVector Direction = actor - actor2;
	FRotator test = FRotationMatrix::MakeFromX(Direction).Rotator();
	GetAttachParentActor()->SetActorRotation(test);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, actor2.ToString());
	*/
	//GetAttachParentActor()->SetActorLocation(FVector(0.0f, 0.0f, (float)testNumber));
	//testNumber += 1.f;
	/*
	APawn *player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn();
	FVector actor2 = player->GetActorLocation(); //+ player->GetRootPrimitiveComponent()->GetPhysicsLinearVelocity() *DeltaSeconds * 10;
	FVector actor = GetAttachParentActor()->GetActorLocation();
	FVector Direction = actor - actor2;
	FRotator test = FRotationMatrix::MakeFromX(Direction).Rotator();
	FRotator test2 = FRotator(1.0f, 0.0f, 0.0f);
	FRotator finalrot = FRotator(test.Quaternion() * test2.Quaternion());
	finalrot.Pitch = 0.0f;
	finalrot.Roll = 0.0f;
	FVector vec2 = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorLocation();
	FVector vec = GetAttachParentActor()->GetActorLocation();
	float distance = FVector::Dist(actor, actor2);
	*/
	//GetAttachParentActor()->SetActorRotation(finalrot);
	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(EKeys::I))
	{

	}
	if (shootTimer <= 0.f)
	{


		Shoot();
		shootTimer = 2.f;
	}
	else
		shootTimer -= DeltaSeconds;
	//GetAttachParentActor()->GetRootPrimitiveComponent()->AddImpulse(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorForwardVector());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(testNumber));
	//GetAttachParentActor()->SetActorRotation()
}
void ARocketTower::Shoot()
{
	/*
	const FName filename = FName(TEXT("Blueprint'/Game/Blueprints/PickUp.PickUp'"));
	FVector loc = GetAttachParentActor()->GetActorLocation();
	FRotator rot = GetAttachParentActor()->GetActorRotation();
	SpawnBP(GetWorld(), (UClass*)LoadObjFromPath<UBlueprint>(&filename), loc, rot);
	*/
	/*
	AActor *invisBaseRocket = nullptr;

	for (TActorIterator<AActor> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		if (ActorItr->GetName() == "invisrocket")
		{
			invisBaseRocket = *ActorItr;
		}
	}
	if (invisBaseRocket == nullptr)
		invisBaseRocket = GetAttachParentActor();
	FString name = invisBaseRocket->GetName();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, name);
	FVector invisBaseRocketLoc = invisBaseRocket->GetActorLocation();
	FRotator invisBaseRocketRot = invisBaseRocket->GetActorRotation();
	FVector forward = GetAttachParentActor()->GetActorForwardVector();
	*/
	FVector rocketLocation = FVector(GetActorLocation().X, GetActorLocation().Y-100, GetActorLocation().Z+90);
	FRotator rocketRotation = FRotator(GetActorRotation().Pitch, GetActorRotation().Yaw, GetActorRotation().Roll+ 80);
	AActor* actor = GetWorld()->SpawnActor<AActor>(BulletBlueprint, rocketLocation, rocketRotation);

	//actor->GetRootPrimitiveComponent()->AddImpulse(actor->GetActorForwardVector()* 5000.0f);
	//actor->GetRootPrimitiveComponent()->SetEnableGravity(false);
	//actor->GetRootPrimitiveComponent()->SetPhysicsLinearVelocity(actor->GetActorForwardVector()*10000.0f); //* (distance/10000 * 1.0f));
}


