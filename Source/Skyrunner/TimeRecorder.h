// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimeRecorder.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UTimeRecorder : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimeRecorder();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// pointer to global ATimeManager object
	UPROPERTY(BlueprintReadOnly)
	class ATimeManager* timeManager;

	// array of every property that should be affected by time manager






	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
