// Fill out your copyright notice in the Description page of Project Settings.

#include "FinalBall.h"

// Sets default values
AFinalBall::AFinalBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Light = CreateDefaultSubobject<UPointLightComponent>(TEXT("LIGHT"));

	RootComponent = Body;
	Light->SetupAttachment(Body);

	Body->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Light->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		SM_BODY(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (SM_BODY.Succeeded())
		Body->SetStaticMesh(SM_BODY.Object);

	//Material'/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean'
	static ConstructorHelpers::FObjectFinder<UMaterial> M_BODY(TEXT("/Game/StarterContent/Materials/M_Water_Ocean.M_Water_Ocean"));
	if (M_BODY.Succeeded())
		Body->SetMaterial(0, M_BODY.Object);

	Body->SetSimulatePhysics(true);
	Body->SetMassOverrideInKg(NAME_None, 10.0f, true);
}

// Called when the game starts or when spawned
void AFinalBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFinalBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

