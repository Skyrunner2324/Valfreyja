// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Components/ActorComponent.h"


#include "EnemyBase.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDelegateTakeDmage, float, numberSequencePointDamageEnemy);

// TODO : rename EnemyBase
UCLASS()
class SKYRUNNER_API ABaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseEnemy();


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters, 
		meta = (ToolTip = "Fire rate, in bullets per second", ExposeOnSpawn = "true"))
	float fireRate = 2.f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
	float fireCooldown = 0.f;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FDelegateTakeDmage OnTakeDamage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Parameters)
	AActor* dotMarker = nullptr;


protected:

	// reference to player
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Components)
	class ACharacter* playerCharacter;
	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void EnemyLocked(bool locked);

};
