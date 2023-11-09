// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TimeSlippageModifier.h"
#include "TimeSlippageNiagaraSimulation.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UTimeSlippageNiagaraSimulation : public UTimeSlippageModifier
{
	GENERATED_BODY()

private:
	TArray<UActorComponent*> niagaraComponents;

public:	
	UTimeSlippageNiagaraSimulation();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
