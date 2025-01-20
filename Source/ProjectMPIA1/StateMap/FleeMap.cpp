#include "FleeMap.h"

FVector2D FleeMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity)
{
	FVector2D desired_velocity = ActorLocation2D - Target->Location;
	desired_velocity = desired_velocity.GetSafeNormal() * MaxSpeed;
	FVector2D steering = desired_velocity - Velocity;

	return steering;
}