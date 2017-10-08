// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "ShipPart.h"
#include "ShipPartData.generated.h"


USTRUCT(BlueprintType)
struct SPACEJUNKIES_API FShipPartData : public FTableRowBase
{
  GENERATED_BODY()
public:
  
  FShipPartData()
  {}

  //The Item ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    int32 ItemID;

  //The Blueprint for this part
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = ShipPart)
  FString BlueprintName;
  
};