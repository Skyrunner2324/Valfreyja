// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageModifier.h"

#include "Kismet/GameplayStatics.h"
#include "TimeSlippage.h"
#include "MathUtil.h"

#include "DebugLog.h"

#include "Components/PrimitiveComponent.h"


// Sets default values for this component's properties
UTimeSlippageModifier::UTimeSlippageModifier()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTimeSlippageModifier::BeginPlay()
{
	Super::BeginPlay();

	// retrieve the only ATimeSlippage object
	TArray<AActor*> arr;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATimeSlippage::StaticClass(), arr);
	timeSlippage = (ATimeSlippage*)arr[0];
}


// Called every frame
void UTimeSlippageModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	localTime += localTimeScale * DeltaTime * timeSlippage->GetGlobalTimeScale();
	deltaTime = localTimeScale * DeltaTime;
	managedDeltaTime = localTimeScale * DeltaTime * timeSlippage->GetGlobalTimeScale();

	DebugLogPerFrame(FColor::Red, TEXT("%f"), localTime);

}

void UTimeSlippageModifier::SetLocalTimeScale(const float newScale)
{
	localTimeScale = newScale;
	GetOwner()->CustomTimeDilation = localTimeScale;
}