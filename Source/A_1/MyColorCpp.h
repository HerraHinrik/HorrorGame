// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "MyColorCpp.generated.h"

UCLASS()
class A_1_API AMyColorCpp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyColorCpp();

	UPROPERTY(Editanywhere)
		float mytime = 1.f;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UMaterialInstanceDynamic* DynamicMaterial;

	//Offset to move
	UPROPERTY(EditAnywhere)
		FVector MoveOffset;

	//Speed
	UPROPERTY(EditAnywhere)
		float Speed = 1.0f;

	// Computed Locations
	FVector StartRelativeLocation;
	FVector MoveOffsetNorm;
	float MaxDistance = 0.0f;
	float CurDistance = 0.0f;
	int MoveDirection = 1;
};
