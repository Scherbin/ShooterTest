
#include "Weapon/STWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"



ASTWeaponBase::ASTWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
	CurrentAmmo = DefaultAmmo;
}

void ASTWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	check(WeaponMesh);

	
}

void ASTWeaponBase::MakeShot()
{
	
}

APlayerController* ASTWeaponBase::GetPlayerController() const
{
	const auto Player = Cast<ACharacter>(GetOwner());
	if (!Player) return nullptr;

	return Player->GetController<APlayerController>();
	
}

bool ASTWeaponBase::GetPlayerViewPoint(FVector& ViewLocation, FRotator& ViewRotation) const
{
	const auto Controller = GetPlayerController();
	if (!Controller) return false;

	Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
	return true;
}

FVector ASTWeaponBase::GetMuzzleWorldLocation() const
{
	return WeaponMesh->GetSocketLocation(MuzzleSocketName);
}

bool ASTWeaponBase::GetTraceData(FVector& TraceStart, FVector& TraceEnd) const
{
	FVector ViewLocation;
	FRotator ViewRotation;
	if(!GetPlayerViewPoint(ViewLocation, ViewRotation)) return false;

	TraceStart = ViewLocation;
	const FVector ShootDirection = ViewRotation.Vector();
	TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
	return true;

}

void ASTWeaponBase::MakeHit(FHitResult& HitResult, const FVector& TraceStart, const FVector& TraceEnd)
{
	if (!GetWorld()) return;

	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredActor(GetOwner());
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
}

void ASTWeaponBase::StartFire()
{
	
}

void ASTWeaponBase::StopFire()
{
	
}

void ASTWeaponBase::DecreaseAmmo()
{
	if (CurrentAmmo.Bullets == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Clips is Empty"));
		return;
	}

	CurrentAmmo.Bullets--;

}

bool ASTWeaponBase::IsAmmoEmpty() const
{
	return !CurrentAmmo.Infinite && CurrentAmmo.Clips && IsClipEmpty();
}

bool ASTWeaponBase::IsClipEmpty() const
{
	return CurrentAmmo.Bullets == 0;
}

void ASTWeaponBase::ChangeClip()
{
	UE_LOG(LogTemp, Error, TEXT("ChangeClip %i"), CurrentAmmo.Bullets);

	if (!CurrentAmmo.Infinite)
	{

		if (CurrentAmmo.Clips == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("No more clips"));
			return;
		}
		CurrentAmmo.Clips--;
	}
	CurrentAmmo.Bullets = DefaultAmmo.Bullets;
}


