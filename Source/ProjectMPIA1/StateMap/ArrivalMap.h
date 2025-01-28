#pragma once
#include "StateMapper.h"

class ArrivalMap : public StateMapper
{
	FVector2D behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime) override;
};
