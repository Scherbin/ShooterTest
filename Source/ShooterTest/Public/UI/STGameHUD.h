// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "STWeaponBase.h"
#include "STGameHUD.generated.h"


UCLASS()
class SHOOTERTEST_API ASTGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	
protected:

private:
	//void DrawCrossHair();

};
