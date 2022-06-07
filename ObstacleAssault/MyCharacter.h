// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);
	void LookUp(float AxisValue);
	void LookRight(float AxisValue);

	//void Grab() was made in the Grabber C++


	void GetCoin();

	UPROPERTY(EditAnywhere)
	int32 PlayerCoinAmount;

	UFUNCTION(BlueprintPure)
	int32 HudCoin() const;


	void RespawnPlayer();

	//CheckpointSystem
	bool HasCheckpoint = false;
	class ACheckPoint* CheckPoint;
	FVector NewSpawnLocation;

private:

	//Player StartLocation
	FVector StartSpawn;
};
