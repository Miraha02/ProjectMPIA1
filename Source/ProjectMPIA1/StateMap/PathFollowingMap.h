#pragma once

#include "CoreMinimal.h"
#include "StateMapper.h"

class PathFollowingMap : public StateMapper
{
	FVector2D behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime) override;
};
