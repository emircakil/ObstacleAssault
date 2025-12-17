// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

float AMovingPlatform::GetDistanceMoved() {

	return FVector::Dist(startLocation, GetActorLocation());
}
void AMovingPlatform::MovePlatform(float DeltaTime) {

	

	distanceMoved = GetDistanceMoved();

	if (distanceMoved >= movedDistance) {
		
	
		FVector moveDirection = platformVelocity.GetSafeNormal();
		FVector newStartLocation = startLocation + moveDirection * movedDistance;
		SetActorLocation(newStartLocation);
		startLocation = newStartLocation;

		platformVelocity = -platformVelocity;
		
	}
	else {
	
		FVector currentLocation = GetActorLocation();
		currentLocation = currentLocation + (platformVelocity * DeltaTime);
		SetActorLocation(currentLocation);
	}

	

}

void AMovingPlatform::RotatePlatform(float DeltaTime) {
	// This function rotating the game object in time

	FRotator rotationToAdd = rotationVelocity * DeltaTime;
	AddActorLocalRotation(rotationToAdd);

}

