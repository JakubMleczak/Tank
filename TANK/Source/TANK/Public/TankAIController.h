// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Tank1.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

	ATank1 * GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


	ATank1* GetPlayerTank() const;
};
