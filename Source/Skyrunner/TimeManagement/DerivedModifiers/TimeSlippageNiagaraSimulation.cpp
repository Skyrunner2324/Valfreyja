// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageNiagaraSimulation.h"

#include "../TimeSlippage.h"
#include "NiagaraComponent.h"

#include "../Utils/DebugLog.h"


UTimeSlippageNiagaraSimulation::UTimeSlippageNiagaraSimulation()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTimeSlippageNiagaraSimulation::BeginPlay()
{
	UTimeSlippageModifier::BeginPlay();
	niagaraComponents = GetOwner()->GetComponentsByClass(UNiagaraComponent::StaticClass());
}


void UTimeSlippageNiagaraSimulation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UTimeSlippageModifier::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// TODO : OnTimeScaleChanged() -> set all niagara components to unpaused
	//if (!timeSlippage->bIsDilated)
	//	return;

	for (auto& c : niagaraComponents)
	{
		// TODO : find a way to remove casting
		auto n = Cast<UNiagaraComponent>(c);
		n->SetPaused(false);
		n->AdvanceSimulation(1, localManagedDeltaTime);
		n->SetPaused(true);
	}
}

