// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

UCLASS()
class SKYRUNNER_API ABaseEnemy : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseEnemy();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	class UCapsuleComponent* collisionCapsule;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	class USphereComponent* detectionSphere;

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	class ACharacter* playerCharacter;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Components)
	class UArrowComponent* arrowComponent;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
