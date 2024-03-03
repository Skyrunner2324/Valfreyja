// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkyrunnerGameMode.generated.h"


UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerReset);

UDELEGATE()
DECLARE_DYNAMIC_DELEGATE(FOnPlayerSpawned);



UCLASS(minimalapi)
class ASkyrunnerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class ATimeSlippage> timeSlippageClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> actorPooledClass;


public:
	UPROPERTY(BlueprintAssignable)
	FOnPlayerReset OnPlayerResetEvent;


	ASkyrunnerGameMode();


	virtual void StartPlay() override;


	UFUNCTION(BlueprintNativeEvent)
	void SpawnMandatoryActors();


	// TODO : upgrade
	UFUNCTION(BlueprintCallable)
	inline FString GetCurrentMapName() const { return GetWorld()->GetMapName(); }


	/**
	 * Respawn player for player controller 0 and possess
	 */
	UFUNCTION(BlueprintCallable)
	void RespawnPlayer(const bool bDestroyPlayerBeforeReset,
		const FString PlayerStartTag = "None");

	/**
	 * Spawn player, call the callback then possess with player controller 0
	 */
	UFUNCTION(BlueprintCallable)
	class APawn* SpawnPlayer(const FOnPlayerSpawned OnSpawned,
		const FString PlayerStartTag = "None");

	/**
	 * Possess and Reset the player and actors that have OnPlayerReset functions bound
	 */
	UFUNCTION(BlueprintCallable)
	void ResetPlayer(class APawn* player, AActor* oldCameraObject);


	UFUNCTION(BlueprintCallable)
	void UnloadOldestMap();
};
