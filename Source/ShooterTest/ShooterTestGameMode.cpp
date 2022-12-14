// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShooterTestGameMode.h"
#include "ShooterTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "UI/STGameHUD.h"
#include "STPlayerController.h"

AShooterTestGameMode::AShooterTestGameMode()
{
	HUDClass = ASTGameHUD::StaticClass();
	PlayerControllerClass = ASTPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		
	}

}
