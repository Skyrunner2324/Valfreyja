// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

#include "Kismet/GameplayStatics.h"
#include "TimeRecorder.h"

// Sets default values
ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), recorders);
	for (auto& r : recorders)
	{
		auto* component = r->GetComponentByClass<UTimeRecorder>();
		if (component)
			r->CustomTimeDilation = timeScale;
	}
}

void ATimeManager::SetTimeScale(const float newScale)
{
	timeScale = newScale;
}