// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageLifeSpan.h"

#include "TimeSlippage.h"
#include "TimeSlippageModifier.h"


UTimeSlippageLifeSpan::UTimeSlippageLifeSpan()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTimeSlippageLifeSpan::BeginPlay()
{
	Super::BeginPlay();
	timeSlippage = ATimeSlippage::Get(GetWorld());
	// TODO : make this class derived from modifier class
	//timeSlippage->modifiers.Add(this);
}


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
		lifeSpanStamp += timeSlippage->globalManagedDeltaTime;
}

