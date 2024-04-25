// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "BreakableWall.generated.h"

UCLASS()
class SKYRUNNER_API ABreakableWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableWall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public : 
	//UFUNCTION(BlueprintCallable)
	//void AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldsActor);

};
