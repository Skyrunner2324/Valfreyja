// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Score.generated.h"

UCLASS()
class SKYRUNNER_API AScore : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScore();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		double TotalTime = 0.f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		TArray<double> CheckpointsTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		bool bIsActif = true;


	UFUNCTION(BlueprintCallable)
		void Reset();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
