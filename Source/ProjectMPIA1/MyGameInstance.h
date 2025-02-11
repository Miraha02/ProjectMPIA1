#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * Custom GameInstance class to store a predefined path of FVector2D points.
 */
UCLASS()
class PROJECTMPIA1_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float TargetMaxSpeed = 15;
	// Path defined as a TArray
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable, Category = "Path")
	float MinDist;

	// Path size defined as a UPROPERTY, editable in the editor
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	int32 PathSize = 15;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	int TargetIndex = 0;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	bool Reverse = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float BrakingFactor = 2;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float PathFactor = 2;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float StopDistance = 25;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float BreakingDistance = 250;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float StopSpeed = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float UpLimit = 1845.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float DownLimit = -2210.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float LeftLimit = 3685.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	float RightLimit = -3545.f;
public:
	// Getter for the path
	UFUNCTION(BlueprintCallable, Category = "Path")
	const TArray<FVector2D>& GetPath() const { return Path; }

	// Static helper function to retrieve the GameInstance
	static UMyGameInstance* GetMyGameInstance(UWorld* World);

protected:
	// Path defined as a TArray
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	TArray<FVector2D> Path;

	// Called when the game instance initializes
	virtual void Init() override;
};
