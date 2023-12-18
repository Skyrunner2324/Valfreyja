// Fill out your copyright notice in the Description page of Project Settings.

#include "StateMachineComponent.h"
#include "BaseState.h"

// Sets default values for this component's properties
UStateMachineComponent::UStateMachineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();
		
	GetOwner()->GetComponents<UBaseState>(states);

	if (states.Num() == 0)
	{
		activeState = -1;
		GEngine->AddOnScreenDebugMessage(949, 1.f, FColor::Red, "No states in state machine");
	}

	for (int i = 0; i < states.Num(); i++)
	{
		if (states[i]->isDefaultState)
			activeState = i;

		states[i]->stateMachine = this;
	}
}

void UStateMachineComponent::SwitchState(const FString& stateName)
{
	for (int i = 0; i < states.Num(); i++)
	{
		if (stateName ==states[i]->stateName)
		{
			if (ActiveStateValid())
			{
				states[activeState]->EndState();
			}

			states[i]->StartState();
			activeState = i;
			return;
		}
	}
}

// Called every frame
void UStateMachineComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (ActiveStateValid())
		return;

	states[activeState]->StateUpdate(DeltaTime);
}
