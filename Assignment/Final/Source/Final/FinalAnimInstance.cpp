// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalAnimInstance.h"

UFinalAnimInstance::UFinalAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
}

void UFinalAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
	}
}
