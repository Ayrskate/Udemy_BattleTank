// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	auto playerTank = GetPlayerTank();

	if (!ControlledTank) {

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT(" AI Controlled Tank11: %s"), *ControlledTank->GetName());
	}
	if (!playerTank) {

	}
	else {
		UE_LOG(LogTemp, Warning, TEXT(" player tank: %s"), *playerTank->GetName());
	}
}
