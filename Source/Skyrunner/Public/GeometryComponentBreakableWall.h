// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "GeometryComponentBreakableWall.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API UGeometryComponentBreakableWall : public UGeometryCollectionComponent
{
	GENERATED_BODY()

public : 
	UFUNCTION(BlueprintCallable, Category = "ChaosPerso")
	void InitializeAnchorField(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldsActor);
};
