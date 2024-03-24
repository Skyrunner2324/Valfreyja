// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"

#include "PoolObject.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "../../Systems/CustomProjectileMovement.h"
#include "../../Utils/DebugLog.h"
#include "NiagaraComponent.h"


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
	check(!copyPoolObject.IsEmpty());
	if (copyPoolObject.IsEmpty())
	{
		SpawnActor(actorClass);
		return GetObjectPooled(position, rotation, actorClass);
	}


	auto predicate = [&](const AActor* a) { return a->IsA(actorClass.Get()); };
	auto find = copyPoolObject.FindByPredicate(predicate);
	AActor* actorPooled = nullptr;
	if (find)
		actorPooled = *find;

	if (!actorPooled)
	{
		SpawnActor(actorClass);
		return GetObjectPooled(position, rotation, actorClass);
	}

	copyPoolObject.Remove(actorPooled);

	actorPooled->Reset();
	actorPooled->SetActorLocation(position);
	actorPooled->SetActorRotation(rotation);
	ActivateActor(false, true, true, actorPooled);


	check(actorPooled);
	return actorPooled;
}

//void UObjectPool::DestroyComponent(bool bPromoteChildren)
//{
//	Super::DestroyComponent(bPromoteChildren);
//}

void UObjectPool::RemoveObjectPooled(AActor* objectToDeactivate)
{
	// placed back in stand by
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
		UNiagaraComponent* niagaraComponent = Cast<UNiagaraComponent>(component);
		component->SetActive(!hiddenIngame, true);

		if (niagaraComponent == nullptr)
			component->SetComponentTickEnabled(!hiddenIngame);
		else
			niagaraComponent->ResetSystem();

		UCustomProjectileMovement* projectileComponent = Cast<UCustomProjectileMovement>(component);

		if (projectileComponent != nullptr)
		{
			projectileComponent->Velocity = FVector(1.f, 0.f, 0.f);
			projectileComponent->Init();
			projectileComponent->UpdateComponentVelocity();
		}
	}
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
		check(poolObjectComponent);
		poolObjectComponent->OnDeath.AddDynamic(this, &UObjectPool::ActorDeath);
	}
}

// Called when the gacme starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();

	if (!arrayClass.IsEmpty())
	{
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

