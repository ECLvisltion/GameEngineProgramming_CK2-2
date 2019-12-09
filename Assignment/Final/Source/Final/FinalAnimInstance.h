// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Final.h"
#include "Animation/AnimInstance.h"
#include "FinalAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UFinalAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	UFinalAnimInstance();
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float CurrentPawnSpeed;
};
