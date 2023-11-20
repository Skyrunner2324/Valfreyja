// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimeSlippageModifier.generated.h"



DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeScaleChangedDelegate, float, newScale);



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API UTimeSlippageModifier : public UActorComponent
{
	GENERATED_BODY()

public:
	UTimeSlippageModifier();

protected:
	virtual void BeginPlay() override;

public:
	// changes local time scale in order to reach global time scale of spcified value
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float localTimeScaleTarget = 1.f;

private:
	// override target value with specified constant local time scale
	UPROPERTY(EditAnywhere)
	bool bOverrideTarget = false;

protected:
	UPROPERTY(EditAnywhere)
	float localTimeScale = 1.f;


	// pointer to global ATimeSlippage object
	UPROPERTY(BlueprintReadOnly)
	class ATimeSlippage* timeSlippage;


	// locally managed delta time
	UPROPERTY(BlueprintReadOnly)
	float deltaTime = 0.f;

	UPROPERTY(BlueprintReadOnly)
	float localTime = 0.f;



public:
	UPROPERTY(BlueprintReadOnly)
	float localManagedDeltaTime = 0.f;

	UPROPERTY(BlueprintAssignable)
	FOnTimeScaleChangedDelegate OnTimeScaleChanged;


public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


	// TODO : lerp
	UFUNCTION(BlueprintCallable)
	void SetLocalTimeScale(const float newScale);
};