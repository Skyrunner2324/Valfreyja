// Fill out your copyright notice in the Description page of Project Settings.


#include "MapLoader.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreamingDynamic.h"
#include "Engine/LevelStreaming.h"

#include "../SkyrunnerGameMode.h"

#include "../Utils/DebugLog.h"



class PendingLoadTask : public FNonAbandonableTask
{
	friend class FAsyncTask<PendingLoadTask>;

private:
	ULevelStreamingDynamic* pendingLoadMap = nullptr;

public:
	PendingLoadTask(ULevelStreamingDynamic* pendingLoadMap)
		: pendingLoadMap(pendingLoadMap) {}

	void DoWork()
	{
		DebugLog(15.f, FColor::Cyan, TEXT("Pending"));
		while (!pendingLoadMap->IsLevelVisible() &&
			pendingLoadMap->GetLevelStreamingState() != ELevelStreamingState::LoadedVisible)
		{
		}
		DebugLog(15.f, FColor::Orange, TEXT("Finished loading"));

		// TODO : manually call OnLoadCompleted and OnLevelShown events
	}

	FORCEINLINE TStatId GetStatId() const
	{
		RETURN_QUICK_DECLARE_CYCLE_STAT(PendingLoadTask, STATGROUP_ThreadPoolAsyncTasks);
	}
};



void UMapLoader::LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed)
{
	//DebugLogRed(TEXT("Load from name"));

	// TODO
}

ULevelStreamingDynamic* UMapLoader::LoadMapAsync(const TSoftObjectPtr<UWorld> level,
	const FTransform levelTransform,
	FLoadCompleted OnLoadCompleted,
	FLevelShown OnLevelShown,
	const bool bResetUponCompletion,
	const FString playerStartTag)
{
	//DebugLogRed(TEXT("Load from soft object reference"));

	UWorld* world = GEngine->GetWorld();
	if (!world)
		world = GEngine->GameViewport->GetWorld();
	check(world);



	// TODO : add a delay to test
	bool bSuccess = false;
	auto map = ULevelStreamingDynamic::LoadLevelInstanceBySoftObjectPtr(world,
		level,
		levelTransform,
		bSuccess);


	auto task = new FAutoDeleteAsyncTask<PendingLoadTask>(map);
	task->StartBackgroundTask();


	if (OnLoadCompleted.IsBound())
		map->OnLevelLoaded.Add(OnLoadCompleted);
	if (OnLevelShown.IsBound())
		map->OnLevelShown.Add(OnLevelShown);


	// print function call result
	if (bSuccess)
		DebugLogGreen(TEXT("Call to LoadLevelInstance success"));
	else
		DebugLogRed(TEXT("Call to LoadLevelInstance failed"));


	// whether to reset directly after load or let the user reset
	// with the OnLoadCompleted event
	if (bResetUponCompletion)
	{
		FOnSuccess resetOnSuccess;
		resetOnSuccess.BindLambda([&]() {
			ASkyrunnerGameMode* gm = Cast<ASkyrunnerGameMode>(UGameplayStatics::GetGameMode(world));
			if (gm)
			{
				gm->RespawnPlayer(false, playerStartTag);
			}
			});
		// TODO : find a way to bind a lambda to the OnLevelShown event
		//map->OnLevelShown.Add(resetOnSuccess);
	}

	return map;
}

void ULevelStreamingDynamicWithPostLoad::PostLoad()
{
	DebugLogRed(TEXT("PostLoad"));
}
