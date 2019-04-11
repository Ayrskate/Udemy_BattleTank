// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//aim where cross intersects the world
	void AimTowardsCrosshair();

	UPROPERTY(EditAnywhere)
		float CHLocationX = 0.5f;

	UPROPERTY(EditAnywhere)
		float CHLocationY = 0.3333f;

private:
	bool GetSightRayHitLocation(FVector& hitLocation) const;
};
