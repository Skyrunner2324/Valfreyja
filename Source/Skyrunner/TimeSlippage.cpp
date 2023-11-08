// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippage.h"

#include "Kismet/GameplayStatics.h"

#include "DebugLog.h"


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
	globalTime += DeltaTime;
	globalManagedDeltaTime = DeltaTime * globalTimeScale;


	// application time debug display
	DebugLogPerFrame(FColor::Yellow, TEXT("Application time : %f"), GetWorld()->GetTimeSeconds());
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

	// TODO : OnGlobalTimeScaleChange()
}