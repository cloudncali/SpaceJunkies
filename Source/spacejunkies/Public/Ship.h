// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HealthSystem.h"
#include "Ship.generated.h"
UCLASS()
class SPACEJUNKIES_API AShip : public APawn
{
	GENERATED_BODY()
private:

  

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_ForwardSpeed_Current;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_StrafSpeed_Current;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_ClimbSpeed_Current;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_YawSpeed_Current;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_PitchSpeed_Current;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_RollSpeed_Current;  
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_BoostTimer;
public:
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_MinSpeed;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_MaxSpeed;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_Acceleration;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_TurnSpeed;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_RollSpeed;
  //This value effects how fast the ship will automatically slow down when not told to move.
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  float F_BreakMultiplier;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
  bool B_Boost;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_BoostMultiplier;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Motion")
    float F_BoostDuration;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  UHealthSystem* HealthSystem;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  AActor* TargetActor;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  UHealthSystem* HealthSystem_Target;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
  bool B_IsAIControlled;


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

  void Boost();

  UFUNCTION()
  void OnHit(UPrimitiveComponent * PrimitiveComponent1, AActor * Actor, UPrimitiveComponent * PrimitiveComponent2, FVector Vector, const FHitResult & HitResult);
  UFUNCTION(BlueprintCallable)
  void Lookat(AActor* Target);
};
