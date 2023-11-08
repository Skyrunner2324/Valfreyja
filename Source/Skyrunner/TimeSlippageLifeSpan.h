// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimeSlippageLifeSpan.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UTimeSlippageLifeSpan : public UActorComponent
{
	GENERATED_BODY()

private:
	// time stamp (when created)
	float lifeSpanStamp = 0.f;


	// < 0.f is forever, 0.f is instant death, time is in seconds (with time slippage)
	UPROPERTY(EditAnywhere)
	float lifeSpan = 0.f;


protected:
	// pointer to global ATimeSlippage object
	UPROPERTY(BlueprintReadOnly)
	class ATimeSlippage* timeSlippage;


public:	
	UTimeSlippageLifeSpan();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
