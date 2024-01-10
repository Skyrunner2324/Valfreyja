// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InstancedTimelineHandle.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateDelegateInstanced, float, scale);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishedDelegateInstanced);


/**
 * 
 */
UCLASS(BlueprintType)
class TIMELINEHANDLECOMPONENT_API UInstancedTimelineHandle : public UObject
{
	GENERATED_BODY()


private:
	UFUNCTION()
	void UpdateCallback(float scale);
	UFUNCTION()
	void FinishedCallback();


public:
	UPROPERTY(BlueprintReadWrite)
	class UTimelineComponent* timeline;


	// events for timeline component execution

	UPROPERTY(BlueprintAssignable)
	FOnUpdateDelegateInstanced OnTimelineUpdate;

	UPROPERTY(BlueprintAssignable)
	FOnFinishedDelegateInstanced OnTimelineFinished;





	UInstancedTimelineHandle();
	~UInstancedTimelineHandle();


	// call this on BeginPlay
	void Init(const class UTimelineHandle* asset);
};
