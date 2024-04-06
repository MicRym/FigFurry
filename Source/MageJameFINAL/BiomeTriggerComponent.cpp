// Fill out your copyright notice in the Description page of Project Settings.


#include "BiomeTriggerComponent.h"

UBiomeTriggerComponent::UBiomeTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
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
		UE_LOG(LogTemp, Warning, TEXT("TriggerAction Here"));
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
