// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyrunnerController.h"

#include "../../Utils/DebugLog.h"
#include "Skyrunner/SkyrunnerGameMode.h"


void ASkyrunnerController::FellOutOfWorld(const UDamageType& dmgType)
{
	//DebugLogRed(TEXT("Fell out of world : calling implementation"));
	FellOutOfWorldImpl(&dmgType);
}

ASpectatorPawn* ASkyrunnerController::SpawnSpectatorPawn()
{
	const auto& gm = Cast<ASkyrunnerGameMode>(GetWorld()->GetAuthGameMode());
	AActor* ps = gm->FindPlayerStart(this, "MenuStart");
	SetSpawnLocation(ps->GetActorLocation());
	return Super::SpawnSpectatorPawn();
}

void ASkyrunnerController::FellOutOfWorldImpl_Implementation(const UDamageType* dmgType)
{
	//DebugLogRed(TEXT("Fell out of world : default implementation"));
}