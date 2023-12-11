// Fill out your copyright notice in the Description page of Project Settings.


#include "MultipleTimelineHandlesComponent.h"

UMultipleTimelineHandlesComponent::UMultipleTimelineHandlesComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UMultipleTimelineHandlesComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UMultipleTimelineHandlesComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

