// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageNiagaraSimulation.h"

#include "NiagaraComponent.h"


UTimeSlippageNiagaraSimulation::UTimeSlippageNiagaraSimulation()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTimeSlippageNiagaraSimulation::BeginPlay()
{
	Super::BeginPlay();
	UTimeSlippageModifier::BeginPlay();
	niagaraComponents = GetOwner()->GetComponentsByClass(UNiagaraComponent::StaticClass());
}


void UTimeSlippageNiagaraSimulation::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

