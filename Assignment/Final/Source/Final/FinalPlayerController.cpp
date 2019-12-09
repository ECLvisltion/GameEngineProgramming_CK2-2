// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalPlayerController.h"

AFinalPlayerController::AFinalPlayerController()
{
	InputYawScale = 2.5f;
	InputPitchScale = -1.75f;
	InputRollScale = 2.5f;
}

void AFinalPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AFinalPlayerController::OnPossess(APawn * aPawn)
{
	Super::OnPossess(aPawn);
}

void AFinalPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}
