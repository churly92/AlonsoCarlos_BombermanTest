// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakableWall.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"



// Sets default values
ABreakableWall::ABreakableWall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cube"));
	SetRootComponent(BoxMesh);
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("Static Mesh'/Engine/BasicShapes/Cube.Cube'"));
	if (MeshAsset.Succeeded())
		BoxMesh->SetStaticMesh(MeshAsset.Object);

	ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("Material'/Game/StarterContent/Materials/M_Wood_Oak.M_Wood_Oak'"));
	if (MaterialAsset.Succeeded())
		BoxMesh->SetMaterial(0,MaterialAsset.Object);
}

// Called when the game starts or when spawned
void ABreakableWall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABreakableWall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

APowerUp * ABreakableWall::DropPowerUp()
{
	APowerUp * newPowerUp = nullptr;
	if (rand() % 10 <= 3)
		newPowerUp = GetWorld()->SpawnActor<APowerUp>(GetActorLocation() + FVector(0,0,75), GetActorRotation());

	return newPowerUp;
}
