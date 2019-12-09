// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Final.h"
#include "GameFramework/PlayerController.h"
#include "FinalPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API AFinalPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFinalPlayerController();

	virtual void PostInitializeComponents() override;
	virtual void OnPossess(APawn * aPawn) override;

protected:
	virtual void BeginPlay() override;
};
