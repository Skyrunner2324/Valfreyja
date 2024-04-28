// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Field/FieldSystemActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AchorField.generated.h"

/**
 * 
 */
UCLASS()
class SKYRUNNER_API AAchorField : public AFieldSystemActor
{
	GENERATED_BODY()

	AAchorField();
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* BoxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UCullingField* CullingField;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxFalloff* BoxFalloff;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UUniformInteger* UniformInteger;
	

};
