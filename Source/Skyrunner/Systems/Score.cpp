// Fill out your copyright notice in the Description page of Project Settings.


#include "Score.h"

// Sets default values
AScore::AScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScore::Reset()
{
	TotalTime = 0.f;
	CheckpointsTime.Reset();
}

