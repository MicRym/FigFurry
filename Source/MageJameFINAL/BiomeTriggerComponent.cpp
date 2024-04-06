// Fill out your copyright notice in the Description page of Project Settings.


#include "BiomeTriggerComponent.h"

UBiomeTriggerComponent::UBiomeTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UBiomeTriggerComponent::Shoot()
{
	AActor* Actor = GetTriggerActor();
	UResourceComponent* ResourceSun = nullptr;
	UResourceComponent* ResourceDirt = nullptr;
	UResourceComponent* ResourceWater = nullptr;
	if (Actor != nullptr)
	{
		ResourceSun = Actor->GetComponentByClass<USunResourceComponent>();

		ResourceDirt = Actor->GetComponentByClass<UWaterResourceComponent>();

		ResourceWater = Actor->GetComponentByClass<UEarthResourceComponent>();
	}
			ResourceSun->DecreseValue(DecreaseValue);
			ResourceDirt->DecreseValue(DecreaseValue);
			ResourceWater->DecreseValue(DecreaseValue);



}

void UBiomeTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UBiomeTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);	
	AActor* Actor = GetTriggerActor();
	if (Actor == nullptr)
	{
	}
	else 
	{

		UResourceComponent* Resource =nullptr;
		switch (BiomeType)
		{
		case EResourceType::None:
			break;
		case EResourceType::Sun:
			Resource = Actor->GetComponentByClass<USunResourceComponent>();
			break;
		case EResourceType::Water:
			UE_LOG(LogTemp, Warning, TEXT("TriggerAction Here"));
			Resource = Actor->GetComponentByClass<UWaterResourceComponent>();
			break;
		case EResourceType::Earth:
			Resource = Actor->GetComponentByClass<UEarthResourceComponent>();
			break;
		default:
			break;
		}
		if (Resource)
		{
			Resource->IncreaseValue(DecreaseValue *DeltaTime);
			UE_LOG(LogTemp, Warning, TEXT("Current Value %f"), Resource->GetResourceValue());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Resource Not Found Here"));
		}

	}
}

AActor* UBiomeTriggerComponent::GetTriggerActor() const
{
	AActor* ReturnActor{ nullptr };
	TArray<AActor*> Actors;
	GetOverlappingActors(Actors);
	FString LogString;
	for (AActor* Actor : Actors)
	{
		if (Actor->ActorHasTag("PlayerTag"))
		{
			ReturnActor = Actor;
			break;
		}
	}
	return ReturnActor;
}
