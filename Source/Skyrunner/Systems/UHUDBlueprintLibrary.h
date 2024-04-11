#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UHUDBlueprintLibrary.generated.h"

UCLASS()
class SKYRUNNER_API UHUDBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	* Converts a world location to screen position for HUD drawing. This differs from the results of FSceneView::WorldToScreen in that it returns a position along the edge of the screen for offscreen locations
	*
	* @param InLocation - The world space location to be converted to screen space
	* @param EdgePercent - How close to the edge of the screen, 1.0 = at edge, 0.0 = at center of screen. .9 or .95 is usually desirable
	* @param ViewportCenterLoc - for offsetting center of the screen, leave at (0.5, 0.5) for no offset
	* @outparam OutScreenPosition - the screen coordinates for HUD drawing
	* @outparam OutRotationAngleDegrees - The angle to rotate a hud element if you want it pointing toward the offscreen indicator, 0° if onscreen
	* @outparam bIsOnScreen - True if the specified location is in the camera view (may be obstructed)
	*/
	UFUNCTION(BlueprintPure, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext), Category = "HUD|Util")
		static void FindScreenEdgeLocationForWorldLocation(UObject* WorldContextObject, const FVector& InLocation, const float EdgePercent, const FVector2D ViewportCenterLoc, FVector2D& OutScreenPosition, float& OutRotationAngleDegrees, bool& bIsOnScreen);

	UFUNCTION(BlueprintPure, Category = "UI Math")
		static bool ProjectWorldToScreenBidirectional(APlayerController const* Player, const FVector& WorldPosition, FVector2D& ScreenPosition, bool& bTargetBehindCamera, bool bPlayerViewportRelative = false);
};
