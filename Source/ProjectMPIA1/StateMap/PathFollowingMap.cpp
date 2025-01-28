#include "PathFollowingMap.h"

#include "AITestsCommon.h"
#include "../MyGameInstance.h"
#include "SeekMap.h"

FVector2D PathFollowingMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity, float DeltaTime)
{
	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	
	FVector2d TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
	if ((TargetVector2d - ActorLocation2D).Size() <= GameInstance->MinDist)
	{
		GameInstance->TargetIndex = (GameInstance->TargetIndex + 1) % GameInstance->PathSize;

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