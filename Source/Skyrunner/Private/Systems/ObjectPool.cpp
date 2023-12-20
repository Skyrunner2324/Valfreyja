// Fill out your copyright notice in the Description page of Project Settings.


#include "Systems/ObjectPool.h"
#include "../../Systems/PoolObject.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../../Systems/CustomProjectileMovement.h"
#include "../../Utils/DebugLog.h"

// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


AActor* UObjectPool::GetObjectPooled(FVector position, FRotator rotation, TSubclassOf<AActor> actorClass)
{
	AActor* actorPooled = nullptr;
	actorPooled = *copyPoolObject.FindByPredicate([&](const AActor* a) { return a->IsA(actorClass.Get()); });

	if (actorPooled == nullptr)
		SpawnActor(actorClass);

	copyPoolObject.Remove(actorPooled);
	actorPooled->Reset();
	actorPooled->SetActorLocation(position);
	actorPooled->SetActorRotation(rotation);
	ActivateActor(false, true, true, actorPooled);

	return actorPooled;
}

void UObjectPool::DestroyComponent(bool bPromoteChildren)
{
	Super::DestroyComponent(bPromoteChildren);
}

void UObjectPool::RemoveObjectPooled(AActor* objectToDeactivate)
{
	copyPoolObject.Add(objectToDeactivate);
	ActivateActor(true, false, false, objectToDeactivate);
}

void UObjectPool::ActorDeath(AActor* actor)
{
	RemoveObjectPooled(actor);
}

void UObjectPool::ActivateActor(bool hiddenIngame, bool enableColision, bool tickEnabled, AActor* actor)
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

void UObjectPool::SpawnActor(TSubclassOf<AActor> actorClass, int numberActorToSpawn)
{
	FVector SpawnLocation;
	FVector SpawnScale;
	FRotator SpawnRotation;
	FActorSpawnParameters spawnParam;

	for (size_t i = 0; i < numberActorToSpawn; i++)
	{
		AActor* actor = GetWorld()->SpawnActor<AActor>(actorClass, SpawnLocation, SpawnRotation, spawnParam);
		ActivateActor(true, false, false, actor);
		poolObject.Insert(actor, 0);
		copyPoolObject.Insert(actor, 0);
		UPoolObject* poolObjectComponent = Cast<UPoolObject>(actor->GetComponentByClass(UPoolObject::StaticClass()));
		poolObjectComponent->OnDeath.AddDynamic(this, &UObjectPool::ActorDeath);
	}
}

// Called when the gacme starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();

	if (!arrayClass.IsEmpty()) {
		for (FStructActorClass structActorClass : arrayClass)
		{
			SpawnActor(structActorClass.actorClass, structActorClass.numberToCreateAtstart);
		}
	}
}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

