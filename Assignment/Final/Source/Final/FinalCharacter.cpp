// Fill out your copyright notice in the Description page of Project Settings.

#include "FinalCharacter.h"
#include "FinalAIController.h"

// Sets default values
AFinalCharacter::AFinalCharacter()
{
	// Set this character to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -88.0f), FRotator(0.0f, -90.0f, 0.0f));
	SpringArm->TargetArmLength = 400.0f;
	SpringArm->SetRelativeRotation(FRotator(-15.0f, 0.0f, 0.0f));
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = true;
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SK_STANDARD(TEXT("/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Standard.SK_CharM_Standard"));
	if (SK_STANDARD.Succeeded()) { GetMesh()->SetSkeletalMesh(SK_STANDARD.Object); }
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

	static ConstructorHelpers::FClassFinder<UAnimInstance> STANDARD_ANIM(TEXT("/Game/Book/Animations/FinalAnimBlueprint.FinalAnimBlueprint_C"));
	if (STANDARD_ANIM.Succeeded()) { GetMesh()->SetAnimInstanceClass(STANDARD_ANIM.Class); }

	AIControllerClass = AFinalAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}

// Called when the game starts or when spawned
void AFinalCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFinalCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AFinalCharacter::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AFinalCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AFinalCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AFinalCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AFinalCharacter::Turn);
}

void AFinalCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::X), NewAxisValue);
}

void AFinalCharacter::LeftRight(float NewAxisValue)
{
	AddMovementInput(FRotationMatrix(GetControlRotation()).GetUnitAxis(EAxis::Y), NewAxisValue);
}

void AFinalCharacter::LookUp(float NewAxisValue)
{
	AddControllerPitchInput(NewAxisValue);
}
void AFinalCharacter::Turn(float NewAxisValue)
{
	AddControllerYawInput(NewAxisValue);
}
