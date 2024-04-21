// Copyright Epic Games, Inc. All Rights Reserved.

#include "ImageTableEditor.h"

#define LOCTEXT_NAMESPACE "FImageTableEditorModule"

void FImageTableEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	ImageTableAssetTypeActions = MakeShared<FImageTableAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(ImageTableAssetTypeActions.ToSharedRef());
}

void FImageTableEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools"))
		return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(ImageTableAssetTypeActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FImageTableEditorModule, ImageTableEditor)