// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Final.h"
#include "GameFramework/Character.h"
#include "FinalCharacter.generated.h"

UCLASS()
class AFinalCharacter : public ACharacter
{
	GENERATED_BODY()
	
public:
	// Sets default values for this character's properties
	AFinalCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent * PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent * SpringArm;

	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent * Camera;

private:
	void UpDown(float NewAxisValue);
	void LeftRight(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void Turn(float NewAxisValue);
};

