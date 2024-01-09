// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkyrunnerGameMode.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerReset);



UCLASS(minimalapi)
class ASkyrunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnPlayerReset OnPlayerResetEvent;


	ASkyrunnerGameMode();



	// TODO : upgrade
	UFUNCTION(BlueprintCallable)
	inline FString GetCurrentMapName() const { return GetWorld()->GetMapName(); }


	UFUNCTION(BlueprintCallable)
	void ResetPlayer(const bool bDestroyPlayerBeforeReset,
		const FString PlayerStartTag = "None");
};
