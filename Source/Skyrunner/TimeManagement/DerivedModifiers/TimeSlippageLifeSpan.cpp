// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageLifeSpan.h"

#include "../TimeSlippage.h"

#include "../../Utils/DebugLog.h"


UTimeSlippageLifeSpan::UTimeSlippageLifeSpan()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTimeSlippageLifeSpan::BeginPlay()
{
	UTimeSlippageModifier::BeginPlay();

	lifeSpanStamp = timeSlippage->globalTime;
}


void UTimeSlippageLifeSpan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	UTimeSlippageModifier::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (timeSlippage->globalTime - lifeSpanStamp >= lifeSpan)
		GetOwner()->Destroy();
}

