// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Bomberman_TestGameMode.h"
#include "Bomberman_TestPlayerController.h"
#include "Bomberman_TestCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABomberman_TestGameMode::ABomberman_TestGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABomberman_TestPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}