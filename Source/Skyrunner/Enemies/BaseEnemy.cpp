// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseEnemy.h"

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

	collisionCapsule = CreateDefaultSubobject<UCapsuleComponent>(FName("Collision Capsule"));
	collisionCapsule->SetCapsuleHalfHeight(95.f);
	collisionCapsule->SetCapsuleRadius(50.f);
	RootComponent = collisionCapsule;

	arrowComponent = CreateDefaultSubobject<UArrowComponent>(FName("Arrow Component"));
	arrowComponent->SetupAttachment(RootComponent);
	
	collisionProjectile = CreateDefaultSubobject<UBoxComponent>(FName("CollisionProjectile"));
	collisionProjectile->SetupAttachment(RootComponent);
	FVector boxExtent = FVector(52, 52, 97);
	collisionProjectile->SetBoxExtent(boxExtent);
	collisionProjectile->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);

	detectionSphere = CreateDefaultSubobject<USphereComponent>(FName("Detection Sphere"));
	detectionSphere->SetSphereRadius(2000.f);
	detectionSphere->SetupAttachment(RootComponent);

	skMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(FName("Skeletal Mesh"));
	skMeshComponent->SetupAttachment(RootComponent);

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


