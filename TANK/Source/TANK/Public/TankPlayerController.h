// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank1.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank1 * GetControlledTank() const;

	virtual void BeginPlay() override;
	void AimTowardsCross();
	virtual void Tick(float DeltaTime) override;

	bool GetRayLoc(FVector&HitLocation) const;

	bool GetLook(FVector2D ScreenLocation, FVector & LookDir) const;

	UPROPERTY(EditAnywhere)
		float CorsshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
		float CorsshairYLocation = 0.33333;

	 
};
