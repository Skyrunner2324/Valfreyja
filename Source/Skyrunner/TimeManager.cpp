// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"

#include "Kismet/GameplayStatics.h"
#include "TimeRecorder.h"

#include "DebugLog.h"


// Sets default values
ATimeManager::ATimeManager()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), recorders);
	for (auto& r : recorders)
	{
		auto* component = r->GetComponentByClass<UTimeRecorder>();
#if 0 // deprecated
		if (component)
			r->CustomTimeDilation = globalTimeScale;
#endif
	}
}

void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	globalTime += DeltaTime;
	DebugLogPerFrame(FColor::Yellow, TEXT("Application time : %f"), GetWorld()->GetTimeSeconds());

	GetWorldSettings()->SetTimeDilation(globalTimeScale);
}

void ATimeManager::SetTimeScale(const float newScale)
{
	globalTimeScale = newScale;
}