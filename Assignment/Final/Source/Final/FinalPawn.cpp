// Fill out your copyright notice in the Description page of Project Settings.


#include "FinalPawn.h"

// Sets default values
AFinalPawn::AFinalPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CAPSULE"));
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MESH"));
	Movement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MOVEMENT"));
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	RootComponent = Capsule;
	Mesh->SetupAttachment(Capsule);
	SpringArm->SetupAttachment(Capsule);
	Camera->SetupAttachment(SpringArm);

	Capsule->SetCapsuleHalfHeight(88.0f);
	Capsule->SetCapsuleRadius(34.0f);
	Mesh->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));

	Movement->MaxSpeed = 2400.f;
	SpringArm->bEnableCameraLag = true;

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_STANDARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Standard.SK_CharM_Standard"));
	if (SK_STANDARD.Succeeded())
	{
		Mesh->SetSkeletalMesh(SK_STANDARD.Object);
	}

	Mesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> FINAL_ANIM(TEXT("/Game/Book/Animations/FinalAnimBlueprint.FinalAnimBlueprint_C"));
	if (FINAL_ANIM.Succeeded()) { Mesh->SetAnimInstanceClass(FINAL_ANIM.Class); }
}

// Called when the game starts or when spawned
void AFinalPawn::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFinalPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFinalPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AFinalPawn::PossessedBy(AController * NewController)
{
	Super::PossessedBy(NewController);
}

// Called to bind functionality to input
void AFinalPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AFinalPawn::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AFinalPawn::LeftRight);
}

void AFinalPawn::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}

void AFinalPawn::LeftRight(float NewAxisValue)
{
	AddMovementInput(GetActorRightVector(), NewAxisValue);
}

