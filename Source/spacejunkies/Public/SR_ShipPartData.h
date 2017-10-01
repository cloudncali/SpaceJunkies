// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "I_ShipPart.h"
#include "SR_ShipPartData.generated.h"
/**
 * 
 */
 /** Structure that defines a level up table entry */


USTRUCT(BlueprintType)
struct SPACEJUNKIES_API FSR_ShipPartData : public FTableRowBase
{
  GENERATED_BODY()
public:
  UENUM()
    enum E_PartTypes
  {
    PT_NONE = 0,
    PT_WEAPON,
    PT_SPECIAL,
    PT_PASSIVE
  };
  FSR_ShipPartData()
  {}

  /** The 'Name' column is the same as the XP Level */

  //The ID for this entity
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    int32 I_ID;

  //Display Name of Part
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    FString S_Name;

  //The type of part
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    int32 I_Type;

  //this string defines the resource cost for this part.
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    FString S_ResourceString;

  //The ship part blueprint to spawn.
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    AShipPart* ShipPart;

  //Ingame description
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ShipPart)
    FString S_Description;

   
};