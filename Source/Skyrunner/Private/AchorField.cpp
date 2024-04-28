// Fill out your copyright notice in the Description page of Project Settings.


#include "AchorField.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AAchorField::AAchorField()
{
	USceneComponent* root = CreateDefaultSubobject<USceneComponent>(FName("SceneRoot"));
	RootComponent = root;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxFalloff = CreateDefaultSubobject<UBoxFalloff>(TEXT("BoxFalloff"));
	UniformInteger = CreateDefaultSubobject<UUniformInteger>(TEXT("UniformInteger"));
	CullingField = CreateDefaultSubobject<UCullingField>(TEXT("CullingField"));
}

void AAchorField::OnConstruction(const FTransform& Transform)
{
	if (FieldSystemComponent == nullptr || BoxFalloff == nullptr || UniformInteger == nullptr || CullingField == nullptr)
	{
		return;
	}

	BoxFalloff->SetBoxFalloff(1.0f, 1.0f, 1.0f, 0.0f, BoxComp->GetComponentTransform(), EFieldFalloffType::Field_FallOff_None);
	UniformInteger->SetUniformInteger(EFieldFilterType::Field_Filter_Static);
	CullingField->SetCullingField(BoxFalloff, UniformInteger, EFieldCullingOperationType::Field_Culling_Outside);

	GetFieldSystemComponent()->ResetFieldSystem(); //reset *all* fields for safety
	GetFieldSystemComponent()->AddFieldCommand(true, EFieldPhysicsType::Field_DynamicState, nullptr, CullingField); //set all clusters outside of box to be dynamic, otherwise stay static 
	Super::OnConstruction(Transform);
}