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
	void DecreseValue(int32 Decreaser = 1);
	UFUNCTION(BlueprintCallable)
	void IncreaseValue(int32 Increaser = 1);
	UFUNCTION(BlueprintCallable)
	int32 GetResourceValue(){ return Value; };
	UFUNCTION(BlueprintCallable)
	void SetResourceValue(int32 NewValue) { Value = NewValue; };
private:
	UPROPERTY(EditAnywhere)
	int32 Value{ 0 };
		
};
