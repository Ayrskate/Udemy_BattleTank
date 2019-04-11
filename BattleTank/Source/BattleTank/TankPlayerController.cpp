// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank11: %s"),*ControlledTank->GetName());
	}


}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//aim towards crosshair
	AimTowardsCrosshair();

}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	//Raycast trough crosshair
	FVector hitLocation;

	if (GetSightRayHitLocation(hitLocation)) {
		//UE_LOG(LogTemp, Warning, TEXT("look direction: %s"), *hitLocation.ToString());

		//obtain where to aim
	}	
}

//get world location where crosshair intersects with the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& hitLocation) const
{
	//find crosshair position
	int32 viewPortX, viewPortY;
	GetViewportSize(viewPortX, viewPortY);

	FVector2D screenLocation = FVector2D(viewPortX * CHLocationX, viewPortY * CHLocationY);
	//UE_LOG(LogTemp, Warning, TEXT("CHLocation: %s"), *screenLocation.ToString());

	//de-project the screen projection of the crosshair to a world direction
	FVector worldDirection;
	FVector worldLocation;

	if (DeprojectScreenPositionToWorld(screenLocation.X, screenLocation.Y, worldLocation, worldDirection)) {
		UE_LOG(LogTemp, Warning, TEXT("worldDirection: %s"), *worldDirection.ToString());
	}


	//line-trace along that look direction, and see what we hit/with range
	return false;
}




