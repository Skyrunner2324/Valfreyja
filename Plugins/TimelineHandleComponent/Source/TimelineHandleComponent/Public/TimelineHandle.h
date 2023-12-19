// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TimelineHandle.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class TIMELINEHANDLECOMPONENT_API UTimelineHandle : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	bool bLooping = false;

	UPROPERTY(EditAnywhere)
	float length = 1.f;

	UPROPERTY(EditAnywhere)
	float playRate = 1.f;

	UPROPERTY(EditAnywhere)
	bool bIgnoreTimeDilation = false;


	UPROPERTY(EditAnywhere)
	class UCurveFloat* curve;

};
