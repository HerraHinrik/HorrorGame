// Fill out your copyright notice in the Description page of Project Settings.


#include "MyColorCpp.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInterface.h"
#include "Components/SceneComponent.h"
#include <GameFramework/RootMotionSource.h>

// Sets default values
AMyColorCpp::AMyColorCpp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyColorCpp::BeginPlay()
{
	Super::BeginPlay();

	auto Cube = FindComponentByClass<UStaticMeshComponent>();
	auto Material = Cube->GetMaterial(0);

	DynamicMaterial = UMaterialInstanceDynamic::Create(Material, NULL);
	Cube->SetMaterial(0, DynamicMaterial);

	// Set Start Location
	StartRelativeLocation = GetActorLocation();

	//Compute Normalized movement 
	MoveOffsetNorm = MoveOffset;
	MoveOffsetNorm.Normalize();
	MaxDistance = MoveOffset.Length();
	
}

// Called every frame
void AMyColorCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	float blend = 0.5f + FMath::Cos(GetWorld()->TimeSeconds) / AMyColorCpp::mytime;
	DynamicMaterial->SetScalarParameterValue(TEXT("Blend"), blend);

	//Set currant distance
	CurDistance += DeltaTime * Speed * MoveDirection;
	if (CurDistance >= MaxDistance || CurDistance < 0.0f)
		MoveDirection *= -1;
	// compute and set Current Location
	SetActorLocation(StartRelativeLocation + MoveOffsetNorm * CurDistance);

}

