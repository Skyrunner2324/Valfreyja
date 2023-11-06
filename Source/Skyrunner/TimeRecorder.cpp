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


#if 0 // deprecated
	FVector rectifiedLocationLerp = oldTransform.GetLocation();
	FQuat rectifiedRotationSlerp = oldTransform.GetRotation();
	FVector rectifiedScaleLerp = oldTransform.GetScale3D();

	const FTransform& newTransform = GetOwner()->GetTransform();
	const FTransform diffTransform = newTransform - oldTransform;


	// rectification done after transform update
	if (diffTransform.GetLocation().SquaredLength() > TMathUtilConstants<float>::Epsilon)
	{
		rectifiedLocationLerp = FMath::Lerp(oldTransform.GetLocation(),
			GetOwner()->GetActorLocation(),
			timeManager->GetTimeScale());
	}
	if (diffTransform.GetRotation().GetAngle() > TMathUtilConstants<float>::Epsilon)
	{
		rectifiedRotationSlerp = FQuat::Slerp(oldTransform.GetRotation(),
			GetOwner()->GetActorRotation().Quaternion(),
			timeManager->GetTimeScale());
	}
	if (diffTransform.GetScale3D().SquaredLength() > TMathUtilConstants<float>::Epsilon)
	{
		rectifiedScaleLerp = FMath::Lerp(oldTransform.GetScale3D(),
			GetOwner()->GetActorScale(),
			timeManager->GetTimeScale());
	}


#if 0
	GetOwner()->SetActorLocation(rectifiedLocationLerp, true);
	GetOwner()->SetActorRotation(rectifiedRotationSlerp);
	GetOwner()->SetActorScale3D(rectifiedScaleLerp);
#else
	FTransform scaledDiff = diffTransform * timeManager->GetTimeScale();
	FTransform rectifiedTransform = oldTransform + scaledDiff;
	GetOwner()->SetActorLocation(rectifiedTransform.GetLocation());
	GetOwner()->SetActorRotation(rectifiedTransform.GetRotation());
	GetOwner()->SetActorScale3D(rectifiedTransform.GetScale3D());
#endif


	oldTransform = GetOwner()->GetTransform();
#endif

	DebugLogPerFrame(FColor::Red, TEXT("%f"), localTime);

	// TODO : tick update recovery

	auto movement = GetOwner()->GetComponentByClass<UPrimitiveComponent>();
	if (movement)
	{
		movement->AddVelocityChangeImpulseAtLocation(-movement->GetPhysicsLinearVelocity() *
			(1.f - timeManager->GetTimeScale()) *
			(1.f - localTimeScale) *
			managedDeltaTime *
			60.f,
			movement->GetCenterOfMass());
	}
}

