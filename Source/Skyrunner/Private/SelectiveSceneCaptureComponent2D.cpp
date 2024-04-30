// Fill out your copyright notice in the Description page of Project Settings.


#include "SelectiveSceneCaptureComponent2D.h"

void USelectiveSceneCaptureComponent2D::AddComponentToHide(UPrimitiveComponent* component)
{
	HideComponent(component);
}

void USelectiveSceneCaptureComponent2D::AddOnlyComponentToShow(UPrimitiveComponent* component)
{
	ShowOnlyComponents.Add(component);
}