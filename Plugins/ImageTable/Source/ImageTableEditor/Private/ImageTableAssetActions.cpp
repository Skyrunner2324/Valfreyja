// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageTableAssetActions.h"
#include "ImageTableAsset.h"

UClass* FImageTableAssetTypeActions::GetSupportedClass() const
{
    return UImageTableAsset::StaticClass();
}

FText FImageTableAssetTypeActions::GetName() const
{
    return INVTEXT("Image Table");
}

FColor FImageTableAssetTypeActions::GetTypeColor() const
{
    return FColor::Red;
}

uint32 FImageTableAssetTypeActions::GetCategories()
{
    return EAssetTypeCategories::Misc;
}
