// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/STWeaponComponent.h"
#include "Weapon/STWeaponBase.h"
#include "GameFramework/Character.h"


USTWeaponComponent::USTWeaponComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

}

void USTWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnWeapon();

}

void USTWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void USTWeaponComponent::StartFire()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StartFire();

}

void USTWeaponComponent::StopFire()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->StopFire();

}

bool USTWeaponComponent::GetWeaponAmmoData(FAmmoData& AmmoData) const
{
	if (CurrentWeapon)
	{
		AmmoData = CurrentWeapon->GetAmmoData();
		return true;
	}
	return false;
}


void USTWeaponComponent::SpawnWeapon()
{
	if (!GetWorld()) return;

	ACharacter* Character = Cast<ACharacter>(GetOwner());
	if (!Character) return;

	CurrentWeapon = GetWorld()->SpawnActor<ASTWeaponBase>(WeaponClass);
	if (!CurrentWeapon) return;
	{
		
		FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, false);
		CurrentWeapon->AttachToComponent(Character->GetMesh(), AttachmentRules, WeaponAttachPointName);
		CurrentWeapon->SetOwner(Character);
	}

}

