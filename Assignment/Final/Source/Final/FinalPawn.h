// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Final.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "FinalPawn.generated.h"

UCLASS()
class FINAL_API AFinalPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFinalPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void PostInitializeComponents() override;
	virtual void PossessedBy(AController* NewController) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = Collision)
	UCapsuleComponent * Capsule;
	UPROPERTY(VisibleAnywhere, Category = Visual)
	USkeletalMeshComponent * Mesh;
	UPROPERTY(VisibleAnywhere, Category = Movement)
	UFloatingPawnMovement * Movement;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	USpringArmComponent * SpringArm;
	UPROPERTY(VisibleAnywhere, Category = Camera)
	UCameraComponent * Camera;
};
