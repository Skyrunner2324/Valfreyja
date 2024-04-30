// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneCaptureComponent2D.h"
#include "SelectiveSceneCaptureComponent2D.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API USelectiveSceneCaptureComponent2D : public USceneCaptureComponent2D
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void AddComponentToHide(UPrimitiveComponent* component);

	UFUNCTION(BlueprintCallable)
	void AddOnlyComponentToShow(UPrimitiveComponent* component);
};
