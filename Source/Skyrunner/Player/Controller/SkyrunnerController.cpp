// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyrunnerController.h"

#include "../../Utils/DebugLog.h"


void ASkyrunnerController::FellOutOfWorld(const UDamageType& dmgType)
{
	//DebugLogRed(TEXT("Fell out of world : calling implementation"));
	FellOutOfWorldImpl(&dmgType);
}

void ASkyrunnerController::FellOutOfWorldImpl_Implementation(const UDamageType* dmgType)
{
	//DebugLogRed(TEXT("Fell out of world : default implementation"));
}