// Fill out your copyright notice in the Description page of Project Settings.

#include "SierraWorks.h"
#include "DuckTower.h"
ADuckTower::ADuckTower(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	static ConstructorHelpers::FObjectFinder<UBlueprint>MyObj(TEXT("Blueprint'/Game/Blueprints/Duckannon'"));
	BulletBlueprint = (UClass*)MyObj.Object->GeneratedClass;

	shootTimer = 2.0f;
	DummyRoot = PCIP.CreateDefaultSubobject<USceneComponent>(this, TEXT("RootComponent"));
	RootComponent = DummyRoot;
	PrimaryActorTick.bCanEverTick = true;
}


void ADuckTower::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hello World!"));
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(shootTimer));
	}

}
void ADuckTower::Tick(float DeltaSeconds)
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
	APawn *player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn();
	FVector actor2 = player->GetActorLocation(); //+ player->GetRootPrimitiveComponent()->GetPhysicsLinearVelocity() *DeltaSeconds * 10;
	FVector actor = GetAttachParentActor()->GetActorLocation();
	FVector Direction = actor - actor2;
	FRotator test = FRotationMatrix::MakeFromX(Direction).Rotator();
	FRotator test2 = FRotator(1.0f, 0.0f, 0.0f);
	FRotator finalrot = FRotator(test.Quaternion() * test2.Quaternion());

	FVector vec2 = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorLocation();
	FVector vec = GetAttachParentActor()->GetActorLocation();
	float distance = FVector::Dist(actor, actor2);

	finalrot.Pitch -= 10- distance / 10000 * 10;
	GetAttachParentActor()->SetActorRotation(finalrot);
	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(EKeys::I))
	{

	}
	if (shootTimer <= 0.f)
	{


		Shoot(distance);
		shootTimer = 2.f;
	}
	else
		shootTimer -= DeltaSeconds;
	//GetAttachParentActor()->GetRootPrimitiveComponent()->AddImpulse(UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn()->GetActorForwardVector());
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::FromInt(testNumber));
	//GetAttachParentActor()->SetActorRotation()
}
void ADuckTower::Shoot(float distance)
{
	/*
	const FName filename = FName(TEXT("Blueprint'/Game/Blueprints/PickUp.PickUp'"));
	FVector loc = GetAttachParentActor()->GetActorLocation();
	FRotator rot = GetAttachParentActor()->GetActorRotation();
	SpawnBP(GetWorld(), (UClass*)LoadObjFromPath<UBlueprint>(&filename), loc, rot);
	*/
	APawn *player = UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetControlledPawn();
	int randomValue = distance / 10000;
	FVector vec = player->GetActorLocation() + FVector(FMath::RandRange(-randomValue, randomValue), FMath::RandRange(-randomValue, randomValue), 0.0f); //+ player->GetRootPrimitiveComponent()->GetPhysicsLinearVelocity() *DeltaSeconds * 10;
	FVector vec2 = GetAttachParentActor()->GetActorLocation();
	FVector Direction = vec - vec2;
	FRotator test = FRotationMatrix::MakeFromX(Direction).Rotator();
	FRotator test2 = FRotator(1.0f, 0.0f, 0.0f);
	FRotator finalrot = FRotator(test.Quaternion() * test2.Quaternion());


	FVector forward = GetAttachParentActor()->GetActorForwardVector();
	forward.X = -forward.X;
	forward.Y = -forward.Y;
	forward.Z = -forward.Z;
	FVector loc = GetAttachParentActor()->GetActorLocation()+ forward * 500.0f;
	FRotator rot = GetAttachParentActor()->GetActorRotation();
	AActor* actor = GetWorld()->SpawnActor<AActor>(BulletBlueprint, loc, finalrot);

	//actor->GetRootPrimitiveComponent()->AddImpulse(actor->GetActorForwardVector()* 5000.0f);
	actor->GetRootPrimitiveComponent()->SetEnableGravity(false);
	actor->GetRootPrimitiveComponent()->SetPhysicsLinearVelocity(actor->GetActorForwardVector()*10000.0f); //* (distance/10000 * 1.0f));
}