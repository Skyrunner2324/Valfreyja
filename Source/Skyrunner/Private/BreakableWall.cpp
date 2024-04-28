// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakableWall.h"
#include "Field/FieldSystemActor.h"
#include "GeometryComponentBreakableWall.h"



ABreakableWall::ABreakableWall()
{
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABreakableWall::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABreakableWall::AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldActor)
{
	geometryComponent->InitializationFields.Empty();

	for (int j = 0; j < fieldActor.Num(); j++)
	{
		//set anchor field as initialization field for each destructible
		geometryComponent->InitializationFields.Add(Cast<AFieldSystemActor>(fieldActor[j])); 
	}

}

void ABreakableWall::GetAnchor()
{

}

void ABreakableWall::RegisterAllComponents()
{
	DebugLogRed(TEXT("Lourd"));

	GetComponentByClass<UGeometryComponentBreakableWall>();
}

