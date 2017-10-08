// Fill out your copyright notice in the Description page of Project Settings.

#include "ShipPart.h"


// Sets default values
AShipPart::AShipPart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AShipPart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AShipPart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AShipPart::ActivatePart(bool bActivate)
{
  m_bActive = bActivate;
  SetActorHiddenInGame(!bActivate);
  SetActorEnableCollision(bActivate);
  SetActorTickEnabled(bActivate);

}