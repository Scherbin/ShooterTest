// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon/STWeaponBase.h"
#include "STRiffleAKWeapon.generated.h"


UCLASS()
class SHOOTERTEST_API ASTRiffleAKWeapon : public ASTWeaponBase
{
	GENERATED_BODY()
	
public:
	virtual void StartFire() override;
	virtual void StopFire() override;

	

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimeBeetwenShots = 0.1f;

	virtual void MakeShot();
	virtual bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;
private:
	FTimerHandle ShotTimerHandle;
};
