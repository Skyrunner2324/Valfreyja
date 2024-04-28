// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Utils/Debuglog.h"
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

public : 
	//UFUNCTION(BlueprintCallable, Category = "AudioReflectionsPortal")
	void AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldsActor);
	void GetAnchor();

	virtual void RegisterAllComponents() override;

private : 
	TArray<AFieldSystemActor*> anchorField;

};
