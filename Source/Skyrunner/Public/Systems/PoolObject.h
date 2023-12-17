// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PoolObject.generated.h"


UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SKYRUNNER_API UPoolObject : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPoolObject();

	UFUNCTION(BlueprintCallable)
	AActor* GetObjectPooled(FVector position, FRotator rotation);

	UFUNCTION(BlueprintCallable)
	void RemoveObjectPooled(AActor* objectToDeactivate);

	void ActivateActor(bool hiddenIngame, bool enableColision, bool tickEnabled, AActor* actorToActivate);
	void SpawnActor(int numberActorToSpawn = 1);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numberActorToCreateAtStart = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> actorClass;

	TArray <AActor*> poolObject;
	TArray <AActor*> copyPoolObject;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
