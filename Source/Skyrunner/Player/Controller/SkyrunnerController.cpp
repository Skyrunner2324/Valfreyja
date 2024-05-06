// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyrunnerController.h"

#include "../../Utils/DebugLog.h"
#include "Skyrunner/SkyrunnerGameMode.h"
#include "SlateBasics.h"


void ASkyrunnerController::FellOutOfWorld(const UDamageType& dmgType)
{
	//DebugLogRed(TEXT("Fell out of world : calling implementation"));
	FellOutOfWorldImpl(&dmgType);
}

bool ASkyrunnerController::IsGamePadConnected()
{
	auto genericApplication = FSlateApplication::Get().GetPlatformApplication();
	if (genericApplication.Get() != nullptr && genericApplication->IsGamepadAttached())
	{
		return true;
	}
	return false;
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