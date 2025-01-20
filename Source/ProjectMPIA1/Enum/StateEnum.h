// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */

UENUM(Blueprintable)
enum class EStateEnum : uint8
{
    SEEK UMETA(DisplayName = "Seek"),         // Valeur associ�e : 0
    FLEE UMETA(DisplayName = "Flee"),       // Valeur associ�e : 1
    PURSUIT UMETA(DisplayName = "Pursuit"),       // Valeur associ�e : 2
    EVADE UMETA(DisplayName = "Evade")       // Valeur associ�e : 3
};