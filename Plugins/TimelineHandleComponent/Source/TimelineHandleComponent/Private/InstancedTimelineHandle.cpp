// Fill out your copyright notice in the Description page of Project Settings.


#include "InstancedTimelineHandle.h"

#include "Components/TimelineComponent.h"
#include "TimelineHandle.h"


void UInstancedTimelineHandle::UpdateCallback(float scale)
{
	OnTimelineUpdate.Broadcast(scale);
}
void UInstancedTimelineHandle::FinishedCallback()
{
	OnTimelineFinished.Broadcast();
}


UInstancedTimelineHandle::UInstancedTimelineHandle()
{
	timeline = CreateDefaultSubobject<UTimelineComponent>(FName("Timeline"));
}

UInstancedTimelineHandle::~UInstancedTimelineHandle()
{
}

void UInstancedTimelineHandle::Init(const UTimelineHandle* asset)
{
	timeline->SetLooping(asset->bLooping);
	timeline->SetTimelineLength(asset->length);
	timeline->SetPlayRate(asset->playRate);
	timeline->SetPlaybackPosition(0.f, false, false);
	timeline->SetIgnoreTimeDilation(asset->bIgnoreTimeDilation);

	FOnTimelineFloat update;
	update.BindUFunction(this, FName("UpdateCallback"));
	FOnTimelineEventStatic finished;
	finished.BindUFunction(this, FName("FinishedCallback"));
	if (asset->curve)
		timeline->AddInterpFloat(asset->curve, update);
	timeline->SetTimelineFinishedFunc(finished);
}