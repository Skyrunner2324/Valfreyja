// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeSlippage.generated.h"

UCLASS()
class SKYRUNNER_API ATimeSlippage : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATimeSlippage();


private:
	// time scale
	// affects every UTimeSlippageModifier and UTimeSlippageLifeSpan objects
	UPROPERTY(EditAnywhere)
	float globalTimeScale = 1.f;


protected:
	virtual void BeginPlay() override;

public:
	// array of every UTimeSlippageModifier and UTimeSlippageLifeSpan objects
	// UTimeSlippageModifier and UTimeSlippageLifeSpan components will automatically
	// add their owner game actor to this array
	UPROPERTY(BlueprintReadOnly)
	TArray<class UTimeSlippageModifier*> modifiers;


	UPROPERTY(BlueprintReadOnly)
	float applicationTime = 0.f;
	UPROPERTY(BlueprintReadOnly)
	float globalTime = 0.f;
	UPROPERTY(BlueprintReadOnly)
	float globalManagedDeltaTime = 0.f;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDilated = false;


	// TODO : deactivate
	virtual void Tick(float DeltaTime) override;


	static ATimeSlippage* Get(UWorld* world);


	// TODO : lerp
	UFUNCTION(BlueprintCallable)
	void SetGlobalTimeScale(const float newScale);

	UFUNCTION(BlueprintCallable)
	inline float GetGlobalTimeScale() const { return globalTimeScale; }
};
