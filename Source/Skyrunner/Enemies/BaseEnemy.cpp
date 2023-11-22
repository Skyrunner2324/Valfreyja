// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABaseEnemy::ABaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(FName("Collision Capsule"));
	collisionCapsule->SetCapsuleHalfHeight(95.f);
	collisionCapsule->SetCapsuleRadius(50.f);
	RootComponent = collisionCapsule;

	arrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("Arrow Component"));
	arrowComponent->SetupAttachment(RootComponent);

	detectionSphere = CreateDefaultSubobject<USphereComponent>(FName("Detection Sphere"));
	detectionSphere->SetSphereRadius(1000.f);
	detectionSphere->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


