// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreamingDynamic.h"

#include "../SkyrunnerGameMode.h"

#include "../Utils/DebugLog.h"


void UMapLoader::LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from name"));
}

void UMapLoader::LoadMapAsync(const TSoftObjectPtr<UWorld> level,
	FLoadCompleted completed,
	const bool bResetUponCompletion,
	const FString playerStartTag)
{
	DebugLogRed(TEXT("Load from soft object reference"));

	auto world = GEngine->GameViewport->GetWorld();


	// TODO : add a delay to test
	bool bSuccess = false;
	ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(world,
		level,
		FTransform(),
		bSuccess);


	completed.ExecuteIfBound(bSuccess);
	if (bSuccess)
		DebugLogGreen(TEXT("Successfully loaded"));
	else
		DebugLogRed(TEXT("Load failed"));


	// TODO : reset (or maybe reset on completed event (user implementation))
	if (bResetUponCompletion)
	{
		ASkyrunnerGameMode* gm = Cast<ASkyrunnerGameMode>(UGameplayStatics::GetGameMode(world));
		if (gm)
		{
			gm->ResetPlayer(playerStartTag);
		}
	}
}
