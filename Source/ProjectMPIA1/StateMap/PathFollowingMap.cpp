#include "PathFollowingMap.h"

#include "AITestsCommon.h"
#include "../MyGameInstance.h"

FVector2D PathFollowingMap::behave(AActorToTarget* Target, FVector2D ActorLocation2D, float MaxSpeed, FVector2D Velocity)
{
	UMyGameInstance* GameInstance = UMyGameInstance::GetMyGameInstance(FAITestHelpers::GetWorld());
	
	FVector2d TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
	if ((TargetVector2d - ActorLocation2D).Size() <= GameInstance->MinDist)
	{
		GameInstance->TargetIndex = (GameInstance->TargetIndex + 1) % GameInstance->PathSize;

		TargetVector2d = GameInstance->GetPath()[GameInstance->TargetIndex];
	}
	
	FVector2D desired_velocity = TargetVector2d - ActorLocation2D;
	desired_velocity = desired_velocity.GetSafeNormal() * MaxSpeed;
	FVector2D steering = desired_velocity - Velocity;

	return steering;
}