// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Utils/Debuglog.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "GeometryComponentBreakableWall.h"
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
	//void AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldsActor);
	//void GetAnchor();

	virtual void RegisterAllComponents() override;

public:
	//UPROPERTY(BlueprintReadWrite,EditAnywhere)
	//USceneComponent* anchorContainer;
	//
	//UPROPERTY(BlueprintReadWrite,EditAnywhere)
	//TArray<AActor*> anchors;
	//
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	UGeometryComponentBreakableWall* instanceGeometryComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int numberOfAnchorToSpawn;
	
	//UPROPERTY(config, EditAnywhere, BlueprintReadOnly)
	//TSubclassOf<AFieldSystemActor> classAnchor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UChildActorComponent* anchor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	TArray<AActor*> anchorFields;

private : 
	//TArray<UGeometryComponentBreakableWall*> GeometryCollectionActors;
};
