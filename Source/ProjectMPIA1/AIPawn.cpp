// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPawn.h"
#include "StateMap/SeekMap.h"
#include "StateMap/FleeMap.h"
#include "StateMap/PursuitMap.h"
#include "StateMap/EvadeMap.h"

// Sets default values
AAIPawn::AAIPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIPawn::BeginPlay()
{
	Super::BeginPlay();

	MyMap.Add(EStateEnum::SEEK, new SeekMap());
	MyMap.Add(EStateEnum::FLEE, new FleeMap());
	MyMap.Add(EStateEnum::PURSUIT, new PursuitMap());
	MyMap.Add(EStateEnum::EVADE, new EvadeMap());
	
}

// Called every frame
void AAIPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector2D ActorLocation2D = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	if (Target == nullptr){return;}
	FVector2D steering = MyMap[State]->behave(Target, ActorLocation2D, MaxSpeed, Velocity);

	Velocity += steering * DeltaTime;

	if (Velocity.Size() > MaxSpeed) {
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}


	// Calculer la direction � partir de la v�locit� (sans la composante Z)
	FVector Direction = FVector(Velocity.X, Velocity.Y, 0.0f).GetSafeNormal();

	// Cr�er une rotation en fonction de la direction
	FRotator NewRotation = Direction.Rotation();

	// Appliquer la rotation et d�placer l'acteur
	SetActorRotation(NewRotation);
	SetActorLocation(GetActorLocation() + FVector(Velocity.X, Velocity.Y, 0.0f));

}

// Called to bind functionality to input
void AAIPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}