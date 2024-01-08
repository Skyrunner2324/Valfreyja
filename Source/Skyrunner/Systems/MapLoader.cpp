// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreamingDynamic.h"

#include "../SkyrunnerGameMode.h"

#include "../Utils/DebugLog.h"



void UMapLoader::LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed)
{
	DebugLogRed(TEXT("Load from name"));
	throw;
}

void UMapLoader::LoadMapAsync(const TSoftObjectPtr<UWorld> level,
	FLoadCompleted OnLoadCompleted,
	FLevelShown OnLevelShown,
	const bool bResetUponCompletion,
	const FString playerStartTag)
{
	DebugLogRed(TEXT("Load from soft object reference"));

	auto world = GEngine->GameViewport->GetWorld();


	// TODO : add a delay to test
	bool bSuccess = false;
	auto map = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(world,
		level,
		FTransform(),
		bSuccess);


	if (OnLoadCompleted.IsBound())
		map->OnLevelLoaded.Add(OnLoadCompleted);
	if (OnLevelShown.IsBound())
		map->OnLevelShown.Add(OnLevelShown);


	FOnSuccess onSuccess;
	onSuccess.BindLambda([&]() {
		if (bSuccess)
			DebugLogGreen(TEXT("Successfully loaded"));
		else
			DebugLogRed(TEXT("Load failed"));
		});
	// TODO : find a way to bind a lambda to the OnLevelLoaded event
	//map->OnLevelLoaded.Add(onSuccess);


	// whether to reset directly after load or let the user reset
	// with the OnLoadCompleted event
	if (bResetUponCompletion)
	{
		FOnSuccess resetOnSuccess;
		resetOnSuccess.BindLambda([&]() {
			ASkyrunnerGameMode* gm = Cast<ASkyrunnerGameMode>(UGameplayStatics::GetGameMode(world));
			if (gm)
			{
				gm->ResetPlayer(playerStartTag);
			}
			});
		// TODO : find a way to bind a lambda to the OnLevelShown event
		//map->OnLevelShown.Add(resetOnSuccess);
	}
}
