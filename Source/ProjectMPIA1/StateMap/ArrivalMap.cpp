#include "ArrivalMap.h"

#include "../MyGameInstance.h"
#include "AITestsCommon.h"


FVector2D ArrivalMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime)
{

	if (Target->beenReached)
	{
		return FVector2d(0,0);
	}
	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	
	FVector2D desired_velocity = Target->Location - ActorLocation2D;
	float distance = desired_velocity.Length();
	float ramped_speed = MaxSpeed * (distance / 250);
	float clipped_speed = std::min(ramped_speed, MaxSpeed);

	desired_velocity = desired_velocity.GetSafeNormal() * clipped_speed;
	
	FVector2D steering = desired_velocity - Velocity;
	steering*=GameInstance->BrakingFactor;

	Velocity += steering * DeltaTime;

	if (Velocity.Size() > MaxSpeed)
	{
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	// Condition d'arrêt si l'acteur est proche de la cible et sa vitesse est faible
	if ((Target->Location - ActorLocation2D).Size() <= GameInstance->StopDistance && Velocity.Size() < GameInstance->StopSpeed)
	{
		Velocity = FVector2D(0.0f, 0.0f);  // Arrêter l'acteur
		Target->beenReached = true;
	}

	return Velocity;
}
