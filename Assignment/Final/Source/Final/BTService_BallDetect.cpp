// Fill out your copyright notice in the Description page of Project Settings.


#include "BTService_BallDetect.h"
#include "FinalAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"
#include "FinalBall.h"

UBTService_BallDetect::UBTService_BallDetect()
{
}

void UBTService_BallDetect::TickNode(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	auto ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto Center = ControllingPawn->GetActorLocation();
	auto World = ControllingPawn->GetWorld();

	float DetectRadius = 1000.0f;
	if (nullptr == World)
	{
		return;
	}

	TArray<FOverlapResult> OverlapResults;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->OverlapMultiByChannel(
		OverlapResults,
		Center,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	if (bResult)
	{
		for (auto const& OverlapResult : OverlapResults)
		{
			auto FinalBall = Cast<AFinalBall>(OverlapResult.GetActor());
			if (FinalBall)
			{
				OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Ball")), FinalBall);
				DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Blue, false, 0.2f);
				return;
			}
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsObject(FName(TEXT("Ball")), nullptr);
	DrawDebugSphere(World, Center, DetectRadius, 16, FColor::Red, false, 0.2f);
}
