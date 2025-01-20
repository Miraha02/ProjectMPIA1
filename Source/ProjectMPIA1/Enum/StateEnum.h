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
    EVADE UMETA(DisplayName = "Evade")       // Valeur associée : 3
};