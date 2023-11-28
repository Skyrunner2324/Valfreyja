// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TimelineHandleComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateDelegate, float, scale);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnFinishedDelegate);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UTimelineHandleComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void UpdateCallback(float scale);
	UFUNCTION()
	void FinishedCallback();

public:
	UPROPERTY(BlueprintReadWrite)
	class UTimelineComponent* timeline;


public:	
	UPROPERTY(EditAnywhere)
	bool bLooping = false;

	UPROPERTY(EditAnywhere)
	float length = 1.f;

	UPROPERTY(EditAnywhere)
	float playRate = 1.f;

	UPROPERTY(EditAnywhere)
	bool bIgnoreTimeDilation = false;


	UPROPERTY(EditAnywhere)
	class UCurveFloat* curve;


	// Sets default values for this component's properties
	UTimelineHandleComponent();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	UPROPERTY(BlueprintAssignable)
	FOnUpdateDelegate OnTimelineUpdate;

	UPROPERTY(BlueprintAssignable)
	FOnFinishedDelegate OnTimelineFinished;


	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
