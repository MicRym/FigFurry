// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "BiomeTriggerComponent.h"
#include "ElementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MAGEJAMEFINAL_API UElementComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UElementComponent();
	UFUNCTION(BlueprintCallable)
	EResourceType GetElemenType() { return ElementType; };
	UFUNCTION(BlueprintCallable)
	void SetElemenType(EResourceType NewElementType) { ElementType = NewElementType; };

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
private:
	UPROPERTY(EditAnywhere)
	EResourceType ElementType{ EResourceType::None };

		
};
