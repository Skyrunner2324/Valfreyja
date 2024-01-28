// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyController.h"


#include "Perception/AIPerceptionComponent.h"

#include "Perception/AISense_Sight.h"
#include "Perception/AISenseConfig_Sight.h"



AEnemyController::AEnemyController()
{
    perception = CreateDefaultSubobject<UAIPerceptionComponent>(FName("Perception component"));

	// add sight sense config

	perception->SetDominantSense(UAISense_Sight::StaticClass());

	UAISenseConfig_Sight* sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("SightSenseConfig"));
	sight->DetectionByAffiliation.bDetectEnemies = true;
	sight->DetectionByAffiliation.bDetectFriendlies = true;
	sight->DetectionByAffiliation.bDetectNeutrals = true;

	perception->ConfigureSense(*sight);
}