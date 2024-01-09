// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"

USTRUCT(BlueprintType)
struct FStructActorClass{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AActor> actorClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int numberToCreateAtstart;

	//FStructActorClass() { }
} ;


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SKYRUNNER_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectPool();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FStructActorClass> arrayClass;

private:
	TArray <AActor*> poolObject;
	TArray <AActor*> copyPoolObject;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	AActor* GetObjectPooled(FVector position, FRotator rotation, TSubclassOf<AActor> actorClass);
	virtual void DestroyComponent(bool bPromoteChildren) override;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	void RemoveObjectPooled(AActor* objectToDeactivate);

	UFUNCTION()
	void ActorDeath(AActor* actor);

	void ActivateActor(bool hiddenIngame, bool enableColision, bool tickEnabled, AActor* actorToActivate);
	void SpawnActor(TSubclassOf<AActor> actorClass, int numberActorToSpawn = 1);
};
