// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUp.h"
#include "BreakableWall.generated.h"



UCLASS()
class BOMBERMAN_TEST_API ABreakableWall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABreakableWall();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = PowerUps)
	APowerUp * DropPowerUp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	

	UPROPERTY(Category = Meshes, VisibleAnywhere)
	class UStaticMeshComponent * BoxMesh;
	
};
