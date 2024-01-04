// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MapLoader.generated.h"


// TODO : take loaded map in arguments (find a way to restart game mode)
DECLARE_DYNAMIC_DELEGATE_OneParam(FLoadCompleted, bool, bSuccess);

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
	static void LoadMapAsync(const TSoftObjectPtr<UWorld> level,
		FLoadCompleted completed,
		const bool bResetUponCompletion = true,
		const FString playerStartTag = "None");
};
