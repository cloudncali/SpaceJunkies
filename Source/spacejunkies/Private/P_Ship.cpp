// Fill out your copyright notice in the Description page of Project Settings.

#include "P_Ship.h"


// Sets default values
AP_Ship::AP_Ship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AP_Ship::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AP_Ship::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AP_Ship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

