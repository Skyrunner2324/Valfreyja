// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletalMeshCompWithTimeline.h"

#if 0
#include "MultipleTimelineHandlesComponent.h"
#else
#include "TimelineHandleComponent.h"
#endif


USkeletalMeshCompWithTimeline::USkeletalMeshCompWithTimeline()
{
#if 0
	timelineHandles = CreateDefaultSubobject<UMultipleTimelineHandlesComponent>(FName("Timeline Handles"));
#else
	timelineHandle = CreateDefaultSubobject<UTimelineHandleComponent>(FName("Timeline"));
#endif
}
