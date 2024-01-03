// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"


#include "Engine/LevelStreamingDynamic.h"

#include "../Utils/DebugLog.h"


void UMapLoader::LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from name"));
}

void UMapLoader::LoadMapAsync(const TSoftObjectPtr<UWorld> level, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from soft object reference"));


	// TODO : add a delay to test
	bool success = false;
	ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(GEngine->GameViewport->GetWorld(),
		level,
		FTransform(),
		success);


	// TODO : find a way of calling completed event when success
	if (success)
		DebugLogGreen(TEXT("Successfully loaded"));
	else
		DebugLogRed(TEXT("Load failed"));


	// TODO : reset (or maybe reset on completed event (user implementation))
}
