// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageLifeSpan.h"

#include "TimeSlippage.h"
#include "TimeSlippageModifier.h"

#include "DebugLog.h"


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

	lifeSpanStamp = timeSlippage->globalTime;
}


void UTimeSlippageLifeSpan::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (timeSlippage->globalTime - lifeSpanStamp >= lifeSpan)
		GetOwner()->Destroy();
}

