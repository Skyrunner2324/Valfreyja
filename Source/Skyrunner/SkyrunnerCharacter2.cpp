// Fill out your copyright notice in the Description page of Project Settings.


#include "SkyrunnerCharacter2.h"


#include "Utils/DebugLog.h"


// Sets default values
ASkyrunnerCharacter2::ASkyrunnerCharacter2()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASkyrunnerCharacter2::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ASkyrunnerCharacter2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASkyrunnerCharacter2::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASkyrunnerCharacter2::FellOutOfWorld(const UDamageType& dmgType)
{
	DebugLogRed(TEXT("Fell out of world : calling implementation"));
	FellOutOfWorldImpl(&dmgType);
}

void ASkyrunnerCharacter2::FellOutOfWorldImpl_Implementation(const UDamageType* dmgType)
{
	DebugLogRed(TEXT("Fell out of world : default implementation"));
}

