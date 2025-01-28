#include "PursuitMap.h"

FVector2D PursuitMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime)
{

	FVector2d TargetEstimated = Target->Location + Target->Velocity * 100;
	FVector2D desired_velocity = TargetEstimated - ActorLocation2D;
	desired_velocity = desired_velocity.GetSafeNormal() * MaxSpeed;
	FVector2D steering = desired_velocity - Velocity;

	Velocity += steering * DeltaTime;

	if (Velocity.Size() > MaxSpeed)
	{
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	return Velocity;
}