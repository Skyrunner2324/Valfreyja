// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeRecorder.h"

#include "TimeManager.h"
#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTimeRecorder::UTimeRecorder()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
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

	// TODO : upgrade

	// TODO : naive rotation
	FVector dir = GetOwner()->GetTransform().GetLocation() - oldTransform.GetLocation();
	GetOwner()->SetActorLocation(oldTransform.GetLocation() + dir * timeManager->GetTimeScale());

	oldTransform = GetOwner()->GetTransform();
}

