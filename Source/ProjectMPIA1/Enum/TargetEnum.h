// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */

UENUM(Blueprintable)
enum class ETargetEnum : uint8
{
    IDLE UMETA(DisplayName = "Idle"),         // Valeur associée : 0
    GO_ON UMETA(DisplayName = "Go on"),       // Valeur associée : 1
    EVADE UMETA(DisplayName = "Evade"),       // Valeur associée : 2
};