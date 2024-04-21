// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ImageTableAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class IMAGETABLE_API UImageTableAsset : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<FString, class UTexture2D*> images;
};
