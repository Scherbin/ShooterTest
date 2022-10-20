// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "STWeaponComponent.h"
#include "STWeaponBase.h"
#include "STPlayerHUDWidget.generated.h"

UCLASS()
class SHOOTERTEST_API USTPlayerHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "UI")
	bool GetWeaponAmmoData(FAmmoData& AmmoData) const;
};
