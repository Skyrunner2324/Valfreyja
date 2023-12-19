// Fill out your copyright notice in the Description page of Project Settings.


#include "TimelineHandleActions.h"

#include "TimelineHandleComponent/Public/TimelineHandle.h"


FTimelineHandleAssetTypeActions::FTimelineHandleAssetTypeActions()
{
}

FTimelineHandleAssetTypeActions::~FTimelineHandleAssetTypeActions()
{
}

UClass* FTimelineHandleAssetTypeActions::GetSupportedClass() const
{
	return UTimelineHandle::StaticClass();
}

FText FTimelineHandleAssetTypeActions::GetName() const
{
	return INVTEXT("Timeline Handle");
}

FColor FTimelineHandleAssetTypeActions::GetTypeColor() const
{
	return FColor::Cyan;
}

uint32 FTimelineHandleAssetTypeActions::GetCategories()
{
	return EAssetTypeCategories::Misc;
}