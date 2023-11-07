// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimeSlippageModifier.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API UTimeSlippageModifier : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTimeSlippageModifier();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	// pointer to global ATimeSlippage object
	UPROPERTY(EditAnywhere)
	class ATimeSlippage* timeSlippage;

	UPROPERTY(EditAnywhere)
	float localTimeScale = 1.f;


protected:
	// locally managed delta time
	UPROPERTY(BlueprintReadOnly)
	float deltaTime = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float localTime = 0.f;


public:
	UPROPERTY(BlueprintReadOnly)
	float localManagedDeltaTime = 0.f;



public:

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	// TODO : lerp
	UFUNCTION(BlueprintCallable)
	void SetLocalTimeScale(const float newScale);
};