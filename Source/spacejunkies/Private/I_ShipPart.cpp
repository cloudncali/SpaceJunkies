// Fill out your copyright notice in the Description page of Project Settings.

#include "I_ShipPart.h"


// Sets default values
AI_ShipPart::AI_ShipPart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AI_ShipPart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AI_ShipPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

