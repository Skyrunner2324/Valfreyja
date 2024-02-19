// Fill out your copyright notice in the Description page of Project Settings.

#include "FOVFreeSkeletalMeshComponent.h"

FMatrix UFOVFreeSkeletalMeshComponent::GetRenderMatrix() const
{
	FMatrix InverseOldViewProjectionMatrix;
	FMatrix NewViewProjectionMatrix;

	const FMatrix ModelMatrix = GetComponentTransform().ToMatrixWithScale();

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController) {
		ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(PlayerController->Player);

		if (LocalPlayer && LocalPlayer->ViewportClient && LocalPlayer->ViewportClient->Viewport) {
			FSceneViewFamilyContext ViewFamily
			(
				FSceneViewFamily::ConstructionValues(LocalPlayer->ViewportClient->Viewport, GetWorld()->Scene, LocalPlayer->ViewportClient->EngineShowFlags)
				.SetRealtimeUpdate(true)
			);

			FVector ViewLocation;
			FRotator ViewRotation;
			FSceneView* SceneView = LocalPlayer->CalcSceneView(&ViewFamily, ViewLocation, ViewRotation, LocalPlayer->ViewportClient->Viewport);

			if (!SceneView) {
				return ModelMatrix;
			}

			const float DesiredFov = 90.0f;
			const float DesiredHalfFovRad = DesiredFov * PI / 360.0f;

			const auto ViewportSize = LocalPlayer->ViewportClient->Viewport->GetSizeXY();
			const float Width = ViewportSize.X;
			const float Height = ViewportSize.Y;
			const float NearClippingPlaneDistance = SceneView->NearClippingDistance;

			const FMatrix NewProjectionMatrix = FReversedZPerspectiveMatrix(DesiredHalfFovRad, Width, Height, NearClippingPlaneDistance);
			
			const FMatrix ViewMatrix = SceneView->ViewMatrices.GetViewMatrix();
			const FMatrix InverseViewMatrix = SceneView->ViewMatrices.GetInvViewMatrix();
			
			const FMatrix ProjectionMatrix = SceneView->ViewMatrices.GetProjectionMatrix();
			const FMatrix InverseProjectionMatrix = SceneView->ViewMatrices.GetInvProjectionMatrix();

			NewViewProjectionMatrix = ViewMatrix * NewProjectionMatrix;
			InverseOldViewProjectionMatrix = InverseProjectionMatrix * InverseViewMatrix;
		}
	}

	return ModelMatrix * NewViewProjectionMatrix * InverseOldViewProjectionMatrix;
}
