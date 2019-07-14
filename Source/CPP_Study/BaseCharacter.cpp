// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"





// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// Set size for collision capsule (Not in use)
	// GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxAcceleration = 4098;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Set Sprint Value
	// SprintSpeed = 800.0f;
	// BaseSpeed = 400.0f;

	//Set Status Value
	// MaxHealth = 100.0f;
	// CurrentHealth = 100.0f;
	// Damage = 10.0f;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &ABaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABaseCharacter::MoveRight);
	// Set up "look" bindngs
	PlayerInputComponent->BindAxis("Turn", this, &ABaseCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &ABaseCharacter::AddControllerPitchInput);
	// Set up Sprint
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ABaseCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ABaseCharacter::StopSprint);
	// Set up Skill
	PlayerInputComponent->BindAction("Skill1", IE_Pressed, this, &ABaseCharacter::Skill1);
	PlayerInputComponent->BindAction("Skill2", IE_Pressed, this, &ABaseCharacter::Skill2);
	PlayerInputComponent->BindAction("Skill3", IE_Pressed, this, &ABaseCharacter::Skill3);
	PlayerInputComponent->BindAction("Skill4", IE_Pressed, this, &ABaseCharacter::Skill4);
	// Set up BaseAttack
	PlayerInputComponent->BindAction("BaseAttack", IE_Pressed, this, &ABaseCharacter::BaseAttack);
}

void ABaseCharacter::MoveForward(float Value)
{
	if (EnableMovement == true)
	{
		// Find out which way is "forward" and record that the player wants to move that way.
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
	
	{
		// Block Input
	}
}

void ABaseCharacter::MoveRight(float Value)
{
	if (EnableMovement == true)
	{
		// Find out which way is "right" and record that the player wants to move that way.
		FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}

	
}

void ABaseCharacter::Sprint()
{
	// Start Sprint
	GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

}

void ABaseCharacter::StopSprint()
{
	// Stop Sprint
	GetCharacterMovement()->MaxWalkSpeed = BaseSpeed;
}

// Skill Functions



void ABaseCharacter::Skill1_Implementation()
{
	// Override on BP
}

void ABaseCharacter::Skill2_Implementation()
{
	// Override on BP
}

void ABaseCharacter::Skill3_Implementation()
{
	// Override on BP
}

void ABaseCharacter::Skill4_Implementation()
{
	// Override on BP
}

void ABaseCharacter::BaseAttack_Implementation()
{
	// Override on BP
}

void ABaseCharacter::SlowCharacter(float SpeedDivide)
{
	BaseSpeed = BaseSpeed / SpeedDivide;
}


void ABaseCharacter::SpeedCharacter(float SpeedDivide)
{
	BaseSpeed = BaseSpeed * SpeedDivide;
}
