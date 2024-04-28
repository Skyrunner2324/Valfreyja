// Fill out your copyright notice in the Description page of Project Settings.


#include "GeometryComponentBreakableWall.h"

void UGeometryComponentBreakableWall::InitializeAnchorField(UGeometryCollectionComponent* geometryComponent, TArray<AActor*> fieldsActor)
{
	InitializationFields.Empty();

	for (int j = 0; j < fieldsActor.Num(); j++)
	{
		//set anchor field as initialization field for each destructible
		InitializationFields.Add(Cast<AFieldSystemActor>(fieldsActor[j]));
	}

}
