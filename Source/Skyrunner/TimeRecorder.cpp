// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeRecorder.h"

#include "Kismet/GameplayStatics.h"
#include "TimeManager.h"
#include "MathUtil.h"

#include "DebugLog.h"

#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UTimeRecorder::UTimeRecorder()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTimeRecorder::BeginPlay()
{
	Super::BeginPlay();

	oldTransform = GetOwner()->GetTransform();

	// retrieve the only ATimeManager object
	TArray<AActor*> arr;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeManager::StaticClass(), arr);
	timeManager = (ATimeManager*)arr[0];
}


// Called every frame
void UTimeRecorder::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	localTime += localTimeScale * DeltaTime * timeManager->GetTimeScale();
	deltaTime = localTimeScale * DeltaTime;
	managedDeltaTime = localTimeScale * DeltaTime * timeManager->GetTimeScale();

	DebugLogPerFrame(FColor::Red, TEXT("%f"), localTime);

	GetOwner()->CustomTimeDilation = localTimeScale;
}

