// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "BiomeTriggerComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MAGEJAMEFINAL_API UBiomeTriggerComponent : public UBoxComponent
{
	GENERATED_BODY()
public:
	UBiomeTriggerComponent();
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	AActor* GetTriggerActor() const;
};
