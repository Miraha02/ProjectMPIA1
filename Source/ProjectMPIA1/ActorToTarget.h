// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enum/StateEnum.h"
#include "Enum/TargetEnum.h"
#include "ActorToTarget.generated.h"

UCLASS()
class PROJECTMPIA1_API AActorToTarget : public AActor
{
	GENERATED_BODY()

private:
	static const int PATH_SIZE = 15;
	FVector2D path[PATH_SIZE] = {
		FVector2D(208.538, -2207.572),
		FVector2D(1111.495, -947.133),
		FVector2D(1200.725, 758.269),
		FVector2D(341.294, 1350.226),
		FVector2D(388.244, 2284.599),
		FVector2D(-313.202, 2865.887),
		FVector2D(-1212.458, 2299.131),
		FVector2D(-1095.787, 1336.131),
		FVector2D(-508.744, 744.174),
		FVector2D(-532.226, 194.499),
		FVector2D(-959.593, -139.064),
		FVector2D(-1565.421, -439.742),
		FVector2D(-1537.243, -1275.999),
		FVector2D(-674.235, -1669.881),
		FVector2D(-656.067, -2846.988)
	};
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	ETargetEnum State;
	
public:	
	// Sets default values for this actor's properties
	AActorToTarget();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
