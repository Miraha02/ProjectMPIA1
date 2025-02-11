// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 *
 */

UENUM(Blueprintable)
enum class ETargetEnum : uint8
{
    IDLE UMETA(DisplayName = "Idle"),         // Valeur associ�e : 0
    GO_ON UMETA(DisplayName = "Go on"),       // Valeur associ�e : 1
    EVADE UMETA(DisplayName = "Evade"),       // Valeur associ�e : 2
};