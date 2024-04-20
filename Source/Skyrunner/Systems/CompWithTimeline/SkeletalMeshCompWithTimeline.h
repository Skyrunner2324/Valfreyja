// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "SkeletalMeshCompWithTimeline.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API USkeletalMeshCompWithTimeline : public USkeletalMeshComponent
{
	GENERATED_BODY()

protected:
#if 0
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class UMultipleTimelineHandlesComponent2* timelineHandles;
#else
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UTimelineHandleComponent* timelineHandle;
#endif


public:
	USkeletalMeshCompWithTimeline();
	
};
