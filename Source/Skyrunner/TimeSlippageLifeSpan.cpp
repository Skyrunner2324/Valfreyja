// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageLifeSpan.h"

#include "TimeSlippageModifier.h"

// Sets default values for this component's properties
UTimeSlippageLifeSpan::UTimeSlippageLifeSpan()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimeSlippageLifeSpan::BeginPlay()
{
	Super::BeginPlay();

	// ...
}


// Called every frame
void UTimeSlippageLifeSpan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (lifeSpanStamp >= lifeSpan)
		GetOwner()->Destroy();

	// TODO : clean
	auto modifier = GetOwner()->GetComponentByClass<UTimeSlippageModifier>();
	if (modifier)
		lifeSpanStamp += modifier->localManagedDeltaTime;
	else
	{
		//lifeSpanStamp += // TODO : globalManagedDeltaTime;
	}
}

