// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Final.h"
#include "GameFramework/GameModeBase.h"
#include "FinalGameMode.generated.h"

UCLASS()
class AFinalGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFinalGameMode();

	virtual void PostLogin(APlayerController * NewPlayer) override;
};
