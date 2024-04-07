// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ResourceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGEJAMEFINAL_API UResourceComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UResourceComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintCallable)
	void DecreseValue(float Decreaser = 1);
	UFUNCTION(BlueprintCallable)
	void IncreaseValue(float Increaser = 1);
	UFUNCTION(BlueprintCallable)
	float GetResourceValue(){ return Value; };
	UFUNCTION(BlueprintCallable)
	void SetResourceValue(float NewValue) { Value = NewValue; };
	UPROPERTY(EditAnywhere)
	float MaxValue{ 100 };

private:
	UPROPERTY(EditAnywhere)
	float Value{ 0 };
		
};
