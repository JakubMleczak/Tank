// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank1.h"
#include "TankPlayerController.h"



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCross();

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
		return;
	}

	FVector HitLocation;
	if (GetRayLoc(HitLocation))
	{
		//UE_LOG(LogTemp, Warning, TEXT("HitLoaction: %s"), *HitLocation.ToString());
	}
}
bool ATankPlayerController::GetRayLoc(FVector& HitLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CorsshairXLocation, ViewportSizeY * CorsshairYLocation);

	FVector LookDir;
	if (GetLook(ScreenLocation, LookDir))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look: %s"), *LookDir.ToString());
	}
	return true;
}

bool ATankPlayerController::GetLook(FVector2D ScreenLocation, FVector& LookDir) const
{

	FVector CameraWorldLocation;
	
	 return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y, 
		CameraWorldLocation,
		LookDir);
}