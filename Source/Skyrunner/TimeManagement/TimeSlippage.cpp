// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippage.h"

#include "Kismet/GameplayStatics.h"

#include "../Utils/DebugLog.h"

#include "TimeSlippageModifier.h"


ATimeSlippage::ATimeSlippage()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATimeSlippage::BeginPlay()
{
	Super::BeginPlay();
	SetGlobalTimeScale(globalTimeScale);
}

void ATimeSlippage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	applicationTime = GetWorld()->RealTimeSeconds;
	globalTime = GetWorld()->TimeSeconds;
	applicationDeltaTime = GetWorld()->DeltaRealTimeSeconds;
	// no need to "manage" deltatime
	globalManagedDeltaTime = DeltaTime/* * globalTimeScale*/;


	// application time debug display
	//DebugLogPerFrame(FColor::Yellow, TEXT("Global time : %f"), globalTime);
	//DebugLogPerFrame(FColor::Yellow, TEXT("Application time : %f"), applicationTime);
	DebugLogPerFrame(FColor::Green, TEXT("frame rate : %f"), 1.f / applicationDeltaTime);
}

ATimeSlippage* ATimeSlippage::Get(UWorld* world)
{
	return Cast<ATimeSlippage>(UGameplayStatics::GetActorOfClass(world, ATimeSlippage::StaticClass()));
}

void ATimeSlippage::SetGlobalTimeScale(const float newScale)
{
	globalTimeScale = newScale;
	GetWorldSettings()->SetTimeDilation(globalTimeScale);

	bIsDilated = newScale != 1.f;

	// update every modifiers
	OnTimeScaleChanged.Broadcast(newScale);
}