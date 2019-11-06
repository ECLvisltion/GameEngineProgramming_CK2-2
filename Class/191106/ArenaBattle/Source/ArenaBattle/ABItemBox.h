// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ArenaBattle.h"
#include "GameFramework/Actor.h"
#include "ABItemBox.generated.h"

UCLASS()
class ARENABATTLE_API AABItemBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AABItemBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(VisibleAnywhere, Category = Box)
	UBoxComponent* Trigger;

	UPROPERTY(VisibleAnywhere, Category = Box)
	UStaticMeshComponent* Box;
};
