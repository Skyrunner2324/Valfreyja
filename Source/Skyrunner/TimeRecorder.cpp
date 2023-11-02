// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeRecorder.h"

// Sets default values for this component's properties
UTimeRecorder::UTimeRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimeRecorder::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTimeRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

