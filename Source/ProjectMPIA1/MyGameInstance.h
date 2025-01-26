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
	// Path defined as a TArray
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Blueprintable, Category = "Path")
	float MinDist;

	// Path size defined as a UPROPERTY, editable in the editor
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Path")
	int32 PathSize = 15;
	
	int TargetIndex = 0;
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
