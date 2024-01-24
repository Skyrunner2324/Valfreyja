// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/LevelStreamingDynamic.h"
#include "MapLoader.generated.h"


// TODO : take loaded map in arguments (find a way to restart game mode)
// using lambda binding

// event in arguments
//DECLARE_DYNAMIC_DELEGATE_OneParam(FLoadCompleted, bool, bSuccess);
DECLARE_DYNAMIC_DELEGATE(FLoadCompleted);
DECLARE_DYNAMIC_DELEGATE(FLevelShown);

// on load success
DECLARE_DELEGATE(FOnSuccess);


UCLASS()
class SKYRUNNER_API ULevelStreamingDynamicWithPostLoad : public ULevelStreamingDynamic
{
	GENERATED_BODY()

private:
	virtual void PostLoad() override;

public:
};


/**
 * 
 */
UCLASS()
class SKYRUNNER_API UMapLoader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	static void LoadMapAsyncFromName(const FName levelName, FLoadCompleted completed);

	UFUNCTION(BlueprintCallable)
	static ULevelStreamingDynamic* LoadMapAsync(const TSoftObjectPtr<UWorld> level,
		const FTransform levelTransform,
		FLoadCompleted OnLoadCompleted,
		FLevelShown OnLevelShown,
		const bool bResetUponCompletion = true,
		const FString playerStartTag = "None");
};
