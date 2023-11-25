// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeSlippage.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTimeScaleChangedDelegate, float, newScale);


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
	UPROPERTY(BlueprintReadOnly)
	float framerate = 0.f;

	// actual app time
	UPROPERTY(BlueprintReadOnly)
	float applicationTime = 0.f;
	// dilated app time
	UPROPERTY(BlueprintReadOnly)
	float globalTime = 0.f;

	// actual delta time
	UPROPERTY(BlueprintReadOnly)
	float applicationDeltaTime = 0.f;
	// dilated delta time
	UPROPERTY(BlueprintReadOnly)
	float globalManagedDeltaTime = 0.f;

	UPROPERTY(BlueprintReadOnly)
	bool bIsDilated = false;


	// delegate that will broadcast to every Modifier objects that
	// global time scale has changed
	FOnTimeScaleChangedDelegate OnTimeScaleChanged;


	// TODO : deactivate
	virtual void Tick(float DeltaTime) override;


	static ATimeSlippage* Get(UWorld* world);


	// TODO : lerp
	UFUNCTION(BlueprintCallable)
	void SetGlobalTimeScale(const float newScale);

	UFUNCTION(BlueprintCallable)
	inline float GetGlobalTimeScale() const { return globalTimeScale; }
};
