// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

#include "TimelineHandleActions.h"


class FTimelineHandleComponentEditorModule : public IModuleInterface
{
private:
	TSharedPtr<FTimelineHandleAssetTypeActions> TimelineHandleAssetTypeActions;


public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
