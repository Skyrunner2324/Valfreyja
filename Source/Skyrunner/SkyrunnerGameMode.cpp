// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkyrunnerGameMode.h"
#include "Player/Character/SkyrunnerCharacter.h"
#include "UObject/ConstructorHelpers.h"


#include "Kismet/GameplayStatics.h"
#include "Engine/LevelStreaming.h"


#include "TimeManagement/TimeSlippage.h"

#include "Utils/DebugLog.h"


ASkyrunnerGameMode::ASkyrunnerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;
}

void ASkyrunnerGameMode::StartPlay()
{
	// TODO : find a way to spawn BP
	//if (timeSlippage)
	//	GetWorld()->SpawnActor<ATimeSlippage>(timeSlippage->GetClass());
	//if (actorPooled)
	//	GetWorld()->SpawnActor<AActor>(actorPooled->GetClass(),
	//		FVector(0.f, 0.f, 0.f),
	//		FRotator(0.f, 0.f, 0.f));

	Super::StartPlay();
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

void ASkyrunnerGameMode::UnloadOldestMap()
{
	UWorld* world = GEngine->GetWorld();
	if (!world)
		world = GEngine->GameViewport->GetWorld();
	check(world);


	auto allLevels = world->GetStreamingLevels();
	for (auto l : allLevels)
	{
		DebugLogString(15.f, FColor::Purple, l->GetName());
	}
	auto oldestMap = allLevels[0];
	if (oldestMap)
		DebugLogString(15.f, FColor::Red, oldestMap->GetName());
	else
		DebugLogRed(TEXT("Could not find map"));


	// TODO : does not work when level is loaded using OpenLevel
	oldestMap->SetIsRequestingUnloadAndRemoval(true);
}
