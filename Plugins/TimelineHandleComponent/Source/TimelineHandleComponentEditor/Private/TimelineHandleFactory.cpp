// Fill out your copyright notice in the Description page of Project Settings.


#include "TimelineHandleFactory.h"

#include "TimelineHandleComponent/Public/TimelineHandle.h"


UTimelineHandleFactory::UTimelineHandleFactory()
{
	SupportedClass = UTimelineHandle::StaticClass();
	bCreateNew = true;
}

UObject* UTimelineHandleFactory::FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTimelineHandle>(InParent, Class, Name, Flags, Context);
}
