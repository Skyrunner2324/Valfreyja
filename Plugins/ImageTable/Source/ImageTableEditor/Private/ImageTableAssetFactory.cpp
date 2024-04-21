// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageTableAssetFactory.h"
#include "ImageTableAsset.h"

UImageTableAssetFactory::UImageTableAssetFactory()
{
    SupportedClass = UImageTableAsset::StaticClass();
    bCreateNew = true;
}

UObject* UImageTableAssetFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
    return NewObject<UImageTableAsset>(InParent, Class, Name, Flags, Context);
}