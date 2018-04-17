// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank1.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
		 {
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"));
		}
	else
		 {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName()));
		}
}

ATank1* ATankAIController::GetControlledTank() const
{
	return Cast<ATank1>(GetPawn());
}


