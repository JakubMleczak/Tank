// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

ATank1* ATankPlayerController::GetControlledTank() const
{
return Cast<ATank1>(GetPawn());
}
