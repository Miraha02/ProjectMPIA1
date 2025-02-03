// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class EStateEnum : uint8
{
    SEEK UMETA(DisplayName = "Seek"),         // Valeur associée : 0
    FLEE UMETA(DisplayName = "Flee"),       // Valeur associée : 1
    PURSUIT UMETA(DisplayName = "Pursuit"),       // Valeur associée : 2
	ARRIVAL UMETA(DisplayName = "Arrival"),       // Valeur associée : 3
	FOLLOW_PATH UMETA(DisplayName = "Follow Path"),       // Valeur associée : 4
    ONE_WAY UMETA(DisplayName = "One Way"),         // Valeur associé : 5
    TWO_WAYS UMETA(DisplayName = "Two Ways")        // Valeur associé : 6
};