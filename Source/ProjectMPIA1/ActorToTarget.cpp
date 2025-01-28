// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToTarget.h"

#include "AITestsCommon.h"
#include "MyGameInstance.h"

// Sets default values
AActorToTarget::AActorToTarget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorToTarget::BeginPlay()
{
	Super::BeginPlay();
	
	Velocity = FVector2d(0, 0);

	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	MaxSpeed = GameInstance->TargetMaxSpeed;
}

// Called every frame
void AActorToTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Location = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	
	FVector2D steering = FVector2d(0, 0);

	switch (State)
	{
	case ETargetEnum::IDLE:
		return;
	case ETargetEnum::EVADE:
		break;
	case ETargetEnum::GO_ON:

		FVector2d Target =  FVector2D(GetActorLocation().X + 1, GetActorLocation().Y +1);
		FVector2D desired_velocity = Target - Location;
		desired_velocity = desired_velocity.GetSafeNormal() * MaxSpeed;
		steering = desired_velocity - Velocity;
		
		steering.X += FMath::RandRange(-100.0f, 100.0f);
		steering.Y += FMath::RandRange(-100.0f, 100.0f);
		break;
	default:
		break;
	}

	Velocity += steering * DeltaTime;

	if (Velocity.Size() > MaxSpeed) {
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	FVector Direction = FVector(Velocity.X, Velocity.Y, 0.0f).GetSafeNormal();

	FRotator NewRotation = Direction.Rotation();

	SetActorRotation(NewRotation);

	FVector NewLocation = GetActorLocation() + FVector(Velocity.X, Velocity.Y, 0.0f);
	if (NewLocation.Y > GameInstance->LeftLimit)
	{
		NewLocation.Y = GameInstance->RightLimit;
	} else if (NewLocation.Y < GameInstance->RightLimit)
	{
		NewLocation.Y = GameInstance->LeftLimit;
	}
	if (NewLocation.X < GameInstance->UpLimit)
	{
		NewLocation.X = GameInstance->DownLimit;
	} else if (NewLocation.X > GameInstance->DownLimit)
	{
		NewLocation.X = GameInstance->UpLimit;
	}
	SetActorLocation(NewLocation);
}