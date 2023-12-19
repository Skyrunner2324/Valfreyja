// Copyright Epic Games, Inc. All Rights Reserved.

#include "TimelineHandleComponentEditor.h"

#define LOCTEXT_NAMESPACE "FTimelineHandleComponentEditorModule"

void FTimelineHandleComponentEditorModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	TimelineHandleAssetTypeActions = MakeShared<FTimelineHandleAssetTypeActions>();
	FAssetToolsModule::GetModule().Get().RegisterAssetTypeActions(TimelineHandleAssetTypeActions.ToSharedRef());
}

void FTimelineHandleComponentEditorModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (!FModuleManager::Get().IsModuleLoaded("AssetTools")) return;
	FAssetToolsModule::GetModule().Get().UnregisterAssetTypeActions(TimelineHandleAssetTypeActions.ToSharedRef());
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTimelineHandleComponentEditorModule, TimelineHandleComponentEditor)