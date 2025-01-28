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
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D Location;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MaxSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	ETargetEnum State;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D FleeLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D FleeVelocity;
	
	bool beenReached=false;
	
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
