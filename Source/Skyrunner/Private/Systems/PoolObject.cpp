// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/PoolObject.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../../Systems/CustomProjectileMovement.h"

// Sets default values for this component's properties
UPoolObject::UPoolObject()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UPoolObject::GetObjectPooled(FVector position, FRotator rotation)
{
	if (copyPoolObject.IsEmpty()) {
		SpawnActor();
	}

	AActor* actorPooled = copyPoolObject[0];
	copyPoolObject.Remove(actorPooled);
	actorPooled->Reset();
	actorPooled->SetActorLocation(position);
	actorPooled->SetActorRotation(rotation);
	ActivateActor(false,true,true,actorPooled);

	return actorPooled;
}

void UPoolObject::RemoveObjectPooled(AActor* objectToDeactivate)
{
	copyPoolObject.Add(objectToDeactivate);
	ActivateActor(true, false, false, objectToDeactivate);
}

void UPoolObject::ActivateActor(bool hiddenIngame, bool enableColision, bool tickEnabled, AActor* actor)
{
	actor->SetActorHiddenInGame(hiddenIngame);
	actor->SetActorEnableCollision(enableColision);
	actor->SetActorTickEnabled(tickEnabled);

	for (UActorComponent* component : actor->GetComponents())
	{
		component->SetActive(!hiddenIngame, true);
		component->SetComponentTickEnabled(!hiddenIngame);

		UCustomProjectileMovement* projectileComponent = Cast<UCustomProjectileMovement>(component);

		if (projectileComponent != nullptr) {
			projectileComponent->Velocity = FVector(1.f, 0.f, 0.f);
			projectileComponent->UpdateComponentVelocity();
			projectileComponent->Init();
		}
	};
}

void UPoolObject::SpawnActor(int numberActorToSpawn)
{
	FVector SpawnLocation;
	FVector SpawnScale;
	FRotator SpawnRotation;
	FActorSpawnParameters spawnParam;

	for (size_t i = 0; i < numberActorToSpawn; i++)
	{
		AActor* actor = GetWorld()->SpawnActor<AActor>(actorClass,SpawnLocation, SpawnRotation, spawnParam);
		ActivateActor(true, false, false, actor);
		poolObject.Insert(actor,0);
		copyPoolObject.Insert(actor, 0);
	}
}

// Called when the gacme starts
void UPoolObject::BeginPlay()
{
	Super::BeginPlay();
	SpawnActor(numberActorToCreateAtStart);
}


// Called every frame
void UPoolObject::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

