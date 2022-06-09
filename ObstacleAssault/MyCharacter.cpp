// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CheckPoint.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	//make the character rotato without following the camera
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	PlayerCoinAmount = 0;

	StartSpawn = GetActorLocation();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	InputComponent->BindAxis("LookRight", this, &AMyCharacter::LookRight);
	InputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUp);

	//Using default Jump function from ACharacter
	InputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
}

void AMyCharacter::MoveForward(float AxisValue)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);
	
	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);

	AddMovementInput(Direction, AxisValue);
}

void AMyCharacter::MoveRight(float AxisValue)
{
	FRotator Rotation = Controller->GetControlRotation();
	FRotator YawRotation(0, Rotation.Yaw, 0);

	FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	AddMovementInput(Direction, AxisValue);
}

void AMyCharacter::LookUp(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMyCharacter::LookRight(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}


void AMyCharacter::GetCoin()
{
	PlayerCoinAmount += 1;
}

int32 AMyCharacter::HudCoin() const
{
	return PlayerCoinAmount;
}

void AMyCharacter::RespawnPlayer()
{
	if (HasCheckpoint == false)
	{
		SetActorLocation(StartSpawn);
	}
	else if (HasCheckpoint)
	{
		SetActorLocation(NewSpawnLocation);
	}
}


