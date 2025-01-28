// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintUtility.h"

TArray<EStateEnum> UBlueprintUtility::GetAllEnumValues()
{
    TArray<EStateEnum> Values;

    // Obtenir l'objet UEnum pour l'�num�ration
    const UEnum* EnumPtr = StaticEnum<EStateEnum>();
    if (!EnumPtr)
    {
        return Values; // Retourne un tableau vide en cas d'erreur
    }

    // Parcourir toutes les valeurs de l'�num�ration
    for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i) // -1 pour ignorer "_MAX" ou autres
    {
        Values.Add(static_cast<EStateEnum>(i));
    }

    return Values;
}

TArray<ETargetEnum> UBlueprintUtility::GetAllTargetEnumValues()
{
    TArray<ETargetEnum> Values;

    // Obtenir l'objet UEnum pour l'�num�ration
    const UEnum* EnumPtr = StaticEnum<ETargetEnum>();
    if (!EnumPtr)
    {
        return Values; // Retourne un tableau vide en cas d'erreur
    }

    // Parcourir toutes les valeurs de l'�num�ration
    for (int32 i = 0; i < EnumPtr->NumEnums() - 1; ++i) // -1 pour ignorer "_MAX" ou autres
    {
        Values.Add(static_cast<ETargetEnum>(i));
    }

    return Values;
}