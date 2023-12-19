// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "TimelineHandleFactory.generated.h"

/**
 * 
 */
UCLASS()
class TIMELINEHANDLECOMPONENTEDITOR_API UTimelineHandleFactory : public UFactory
{
	GENERATED_BODY()
	
public:
	UTimelineHandleFactory();
	UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn);
};
