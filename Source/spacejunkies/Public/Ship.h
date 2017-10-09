// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Ship.generated.h"
UCLASS()
class SPACEJUNKIES_API AShip : public APawn
{
	GENERATED_BODY()
private:
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_ForwardSpeed_Current;
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_StrafSpeed_Current;
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_ClimbSpeed_Current;
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_YawSpeed_Current;
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_PitchSpeed_Current;
  UPROPERTY(VisibleAnywhere, Category = "Motion")
  float F_RollSpeed_Current;
  

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_MinSpeed;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_MaxSpeed;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_Acceleration;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_TurnSpeed;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_RollSpeed;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealth;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealthMax;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealthPercent;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fArmor;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fArmorMax;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fArmorPercent;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fShield;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fShieldMax;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    float m_fShieldPercent;

  // Sets default values for this pawn's properties
  AShip();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
  
  void TurnUp(float F_AxisValue);
  
  void TurnRight(float F_AxisValue);
  
  void Thrust(float F_AxisValue);
  
  void Straf(float F_AxisValue);
  
  void Climb(float F_AxisValue);
  UFUNCTION()
  void OnHit(UPrimitiveComponent * PrimitiveComponent1, AActor * Actor, UPrimitiveComponent * PrimitiveComponent2, FVector Vector, const FHitResult & HitResult);
	
  void UpdatePercentages();
};
