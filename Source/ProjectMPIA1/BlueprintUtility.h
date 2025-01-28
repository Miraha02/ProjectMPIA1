// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enum/StateEnum.h"
#include "Enum/TargetEnum.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintUtility.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTMPIA1_API UBlueprintUtility : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	// Fonction pour obtenir toutes les valeurs de l'�num�ration
	UFUNCTION(BlueprintPure, Category = "Utilities|Enum")
	static TArray<EStateEnum> GetAllEnumValues();

	UFUNCTION(BlueprintPure, Category = "Utilities|Enum")
	static TArray<ETargetEnum> GetAllTargetEnumValues();
};
