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

void ASkyrunnerGameMode::ResetPlayer(const FString PlayerStartTag)
{
	// get player 1 (the only player in a singleplayer game)
	auto player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	player->Destroy();

	// find player start and restart player
	auto controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	AActor* playerStart = nullptr;
	if (PlayerStartTag != "None")
		playerStart = FindPlayerStart(controller, PlayerStartTag);
	else
		playerStart = FindPlayerStart(controller);

	RestartPlayerAtPlayerStart(controller, playerStart);


	// broadcast delegate that should reset player controller and player HUD
	OnPlayerResetEvent.Broadcast();
}
