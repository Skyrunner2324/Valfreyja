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

private:	
	// pointer to global ATimeManager object
	UPROPERTY(EditAnywhere)
	class ATimeManager* timeManager;

	FTransform oldTransform;


	// TODO : find a way to affect properties update (before tick)
	// array of every property that should be affected by time manager
	UPROPERTY(EditAnywhere)
	TArray<UActorComponent*> properties;



public:

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
