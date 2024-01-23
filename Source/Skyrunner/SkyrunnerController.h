// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SkyrunnerController.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API ASkyrunnerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void FellOutOfWorld(const class UDamageType& dmgType) override;

	UFUNCTION(BlueprintNativeEvent)
	void FellOutOfWorldImpl(const class UDamageType* dmgType);
};
