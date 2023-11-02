// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class SKYRUNNER_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// array of every UTimeRecorder objects
	// manage global recorder objects



	UPROPERTY(EditAnywhere)
	float timeDilation = 1.f;



	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
