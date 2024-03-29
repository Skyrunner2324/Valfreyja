// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreBoard.generated.h"

UCLASS()
class SKYRUNNER_API AScoreBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreBoard();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		double BestScore = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		double CurrentScore = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		TArray<double> ScoreBoard;

	UFUNCTION(BlueprintCallable)
		void SortScoreBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
