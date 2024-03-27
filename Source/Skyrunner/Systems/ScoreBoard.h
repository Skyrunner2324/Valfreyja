// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Score.h"
#include "ScoreBoard.generated.h"

UCLASS()
class SKYRUNNER_API AScoreBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreBoard();
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		AScore* BestScore = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		AScore* CurrentScore = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
		TArray<AScore*> ScoreBoard;

	//UFUNCTION(BlueprintCallable)
	//	void SortScoreBoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
