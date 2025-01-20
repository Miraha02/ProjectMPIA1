#include "PursuitMap.h"

FVector2D PursuitMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity)
{
	FVector2D desired_velocity = Target->Location - ActorLocation2D;
	desired_velocity = desired_velocity.GetSafeNormal() * MaxSpeed;
	FVector2D steering = desired_velocity - Velocity;

	return steering;
}