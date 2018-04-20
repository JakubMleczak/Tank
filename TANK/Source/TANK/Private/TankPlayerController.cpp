// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank1.h"
#include "TankPlayerController.h"



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

 }


void ATankPlayerController::BeginPlay()
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

ATank1* ATankPlayerController::GetControlledTank() const
{
return Cast<ATank1>(GetPawn());
}

void ATankPlayerController::AimTowardsCross()
{
	if (!GetControlledTank())
	{
		return nullptr;
	}

}