
#include "Weapon/STWeaponBase.h"
#include "Components/SkeletalMeshComponent.h"

ASTWeaponBase::ASTWeaponBase()
{
	PrimaryActorTick.bCanEverTick = false;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	SetRootComponent(WeaponMesh);
}

void ASTWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}



