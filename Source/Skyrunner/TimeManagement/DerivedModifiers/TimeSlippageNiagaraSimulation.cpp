// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageNiagaraSimulation.h"

#include "../TimeSlippage.h"
#include "NiagaraComponent.h"

#include "../../Utils/DebugLog.h"


UTimeSlippageNiagaraSimulation::UTimeSlippageNiagaraSimulation()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTimeSlippageNiagaraSimulation::BeginPlay()
{
	UTimeSlippageModifier::BeginPlay();
	GetOwner()->GetComponents<UNiagaraComponent>(niagaraComponents);
}


void UTimeSlippageNiagaraSimulation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UTimeSlippageModifier::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TODO : OnTimeScaleChanged() -> set all niagara components to unpaused
	//if (!timeSlippage->bIsDilated)
	//	return;

	for (UNiagaraComponent* c : niagaraComponents)
	{
		c->SetPaused(false);
		c->AdvanceSimulation(1, localManagedDeltaTime);
		c->SetPaused(true);
	}
}

