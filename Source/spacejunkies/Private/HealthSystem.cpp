// Fill out your copyright notice in the Description page of Project Settings.

#include "HealthSystem.h"


// Sets default values for this component's properties
UHealthSystem::UHealthSystem()
{
  // Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
  // off to improve performance if you don't need them.
  PrimaryComponentTick.bCanEverTick = true;

  // ...
}


// Called when the game starts
void UHealthSystem::BeginPlay()
{
  Super::BeginPlay();

  // ...

}


// Called every frame
void UHealthSystem::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
  Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
  isImmune(DeltaTime);
  isDead();
  UpdatePercentages();
  // ...
}

bool UHealthSystem::isDead()
{
  if (m_fHealth <= 0)
  {
    m_bDead = true;
  }
  else
  {
    m_bDead = false;
  }
  return m_bDead;
}

bool UHealthSystem::isImmune(float fDeltaTime)
{
  if (m_bImmune)
  {
    m_fImmuneTime_Current += fDeltaTime;
    if (m_fImmuneTime_Current >= m_fImmuneTime)
    {
      m_bImmune = false;
      m_fImmuneTime_Current = 0.0f;
    }
  }
  else
  {
    m_fImmuneTime_Current = 0.0f;
  }
  return m_bImmune;
}

void UHealthSystem::Damage(float fDamage, FHitResult HitResult)
{
  if (!m_bImmune && fDamage > 0.0f)
  {
    if (m_fShield > 0)
    {
      if (m_fShield < fDamage)
      {
        m_fShield = 0;
        Damage(fDamage - m_fShield, HitResult);
      }
      else
      {
        m_fShield -= fDamage;
      }
    }
    else if (m_fArmor > 0)
    {
      if (m_fArmor < fDamage)
      {
        m_fArmor = 0;
        Damage(fDamage - m_fArmor, HitResult);
      }
      else
      {
        m_fArmor -= fDamage;
      }
    }
    else
    {
      m_fHealth -= fDamage;
    }
    m_bImmune = true;
    m_HitResult_Last = HitResult;
  }
}
void UHealthSystem::UpdatePercentages()
{
  if (m_fHealth_Max != 0.0f)
  {
    m_fHealth_Percent = m_fHealth / m_fHealth_Max;
  }
  else
  {
    m_fHealth_Percent = 0.0f;
  }

  if (m_fArmor_Max != 0.0f)
  {
    m_fArmor_Percent = m_fArmor / m_fArmor_Max;
  }
  else
  {
    m_fArmor_Percent = 0.0f;
  }

  if (m_fShield_Max != 0.0f)
  {
    m_fShield_Percent = m_fShield / m_fShield_Max;
  }
  else
  {
    m_fShield_Percent = 0.0f;
  }
}