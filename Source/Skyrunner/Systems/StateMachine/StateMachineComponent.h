// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateMachineComponent.generated.h"

class UBaseState;

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UStateMachineComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UStateMachineComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	bool ActiveStateValid() { return activeState < 0 || activeState >= states.Num(); }

	int activeState = 0;
public:	
	void SwitchState(const FString& stateName);

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<UBaseState*> states;
	//TArray<TSubclassOf<UBaseState>> states;
};
