// Fill out your copyright notice in the Description page of Project Settings.

#include "StateMachineComponent.h"

// Sets default values for this component's properties
UStateMachineComponent::UStateMachineComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UStateMachineComponent::BeginPlay()
{
	Super::BeginPlay();

	if (states.Num() == 0)
	{
		activeState = -1;
		GEngine->AddOnScreenDebugMessage(949, 1.f, FColor::Red, "No states in state machine");
	}
	else
		activeStatePtr = Cast<UBaseState>(states[activeState]);

	for (int i = 0; i < states.Num(); i++)
	{
		UBaseState* state = Cast<UBaseState>(states[i]);
		state->stateMachine = this;
	}
}

void UStateMachineComponent::SwitchState(const FString& stateName)
{
	for (int i = 0; i < states.Num(); i++)
	{
		UBaseState* state = Cast<UBaseState>(states[i]);
		if (stateName ==state->stateName)
		{
			if (ActiveStateValid())
			{
				activeStatePtr = Cast<UBaseState>(states[activeState]);
				activeStatePtr->EndState();
			}

			state->StartState();
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

	activeStatePtr->StateUpdate(DeltaTime);
}
