// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STWeaponComponent.generated.h"

class ASTWeaponBase;
struct FAmmoData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class SHOOTERTEST_API USTWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	USTWeaponComponent();

	void StartFire();
	void StopFire();

	bool GetWeaponAmmoData(FAmmoData& AmmoData) const;
	
protected:
	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	FName WeaponAttachPointName = "WeaponSocket";

	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditDefaultsOnly, Category = "Weapon")
	TSubclassOf<ASTWeaponBase>WeaponClass; 

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY()
	ASTWeaponBase* CurrentWeapon = nullptr;

	void SpawnWeapon();

};
