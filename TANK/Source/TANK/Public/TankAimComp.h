// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimComp.generated.h"


class UTankBarrel;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANK_API UTankAimComp : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComp();

	void SetBarrelReference(UTankBarrel* BarrelToSet);


	

	void AimAt(FVector,float);
	
private:
	UTankBarrel * Barrel = nullptr;
	void MoveBarrelTowards(FVector AimDir);
	


};
