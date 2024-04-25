// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakableWall.h"
#include "Field/FieldSystemActor.h"

// Sets default values
ABreakableWall::ABreakableWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABreakableWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakableWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void ABreakableWall::AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldActor)
//{
//	geometryComponent->InitializationFields.Empty();
//
//	for (int j = 0; j < fieldActor.Num(); j++)
//	{
//		//set anchor field as initialization field for each destructible
//		geometryComponent->InitializationFields.Add(Cast<AFieldSystemActor>(fieldActor[j])); 
//	}
//
//}

