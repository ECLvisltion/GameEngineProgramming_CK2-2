// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "FinalGameMode.h"
#include "FinalCharacter.h"
#include "FinalPlayerController.h"

AFinalGameMode::AFinalGameMode()
{
	DefaultPawnClass = AFinalCharacter::StaticClass();
	PlayerControllerClass = AFinalPlayerController::StaticClass();
}

void AFinalGameMode::PostLogin(APlayerController * NewPlayer)
{
	Super::PostLogin(NewPlayer);
}
