// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthSystem.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACEJUNKIES_API UHealthSystem : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthSystem();

  UFUNCTION(BlueprintCallable)
    bool isDead();
  UFUNCTION(BlueprintCallable)
    bool isImmune(float fDeltaTime);
  UFUNCTION(BlueprintCallable)
    void Damage(float fDamage, FHitResult HitResult);
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
  void UpdatePercentages();
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    bool m_bDead;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
    bool m_bImmune;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fImmuneTime;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fImmuneTime_Current;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealth;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealth_Max;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fHealth_Percent;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fArmor;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fArmor_Max;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fArmor_Percent;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fShield;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fShield_Max;
  UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fShield_Percent;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fShield_Recharge_Rate;
  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vitals")
  float m_fShield_Recharge_Delay;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Vitals")
  FHitResult m_HitResult_Last;

};
