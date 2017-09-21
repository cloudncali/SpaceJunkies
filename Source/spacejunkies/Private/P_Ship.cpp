// Fill out your copyright notice in the Description page of Project Settings.

#include "P_Ship.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AP_Ship::AP_Ship()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

  SetActorEnableCollision(true);
  F_Acceleration = 500.0f;
  F_TurnSpeed = 50.0f;
  F_RollSpeed = 100.0f;
  F_MinSpeed = -5000.0f;
  F_MaxSpeed = 5000.0f;
  F_ForwardSpeed_Current = 0.0f;
  F_ClimbSpeed_Current = 0.0f;
  F_StrafSpeed_Current = 0.0f;
  F_YawSpeed_Current = 0.0f;
  F_PitchSpeed_Current = 0.0f;
  F_RollSpeed_Current = 0.0f;

}

// Called when the game starts or when spawned
void AP_Ship::BeginPlay()
{
	Super::BeginPlay();
  TArray<UStaticMeshComponent*> comps;

  GetComponents(comps);
  for (auto StaticMeshComponent : comps)
  {
    StaticMeshComponent->OnComponentHit.AddDynamic(this, &AP_Ship::OnHit);
  }
}

// Called every frame
void AP_Ship::Tick(float DeltaTime)
{
  Super::Tick(DeltaTime);

  AddActorLocalOffset(FVector(F_ForwardSpeed_Current*DeltaTime, F_StrafSpeed_Current*DeltaTime, F_ClimbSpeed_Current*DeltaTime), true);
  AddActorLocalRotation(FRotator(F_PitchSpeed_Current*DeltaTime, F_YawSpeed_Current*DeltaTime, F_RollSpeed_Current*DeltaTime));

}

// Called to bind functionality to input
void AP_Ship::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
  InputComponent->BindAxis("TurnUp", this, &AP_Ship::TurnUp);
  InputComponent->BindAxis("TurnRight", this, &AP_Ship::TurnRight);
  InputComponent->BindAxis("Thrust", this, &AP_Ship::Thrust);
  InputComponent->BindAxis("Straf", this, &AP_Ship::Straf);
  InputComponent->BindAxis("Climb", this, &AP_Ship::Climb);
}

void AP_Ship::TurnUp(float F_AxisValue)
{
  float F_DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
  F_PitchSpeed_Current = FMath::FInterpTo(F_PitchSpeed_Current, (F_TurnSpeed*F_AxisValue) + (FMath::Abs(F_YawSpeed_Current)*-0.2f), F_DeltaTime, 2);
}
void AP_Ship::TurnRight(float F_AxisValue)
{
  float F_DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
  F_YawSpeed_Current = FMath::FInterpTo(F_YawSpeed_Current, (F_TurnSpeed*F_AxisValue), F_DeltaTime, 2);
  if (FMath::Abs(F_YawSpeed_Current) > 10.0f)
  {
    F_RollSpeed_Current = FMath::FInterpTo(F_RollSpeed_Current, (F_YawSpeed_Current*0.5f), F_DeltaTime, 2);
  }
  else
  {
    F_RollSpeed_Current = FMath::FInterpTo(F_RollSpeed_Current, GetActorRotation().Roll*-2, F_DeltaTime, 2);
  }
  
}
void AP_Ship::Thrust(float F_AxisValue)
{
  float F_DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
  if (F_AxisValue != 0.0f)
  {
    F_ForwardSpeed_Current = FMath::Clamp(F_ForwardSpeed_Current + (F_Acceleration*F_AxisValue*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
  else
  {
    F_ForwardSpeed_Current = FMath::Clamp(F_ForwardSpeed_Current + (F_Acceleration*(UKismetMathLibrary::SignOfFloat(F_ForwardSpeed_Current)*-0.5f)*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
}

void AP_Ship::Straf(float F_AxisValue)
{
  float F_DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
  if (F_AxisValue != 0.0f)
  {
    F_StrafSpeed_Current = FMath::Clamp(F_StrafSpeed_Current + (F_Acceleration*F_AxisValue*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
  else
  {
    F_StrafSpeed_Current = FMath::Clamp(F_StrafSpeed_Current + (F_Acceleration*(UKismetMathLibrary::SignOfFloat(F_StrafSpeed_Current)*-0.5f)*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
  /*
  //Strafing rolls ship slightly
  if (FMath::Abs(F_StrafSpeed_Current) > 10.0f)
  {
    F_RollSpeed_Current = FMath::FInterpTo(F_RollSpeed_Current, (F_StrafSpeed_Current*0.5f), F_DeltaTime, 2);
  }
  else
  {
    F_RollSpeed_Current = FMath::FInterpTo(F_RollSpeed_Current, GetActorRotation().Roll*-2, F_DeltaTime, 2);
  }
  */
}
void AP_Ship::Climb(float F_AxisValue)
{
  float F_DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
  if (F_AxisValue != 0.0f)
  {
    F_ClimbSpeed_Current = FMath::Clamp(F_ClimbSpeed_Current + (F_Acceleration*F_AxisValue*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
  else
  {
    F_ClimbSpeed_Current = FMath::Clamp(F_ClimbSpeed_Current + (F_Acceleration*(UKismetMathLibrary::SignOfFloat(F_ClimbSpeed_Current)*-0.5f)*F_DeltaTime), F_MinSpeed, F_MaxSpeed);
  }
}

void AP_Ship::OnHit(UPrimitiveComponent * PrimitiveComponent1, AActor * Actor, UPrimitiveComponent * PrimitiveComponent2, FVector Vector, const FHitResult & HitResult)
{
  SetActorRotation(FMath::Lerp(GetActorRotation(), UKismetMathLibrary::MakeRotationFromAxes(HitResult.Normal, FVector(), FVector()), 0.025f));
}