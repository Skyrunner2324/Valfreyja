// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletalMeshCompWithTimeline.h"

#include "Systems/TimelineHandleComponent.h"
#include "Systems/ObjectPool.h"


USkeletalMeshCompWithTimeline::USkeletalMeshCompWithTimeline()
{
	timelineHandle = CreateDefaultSubobject<UTimelineHandleComponent>(FName("Timeline"));
	poolObject = CreateDefaultSubobject<UPoolObject>(FName("Poolobject"));
}
