// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetTypeActions_Base.h"

/**
 * 
 */
class TIMELINEHANDLECOMPONENTEDITOR_API FTimelineHandleAssetTypeActions : public FAssetTypeActions_Base
{
public:
	FTimelineHandleAssetTypeActions();
	~FTimelineHandleAssetTypeActions();

	UClass* GetSupportedClass() const override;
	FText GetName() const override;
	FColor GetTypeColor() const override;
	uint32 GetCategories() override;
};
