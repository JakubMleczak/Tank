// Fill out your copyright notice in the Description page of Project Settings.
#include "Tank1.h"
#include "TankAimComp.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"



// Sets default values for this component's properties
UTankAimComp::UTankAimComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimComp::SetBarrelReference(UStaticMeshComponent* BarrelToSet)
{
	Barrel = BarrelToSet;
}


void UTankAimComp::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	bool bHavesol = UGameplayStatics::SuggestProjectileVelocity
		(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
		);
	if (bHavesol)
	{
	auto AimDir = OutLaunchVelocity.GetSafeNormal();
	MoveBarrelTowards(AimDir);
	}

}

	void UTankAimComp::MoveBarrelTowards(FVector AimDir)
	{
		auto BarrelRotation = Barrel->GetForwardVector().Rotation();
		auto AimAsRotator = AimDir.Rotation();
		auto DeltaRotator = AimAsRotator - BarrelRotation;
		
		
	}
	

