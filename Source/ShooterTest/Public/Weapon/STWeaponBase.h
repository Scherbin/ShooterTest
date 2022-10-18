// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STWeaponBase.generated.h"

class USkeletalMeshComponent;

UCLASS()
class SHOOTERTEST_API ASTWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASTWeaponBase();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
		USkeletalMeshComponent* WeaponMesh;

	virtual void BeginPlay() override;



};
