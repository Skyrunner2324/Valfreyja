// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"

#include "../Utils/DebugLog.h"


void UMapLoader::LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from name"));
}

void UMapLoader::LoadMapAsync(const TSoftObjectPtr<UWorld> level, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from soft object reference"));
}
