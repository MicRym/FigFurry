// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "ResourceComponent.h"
#include "SunResourceComponent.h"
#include "EarthResourceComponent.h"
#include "WaterResourceComponent.h"
#include "BiomeTriggerComponent.generated.h"

UENUM(BlueprintType)
enum class EResourceType : uint8 {
	None	UMETA(DisplayName = "None"), 
	Sun		UMETA(DisplayName = "Sun"),
	Water	UMETA(DisplayName = "Water"),
	Earth	UMETA(DisplayName = "Earth"),
 };

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
	UPROPERTY(EditAnywhere)
	float DecreaseValue{ 1.0f };
	AActor* GetTriggerActor() const;
	UPROPERTY(EditAnywhere)
	EResourceType BiomeType{ EResourceType::None};

};
