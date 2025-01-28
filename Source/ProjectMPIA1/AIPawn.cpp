// Fill out your copyright notice in the Description page of Project Settings.


#include "AIPawn.h"

#include "StateMap/ArrivalMap.h"
#include "StateMap/SeekMap.h"
#include "StateMap/FleeMap.h"
#include "StateMap/PursuitMap.h"
#include "StateMap/EvadeMap.h"
#include "StateMap/ArrivalMap.h"
#include "StateMap/PathFollowingMap.h"

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
	MyMap.Add(EStateEnum::FOLLOW_PATH, new PathFollowingMap());
	MyMap.Add(EStateEnum::ARRIVAL, new ArrivalMap());
	
}

// Called every frame
void AAIPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector2D ActorLocation2D = FVector2D(GetActorLocation().X, GetActorLocation().Y);

	if (Target == nullptr)
	{
		Target = GetWorld()->SpawnActor<AActorToTarget>(
			AActorToTarget::StaticClass(),
			FVector(0.0f, 0.0f, 0.0f),
			FRotator(0.0f, 0.0f, 0.0f)
		);
		
		if (Target)
		{
			Target->SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
		}
	}

	Velocity = MyMap[State]->behave(Target, ActorLocation2D, MaxSpeed, Velocity, DeltaTime);
	
	// Calculer la direction à partir de la vélocité (sans la composante Z)
	FVector Direction = FVector(Velocity.X, Velocity.Y, 0.0f).GetSafeNormal();

	// Si on ne bouge plus, on update pas la rotation
	if (Velocity == FVector2d(0,0))
	{
		return;
	}
	
	// Créer une rotation en fonction de la direction
	FRotator NewRotation = Direction.Rotation();

	// Appliquer la rotation et déplacer l'acteur
	SetActorRotation(NewRotation);
	SetActorLocation(GetActorLocation() + FVector(Velocity.X, Velocity.Y, 0.0f));

}

// Called to bind functionality to input
void AAIPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}