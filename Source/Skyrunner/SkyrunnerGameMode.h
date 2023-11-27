// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkyrunnerGameMode.generated.h"

UCLASS(minimalapi)
class ASkyrunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASkyrunnerGameMode();

	// TODO : upgrade
	UFUNCTION(BlueprintCallable)
	inline FString GetCurrentMapName() const { return GetWorld()->GetMapName(); }
};



