// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MultipleTimelineHandlesComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API UMultipleTimelineHandlesComponent : public UActorComponent
{
	GENERATED_BODY()


protected:
	TMap<FString, class UInstancedTimelineHandle*> instancedHandles;


	UFUNCTION(BlueprintCallable, BlueprintPure)
	inline class UInstancedTimelineHandle* GetTimeline(const FString& timelineName)
	{
		if (instancedHandles.IsEmpty())
			return nullptr;

		auto th = instancedHandles.Find(timelineName);
		if (th)
		{
			return *th;
		}
		else
		{
			check(th);
			return nullptr;
		}
	}


public:
	UPROPERTY(EditAnywhere)
	TMap<FString, class UTimelineHandle*> timelines;


	// Sets default values for this component's properties
	UMultipleTimelineHandlesComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


};
