// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseState.generated.h"

/**
 * 
 */
UCLASS( Blueprintable, ClassGroup = (Custom))
class SKYRUNNER_API UBaseState : public UActorComponent
{
	GENERATED_BODY()
	
public:
	UBaseState();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool isDefaultState = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString stateName = "BaseState";

	UPROPERTY(BlueprintReadOnly)
	class UStateMachineComponent* stateMachine;

	// Called when switching states
	void StartState();
	void EndState();

	// Updates the state, called every tick
	void StateUpdate(float DeltaTime);

	// Here, check if the state should change and call to the StateMachine to change state
	void CheckStateConditions();
};
