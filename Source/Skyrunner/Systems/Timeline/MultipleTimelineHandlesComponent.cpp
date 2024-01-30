// Fill out your copyright notice in the Description page of Project Settings.


#include "MultipleTimelineHandlesComponent.h"

#include "TimelineHandleComponent/Public/InstancedTimelineHandle.h"
#include "Components/TimelineComponent.h"


UMultipleTimelineHandlesComponent::UMultipleTimelineHandlesComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// create all timeline components based on the timeline handle assets
	for (const auto& th : timelines)
	{
		instancedHandles.Add(th.Key, CreateDefaultSubobject<UInstancedTimelineHandle>(FName(th.Key)));
	}
}


void UMultipleTimelineHandlesComponent::BeginPlay()
{
	// create all timeline components based on the timeline handle assets
	// if constructor failed to create the instances
	if (instancedHandles.IsEmpty() && !timelines.IsEmpty())
	{
		for (const auto& th : timelines)
		{
			instancedHandles.Add(th.Key, NewObject<UInstancedTimelineHandle>(this,
				UInstancedTimelineHandle::StaticClass(),
				FName(th.Key)));
		}
	}

	for (const auto& ith : instancedHandles)
	{
		ith.Value->Init(*timelines.Find(ith.Key));
	}

	Super::BeginPlay();
}


void UMultipleTimelineHandlesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
