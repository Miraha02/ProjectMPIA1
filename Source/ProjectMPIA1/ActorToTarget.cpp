// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorToTarget.h"

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
	
}

// Called every frame
void AActorToTarget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (State)
	{
	case ETargetEnum::IDLE:
		return;
	case ETargetEnum::PURSUIT:
		break;
	case ETargetEnum::EVADE:
		break;
	case ETargetEnum::GO_ON:
		Location = FVector2D(GetActorLocation().X, GetActorLocation().Y);

		Velocity *= DeltaTime;

		if (Velocity.Size() > MaxSpeed) {
			Velocity = Velocity.GetSafeNormal() * MaxSpeed;
		}

		FVector Direction = FVector(Velocity.X, Velocity.Y, 0.0f).GetSafeNormal();

		FRotator NewRotation = Direction.Rotation();

		SetActorRotation(NewRotation);
		SetActorLocation(GetActorLocation() + FVector(Velocity.X, Velocity.Y, 0.0f));
		break;
	default:
		break;
	}

	Location = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	Velocity *= DeltaTime;

	if (Velocity.Size() > MaxSpeed) {
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	FVector Direction = FVector(Velocity.X, Velocity.Y, 0.0f).GetSafeNormal();

	FRotator NewRotation = Direction.Rotation();

	SetActorRotation(NewRotation);
	SetActorLocation(GetActorLocation() + FVector(Velocity.X, Velocity.Y, 0.0f));
}

