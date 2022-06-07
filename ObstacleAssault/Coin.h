// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyCharacter.h"
#include "Coin.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ACoin : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoin();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
		class USphereComponent* Collision;

	UPROPERTY(EditAnywhere)
		class UStaticMeshComponent* MeshCoin;

	UPROPERTY(EditAnywhere)
		class UAudioComponent* PickUpSound;

	UPROPERTY(EditAnywhere)
	float SphereRadius = 32.f;

	UFUNCTION()
		void PickCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSeep, const FHitResult& SweepResult);

private:

	UPROPERTY(EditAnywhere)
		FRotator Velocity;
};
