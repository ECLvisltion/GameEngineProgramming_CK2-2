// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"

AFinalAIController::AFinalAIController()
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BTObject(TEXT("/Game/Book/AI/BT_FinalCharacter.BT_FinalCharacter"));
	if (BTObject.Succeeded()) { BTAsset = BTObject.Object; }

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BBObject(TEXT("/Game/Book/AI/BB_FinalCharacter.BB_FinalCharacter"));
	if (BBObject.Succeeded()) { BBAsset = BBObject.Object; }
}

void AFinalAIController::OnPossess(APawn * InPawn)
{
	Super::OnPossess(InPawn);
	if (UseBlackboard(BBAsset, Blackboard))
	{
		Blackboard->SetValueAsFloat(FName("WaitTimer"), 3.0f);
		Blackboard->SetValueAsVector(
			FName("HomePos"),
			FVector(1000.0f, 0.0f, 108.0f));
		RunBehaviorTree(BTAsset);
	}
}

void AFinalAIController::OnUnPossess()
{
	Super::OnUnPossess();
}
