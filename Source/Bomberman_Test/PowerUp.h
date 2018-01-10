// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUp.generated.h"

UENUM(BlueprintType)
enum class EPowerUpType : uint8
{
	PPT_ExtraBomb	 	UMETA(DisplayName = "ExtraBomb"),
	PPT_LongerBlast	 	UMETA(DisplayName = "LongerBlast"),
	PPT_SpeedBoost		UMETA(DisplayName = "SpeedBoost"),
	PPT_RemoteBomb		UMETA(DisplayName = "RemoteBomb"),
	PPT_Default			UMETA(DisplayName = "Default")

};

UCLASS()
class BOMBERMAN_TEST_API APowerUp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUp();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = PowerUps)
	EPowerUpType GetPowerUpType() const { return PowerUpEnum;  }

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enum)
	EPowerUpType PowerUpEnum;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(Category = Meshes, VisibleAnywhere)
	class UStaticMeshComponent * PPMesh;
};
