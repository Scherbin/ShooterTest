// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/STPlayerHUDWidget.h"
#include "STWeaponComponent.h"

bool USTPlayerHUDWidget:: GetWeaponAmmoData(FAmmoData& AmmoData) const
{
	const auto Player = GetOwningPlayerPawn();
	if (!Player) return false;

	const auto Component = Player->GetComponentByClass(USTWeaponComponent::StaticClass());
	const auto WeaponComponent = Cast<USTWeaponComponent>(Component);
	if (!WeaponComponent) return false;

	return WeaponComponent->GetWeaponAmmoData(AmmoData);
}