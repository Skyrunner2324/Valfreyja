// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseState.h"
#include "StateMachineComponent.h"

void UBaseState::StartState()
{
	GEngine->AddOnScreenDebugMessage(90349, 1.f, FColor::Emerald, stateName + " StartState");
}

void UBaseState::EndState()
{
	GEngine->AddOnScreenDebugMessage(90348, 1.f, FColor::Emerald, stateName + " EndState");

}

void UBaseState::StateUpdate(float DeltaTime)
{
	CheckStateConditions();
}

void UBaseState::CheckStateConditions()
{

}
