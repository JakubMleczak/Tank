// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComp.h"


// Sets default values for this component's properties
UTankAimComp::UTankAimComp()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

void UTankAimComp::AimAt(FVector HitLocation)
{
	auto OURTANK =GetOwner()->GetName();

	UE_LOG(LogTemp, Warning, TEXT("%s aiming at %s"), *OURTANK, *HitLocation.ToString());

}


