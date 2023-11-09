// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeSlippageModifier.h"

#include "Kismet/GameplayStatics.h"
#include "TimeSlippage.h"

#include "../Utils/DebugLog.h"


// Sets default values for this component's properties
UTimeSlippageModifier::UTimeSlippageModifier()
{
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UTimeSlippageModifier::BeginPlay()
{
	Super::BeginPlay();
	SetLocalTimeScale(localTimeScale);
	timeSlippage = ATimeSlippage::Get(GetWorld());
	timeSlippage->modifiers.Add(this);
}


// Called every frame
void UTimeSlippageModifier::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	deltaTime = localTimeScale * DeltaTime;
	localManagedDeltaTime = localTimeScale * timeSlippage->globalManagedDeltaTime;
	localTime += localManagedDeltaTime;

	//DebugLogPerFrame(FColor::Red, TEXT("%f"), localTime);

	// TODO : event OnGlobalTimeScaleChange()
	if (!bOverrideTarget && timeSlippage->GetGlobalTimeScale() != 0.f)
		SetLocalTimeScale(localTimeScaleTarget / timeSlippage->GetGlobalTimeScale());
}

void UTimeSlippageModifier::SetLocalTimeScale(const float newScale)
{
	localTimeScale = newScale;
	GetOwner()->CustomTimeDilation = localTimeScale;
}