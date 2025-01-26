// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum/StateEnum.h"
#include "StateMap/StateMapper.h"
#include "GameFramework/Pawn.h"
#include "ActorToTarget.h"
#include "AIPawn.generated.h"

UCLASS()
class PROJECTMPIA1_API AAIPawn : public APawn
{
	GENERATED_BODY()
private:
	TMap<EStateEnum, StateMapper*> MyMap;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	AActorToTarget* Target;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	FVector2D Velocity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float MaxSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	float SLowingDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
	EStateEnum State;

	// Sets default values for this pawn's properties
	AAIPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
