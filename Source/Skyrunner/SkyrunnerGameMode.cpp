// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkyrunnerGameMode.h"
#include "SkyrunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"


#include "Kismet/GameplayStatics.h"


ASkyrunnerGameMode::ASkyrunnerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ASkyrunnerGameMode::ResetPlayer(const bool bDestroyPlayerBeforeReset,
	const FString PlayerStartTag)
{
	if (bDestroyPlayerBeforeReset)
	{
		// get player 1 (the only player in a singleplayer game)
		auto player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
#if 1
		GetWorld()->DestroyActor(player);
#else
		player->Destroy();
#endif
	}

	auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerStartTag == "None")
	{
		RestartPlayer(controller);
	}
	else
	{
		// find player start and restart player
		AActor* playerStart = FindPlayerStart(controller, PlayerStartTag);
		RestartPlayerAtPlayerStart(controller, playerStart);
	}

	// broadcast delegate that should reset player controller and player HUD
	OnPlayerResetEvent.Broadcast();
}
