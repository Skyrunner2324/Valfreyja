// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippage.h"

#include "Kismet/GameplayStatics.h"
#include "TimeSlippageModifier.h"

#include "DebugLog.h"


// Sets default values
ATimeSlippage::ATimeSlippage()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeSlippage::BeginPlay()
{
	Super::BeginPlay();
	SetGlobalTimeScale(globalTimeScale);


	// reference to every recorders
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), modifiers);
	//for (auto& r : modifiers)
	//{
	//}
}

void ATimeSlippage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	globalTime += DeltaTime;
	globalManagedDeltaTime = DeltaTime * globalTimeScale;


	// application time debug display
	DebugLogPerFrame(FColor::Yellow, TEXT("Application time : %f"), GetWorld()->GetTimeSeconds());
}

void ATimeSlippage::SetGlobalTimeScale(const float newScale)
{
	globalTimeScale = newScale;
	GetWorldSettings()->SetTimeDilation(globalTimeScale);

	bIsDilated = newScale != 1.f;
}