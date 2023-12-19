// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MultipleTimelineHandlesComponent.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UMultipleTimelineHandlesComponent : public UActorComponent
{
	GENERATED_BODY()


private:
	TArray<class UTimelineComponent*> handles;

public:

	UPROPERTY(EditAnywhere)
	TMap<FString, class UTimelineHandle*> timelines;


	// Sets default values for this component's properties
	UMultipleTimelineHandlesComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	inline class UTimelineComponent* GetTimeline(const int i) const { return handles[i]; }

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
