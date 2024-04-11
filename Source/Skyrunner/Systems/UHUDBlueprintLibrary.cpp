#include "UHUDBlueprintLibrary.h"
#include <Kismet/GameplayStatics.h>
#include <GameFramework/Character.h>
#include <Engine/Engine.h>

void UHUDBlueprintLibrary::FindScreenEdgeLocationForWorldLocation(UObject* WorldContextObject, const FVector& InLocation, const float EdgePercent, const FVector2D ViewportCenterLoc, FVector2D& OutScreenPosition, float& OutRotationAngleDegrees, bool& bIsOnScreen)
{
	bIsOnScreen = false;
	OutRotationAngleDegrees = 0.f;
	FVector2D ScreenPosition = FVector2D();

	if (!GEngine)
	{
		return;
	}

	const FVector2D ViewportSize = FVector2D(GEngine->GameViewport->Viewport->GetSizeXY());
	const FVector2D ViewportCenter = FVector2D(ViewportSize.X * ViewportCenterLoc.X, ViewportSize.Y * ViewportCenterLoc.Y);

	UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject);

	if (!World)
	{
		return;
	}

	APlayerController* PlayerController = (WorldContextObject ? UGameplayStatics::GetPlayerController(WorldContextObject, 0) : NULL);

	if (!PlayerController)
	{
		return;
	}

	FVector CameraLoc;
	FRotator CameraRot;

	PlayerController->GetPlayerViewPoint(CameraLoc, CameraRot);

	const FVector CameraToLoc = InLocation - CameraLoc;
	FVector Forward = CameraRot.Vector();
	FVector Offset = CameraToLoc.GetSafeNormal();

	float DotProduct = FVector::DotProduct(Forward, Offset);
	bool bLocationIsBehindCamera = (DotProduct < 0);

	if (bLocationIsBehindCamera)
	{
		FVector Inverted = CameraToLoc * -1.f;
		FVector NewInLocation = CameraLoc + Inverted;

		PlayerController->ProjectWorldLocationToScreen(NewInLocation, ScreenPosition);

		ScreenPosition.X = ViewportSize.X - ScreenPosition.X;
		ScreenPosition.Y = ViewportSize.Y - ScreenPosition.Y;
	}
	else
	{
		PlayerController->ProjectWorldLocationToScreen(InLocation, ScreenPosition);
	}

	// Check to see if it's on screen. If it is, ProjectWorldLocationToScreen is all we need, return it.
	if (ScreenPosition.X >= 0.f && ScreenPosition.X <= ViewportSize.X
		&& ScreenPosition.Y >= 0.f && ScreenPosition.Y <= ViewportSize.Y && !bLocationIsBehindCamera)
	{
		OutScreenPosition = ScreenPosition;
		bIsOnScreen = true;
		return;
	}

	ScreenPosition -= ViewportCenter;

	float AngleRadians = FMath::Atan2(ScreenPosition.Y, ScreenPosition.X);
	AngleRadians -= FMath::DegreesToRadians(90.f);

	OutRotationAngleDegrees = FMath::RadiansToDegrees(AngleRadians) + 180.f;

	float Cos = cosf(AngleRadians);
	float Sin = -sinf(AngleRadians);

	ScreenPosition = FVector2D(ViewportCenter.X + (Sin * 150.f), ViewportCenter.Y + Cos * 150.f);

	float m = Cos / Sin;

	FVector2D ScreenBounds = ViewportCenter * EdgePercent;

	if (Cos > 0)
	{
		ScreenPosition = FVector2D(ScreenBounds.Y / m, ScreenBounds.Y);
	}
	else
	{
		ScreenPosition = FVector2D(-ScreenBounds.Y / m, -ScreenBounds.Y);
	}

	if (ScreenPosition.X > ScreenBounds.X)
	{
		ScreenPosition = FVector2D(ScreenBounds.X, ScreenBounds.X * m);
	}
	else if (ScreenPosition.X < -ScreenBounds.X)
	{
		ScreenPosition = FVector2D(-ScreenBounds.X, -ScreenBounds.X * m);
	}

	ScreenPosition += ViewportCenter;

	OutScreenPosition = ScreenPosition;
}

bool UHUDBlueprintLibrary::ProjectWorldToScreenBidirectional(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool& bTargetBehindCamera, bool bPlayerViewportRelative)
{
	FVector Projected;
	bool bSuccess = false;

	ULocalPlayer* const LP = Player ? Player->GetLocalPlayer() : nullptr;
	if (LP && LP->ViewportClient)
	{
		// get the projection data
		FSceneViewProjectionData ProjectionData;
		if (LP->GetProjectionData(LP->ViewportClient->Viewport, /*out*/ ProjectionData))
		{
			const FMatrix ViewProjectionMatrix = ProjectionData.ComputeViewProjectionMatrix();
			const FIntRect ViewRectangle = ProjectionData.GetConstrainedViewRect();

			FPlane Result = ViewProjectionMatrix.TransformFVector4(FVector4(WorldPosition, 1.f));
			if (Result.W < 0.f) { bTargetBehindCamera = true; }
			else { bTargetBehindCamera = false; }
			if (Result.W == 0.f) { Result.W = 1.f; } // Prevent Divide By Zero

			const float RHW = 1.f / FMath::Abs(Result.W);
			Projected = FVector(Result.X, Result.Y, Result.Z) * RHW;

			// Normalize to 0..1 UI Space
			const float NormX = (Projected.X / 2.f) + 0.5f;
			const float NormY = 1.f - (Projected.Y / 2.f) - 0.5f;

			Projected.X = (float)ViewRectangle.Min.X + (NormX * (float)ViewRectangle.Width());
			Projected.Y = (float)ViewRectangle.Min.Y + (NormY * (float)ViewRectangle.Height());

			bSuccess = true;
			ScreenPosition = FVector2D(Projected.X, Projected.Y);

			if (bPlayerViewportRelative)
			{
				ScreenPosition -= FVector2D(ProjectionData.GetConstrainedViewRect().Min);
			}
		}
		else
		{
			ScreenPosition = FVector2D(1234, 5678);
		}
	}

	return bSuccess;
}
