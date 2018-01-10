// Fill out your copyright notice in the Description page of Project Settings.

#include "PowerUp.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
APowerUp::APowerUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PowerUpEnum = static_cast<EPowerUpType>(rand() % 4);

	PPMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("cylinder"));
	SetRootComponent(PPMesh);
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("Static Mesh'/Engine/BasicShapes/Cylinder.Cylinder'"));
	if (MeshAsset.Succeeded())
		PPMesh->SetStaticMesh(MeshAsset.Object);

	ConstructorHelpers::FObjectFinder<UMaterialInstance> MatAsset(TEXT("Material'/Game/TopDownCPP/Materials/M_PowerUp_Inst.M_PowerUp_Inst'"));
	if (MatAsset.Succeeded())
		PPMesh->SetMaterial(0, MatAsset.Object);
	
	PPMesh->SetWorldScale3D(FVector(1.0f, 1.0f, 0.2f));
	PPMesh->SetCollisionProfileName(FName("OverlapAllDynamic"));

	
}

// Called when the game starts or when spawned
void APowerUp::BeginPlay()
{
	Super::BeginPlay();

	UMaterialInstanceDynamic * DynMatAsset = UMaterialInstanceDynamic::Create(PPMesh->GetMaterial(0), this);

	switch (PowerUpEnum)
	{
	case EPowerUpType::PPT_ExtraBomb:
		DynMatAsset->SetVectorParameterValue(FName("Color"), FLinearColor(0, 0, 1));
		break;
	case EPowerUpType::PPT_LongerBlast:
		DynMatAsset->SetVectorParameterValue(FName("Color"), FLinearColor(1, 0, 0));
		break;
	case EPowerUpType::PPT_SpeedBoost:
		DynMatAsset->SetVectorParameterValue(FName("Color"), FLinearColor(0, 0.2f, 0));
		break;
	case EPowerUpType::PPT_RemoteBomb:
		DynMatAsset->SetVectorParameterValue(FName("Color"), FLinearColor(1, 1, 0));
		break;
	default:
		break;
	}
	PPMesh->SetMaterial(0, DynMatAsset);
}

// Called every frame
void APowerUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator rot;
	rot.Yaw = GetActorRotation().Yaw;
	rot.Pitch = GetActorRotation().Pitch;
	rot.Roll = GetActorRotation().Roll + 180 *DeltaTime;
	SetActorRotation(rot);
}

