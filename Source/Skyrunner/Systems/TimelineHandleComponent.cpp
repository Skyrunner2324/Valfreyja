// Fill out your copyright notice in the Description page of Project Settings.


#include "TimelineHandleComponent.h"

#include "Components/TimelineComponent.h"


void UTimelineHandleComponent::UpdateCallback(float scale)
{
	OnTimelineUpdate.Broadcast(scale);
}
void UTimelineHandleComponent::FinishedCallback()
{
	OnTimelineFinished.Broadcast();
}


UTimelineHandleComponent::UTimelineHandleComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	timeline = CreateDefaultSubobject<UTimelineComponent>(FName("Timeline"));
}


void UTimelineHandleComponent::BeginPlay()
{
	Super::BeginPlay();

	timeline->SetLooping(bLooping);
	timeline->SetTimelineLength(length);
	timeline->SetPlayRate(playRate);
	timeline->SetPlaybackPosition(0.f, false);

	FOnTimelineFloat update;
	update.BindUFunction(this, FName("UpdateCallback"));
	FOnTimelineEventStatic finished;
	finished.BindUFunction(this, FName("FinishedCallback"));
	if (curve)
		timeline->AddInterpFloat(curve, update);
	timeline->SetTimelineFinishedFunc(finished);
}


void UTimelineHandleComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}