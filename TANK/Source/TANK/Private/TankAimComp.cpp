// Fill out your copyright notice in the Description page of Project Settings.
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimComp.h"


// Sets default values for this component's properties
UTankAimComp::UTankAimComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimComp::SetBarrelReference(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Called when the game starts
void UTankAimComp::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComp::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
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
	 MoveBarrel();
	}

	void UStaticMeshComponent*MoveBarrel();
	
}


