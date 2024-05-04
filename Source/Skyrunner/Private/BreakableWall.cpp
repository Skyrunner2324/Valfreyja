// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakableWall.h"
#include "Field/FieldSystemActor.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Engine/EngineTypes.h"
#include "AchorField.h"
#include "Components/ChildActorComponent.h"

ABreakableWall::ABreakableWall()
{
	PrimaryActorTick.bCanEverTick = true;
	//this->GetComponents<UGeometryComponentBreakableWall>(GeometryCollectionActors);
	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(FName("SceneRoot"));
	RootComponent = root;

	instanceGeometryComponent = CreateDefaultSubobject<UGeometryComponentBreakableWall>(FName("GeometryCollection"));
	instanceGeometryComponent->SetupAttachment(RootComponent);
	instanceGeometryComponent->SetSimulatePhysics(false);

	numberOfAnchorToSpawn = 3;

	/*for (size_t i = 0; i < numberOfAnchorToSpawn; i++)
	{*/
		/*anchor = CreateDefaultSubobject<UChildActorComponent>(TEXT("AnchorField"));
		anchor->SetChildActorClass(AAchorField::StaticClass());
		anchor->SetupAttachment(RootComponent);*/
	//}
}

// Called when the game starts or when spawned
void ABreakableWall::BeginPlay()
{
	Super::BeginPlay();
}

//void ABreakableWall::AddAnchor(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldActor)
//{
//	//if (geometryComponent == nullptr)
//	//	return;
//
//	//geometryComponent->InitializationFields.Empty();
//
//	//for (int j = 0; j < fieldActor.Num(); j++)
//	//{
//	//	//set anchor field as initialization field for each destructible
//	//	geometryComponent->InitializationFields.Add(Cast<AFieldSystemActor>(fieldActor[j]));
//	//}
//
//}
//
//void ABreakableWall::GetAnchor()
//{
//
//}
//
void ABreakableWall::RegisterAllComponents()
{
	//if (anchorContainer != nullptr) {
	//TArray<UActorComponent*> ParticleComponents = GetComponentsByClass(AFieldSystemActor::StaticClass());

	/*if (anchors.IsEmpty())
		return;

	AddAnchor(instanceGeometryComponent, anchors);*/

	//}
	FString tagAnchor = "AnchorField";

	if(GetOwner() != nullptr)
		tagAnchor = "Anchor" + GetOwner()->GetName();

	UGameplayStatics::GetAllActorsOfClassWithTag(this, AFieldSystemActor::StaticClass(), FName(tagAnchor), anchorFields);
	/*GetComponents<UGeometryComponentBreakableWall>(GeometryCollectionActors);*/

	/*for (int i = 0; i < GeometryCollectionActors.Num(); ++i)
	{
		UGeometryCollectionComponent* geometryCollectionComp = Cast<UGeometryCollectionComponent>(GeometryCollectionActors[i]);*/
		if (instanceGeometryComponent != nullptr || !anchorFields.IsEmpty())
		{
			instanceGeometryComponent->InitializationFields.Empty();
			for (int j = 0; j < anchorFields.Num(); j++)
			{
				if (anchorFields.IsValidIndex(j))
				{
					instanceGeometryComponent->InitializationFields.Add(Cast<AFieldSystemActor>(anchorFields[j])); //set anchor field as initialization field for each destructible
				}
			}
			//geometryCollectionComp->RegisterAndInitializePhysicsProxy(); //this looks like it does something, but it bugs out and breaks most of the destructibles.
		}
	//}
}

