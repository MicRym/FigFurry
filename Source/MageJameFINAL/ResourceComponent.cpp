// Fill out your copyright notice in the Description page of Project Settings.


#include "ResourceComponent.h"

// Sets default values for this component's properties
UResourceComponent::UResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UResourceComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UResourceComponent::DecreseValue(float Decreaser)
{
	Value -= Decreaser;
}

void UResourceComponent::IncreaseValue(float Increaser)
{
	if (Value < MaxValue)
	{
		Value += Increaser;
	}
	else
	{
		Value = MaxValue;
	}
	
}

