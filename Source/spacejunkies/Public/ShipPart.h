// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ship.h"
#include "ShipPart.generated.h"

UCLASS()
class SPACEJUNKIES_API AShipPart : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
  AShipPart();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  bool m_bActive;
	
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
  AShip* ParentShip;
  UFUNCTION(BlueprintCallable)
    void ActivatePart(bool bActivate);


};
