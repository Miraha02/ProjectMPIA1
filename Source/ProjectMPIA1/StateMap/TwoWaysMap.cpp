#include "TwoWaysMap.h"

#include "AITestsCommon.h"
#include "../MyGameInstance.h"

FVector2D TwoWaysMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime)
{
	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());

	FVector2d TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
	if ((TargetVector2d - ActorLocation2D).Size() <= GameInstance->MinDist)
	{
		if (GameInstance->TargetIndex == GameInstance->PathSize - 1 || GameInstance->TargetIndex == 0) {
			GameInstance->Reverse = GameInstance->Reverse ^ 1;
		}
		int next = GameInstance->Reverse ? -1 : 1;
		GameInstance->TargetIndex = (GameInstance->TargetIndex + next);

		TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
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

	return Velocity;
}