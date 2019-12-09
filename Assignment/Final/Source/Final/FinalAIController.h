// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Final.h"
#include "AIController.h"
#include "FinalAIController.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API AFinalAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AFinalAIController();
	virtual void OnPossess(APawn * InPawn) override;
	virtual void OnUnPossess() override;

private:
	UPROPERTY()
	class UBehaviorTree * BTAsset;

	UPROPERTY()
	class UBlackboardData * BBAsset;
};
