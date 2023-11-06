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


private:
	// array of every UTimeRecorder objects
	UPROPERTY(EditAnywhere)
	TArray<class AActor*> recorders;


	// time scale
	// affects every UTimeRecorderObject
	UPROPERTY(EditAnywhere)
	float globalTimeScale = 1.f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly)
	float globalTime = 0.f;


	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetTimeScale(const float newScale);

	UFUNCTION(BlueprintCallable)
	inline float GetTimeScale() const { return globalTimeScale; }
};
