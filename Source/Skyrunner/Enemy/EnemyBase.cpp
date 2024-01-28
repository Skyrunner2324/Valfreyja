// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBase.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Components/ArrowComponent.h" 	
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "Components/SkeletalMeshComponent.h"



// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	auto capsule = Cast<UCapsuleComponent>(RootComponent);
	capsule->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	capsule->SetCapsuleHalfHeight(95.f);
	capsule->SetCapsuleRadius(50.f);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	// convert from bullets/s to s/bullet for easier time management
	fireRate = 1.f / fireRate; 
	fireCooldown = fireRate;
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (fireCooldown > 0.f)
		fireCooldown -= DeltaTime;
}
