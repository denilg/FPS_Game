// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "FPS_Game.h"
#include "FPS_GameGameMode.h"
#include "FPS_GameHUD.h"
#include "FPS_GameCharacter.h"

AFPS_GameGameMode::AFPS_GameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AFPS_GameHUD::StaticClass();
}
