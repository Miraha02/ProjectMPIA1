#include "OneWayMap.h"

#include "AITestsCommon.h"
#include "../MyGameInstance.h"

FVector2D OneWayMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime)
{

	if (Velocity == FVector2d().Zero())
	{
		return FVector2d(0, 0);
	}


	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	FVector2d TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
	if (GameInstance->TargetIndex < GameInstance->PathSize - 1) {
		if ((TargetVector2d - ActorLocation2D).Size() <= GameInstance->MinDist)
		{
			GameInstance->TargetIndex++;

			TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
		}
	}

	FVector2D desired_velocity = TargetVector2d - ActorLocation2D;
	float distance = desired_velocity.Length();
	float ramped_speed = MaxSpeed * (distance / 250);
	float clipped_speed = std::min(ramped_speed, MaxSpeed);

	desired_velocity = desired_velocity.GetSafeNormal() * clipped_speed;

	FVector2D steering = desired_velocity - Velocity;
	steering *= GameInstance->BrakingFactor;

	Velocity += steering * DeltaTime;

	if (Velocity.Size() > MaxSpeed)
	{
		Velocity = Velocity.GetSafeNormal() * MaxSpeed;
	}

	if ((TargetVector2d - ActorLocation2D).Size() <= GameInstance->StopDistance && Velocity.Size() < GameInstance->StopSpeed)
	{
		Velocity = FVector2D(0.0f, 0.0f);  // Arrêter l'acteur
	}

	return Velocity;
}