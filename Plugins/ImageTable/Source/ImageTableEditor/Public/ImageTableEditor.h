// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "ImageTableAssetActions.h"

class FImageTableEditorModule : public IModuleInterface
{
private:
	TSharedPtr<FImageTableAssetTypeActions> ImageTableAssetTypeActions;
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
