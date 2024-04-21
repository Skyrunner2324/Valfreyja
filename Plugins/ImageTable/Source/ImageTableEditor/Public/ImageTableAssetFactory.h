// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "ImageTableAssetFactory.generated.h"

/**
 * 
 */
UCLASS()
class IMAGETABLEEDITOR_API UImageTableAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UImageTableAssetFactory();
	UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};
