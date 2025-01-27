#pragma once

#include "CoreMinimal.h"
#include "../ActorToTarget.h"

class StateMapper
{
public:
    // Méthodes pour manipuler la map
    virtual FVector2D behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime);
};
