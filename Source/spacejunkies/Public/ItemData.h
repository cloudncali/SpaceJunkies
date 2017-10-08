// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "ItemData.generated.h"
/**
 * 
 */
 /** Structure that defines a level up table entry */


USTRUCT(BlueprintType)
struct SPACEJUNKIES_API FItemData : public FTableRowBase
{
  GENERATED_BODY()
public:
  UENUM()
    enum E_PartTypes
  {
    PT_NONE = 0,
    PT_RESOURCE,
    PT_AMMO,
    PT_WEAPON,
    PT_SPECIAL,
    PT_PASSIVE3
  };
  FItemData()
  {}

  //The ID
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MetaData)
    int32 ItemID;

  //Display Name of the item
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInfo)
    FString ItemName;

  //The type of item
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = MetaData)
    int32 ItemType;

  //Ingame description
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = DisplayInfo)
    FString ItemDescription;
};