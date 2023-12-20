// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "SKC_WeaponBase.generated.h"

/**
 * 
 */
UCLASS()
class USKC_WeaponBase : public USkeletalMeshComponent
{
	GENERATED_BODY()
	
	private:
		void SetModeVoid();
};
