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
		double BestTime = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		double CurrentTime = 0.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		int BestScore = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		int CurrentScore = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		TMap<FString, double> TimeLeaderBoard;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		TMap<FString, int> ScoreLeaderBoard;

	UFUNCTION(BlueprintCallable)
		void SortLeaderBoards();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
