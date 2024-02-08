// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TimeDefaults.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API UTimeDefaults : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category="TimeDefaults")
	static inline float GetWorldDeltaRealTimeSeconds()
	{
		UWorld* world = GEngine->GameViewport->GetWorld();
		return world->DeltaRealTimeSeconds;
	}
};
