// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CheckPoint.generated.h"

UCLASS()
class OBSTACLEASSAULT_API ACheckPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FVector CheckPointRespawnLocation;

private:

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BaseMesh;

	UPROPERTY(EditAnywhere)
		class UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere)
		UParticleSystem* CheckPointParticle;

	UPROPERTY(EditAnywhere)
		USoundBase* CheckPointSound;

	//bool to prevent triggering more than sound/particle
	bool HasActivated = false;

	UFUNCTION()
		void CheckPointCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSeep, const FHitResult& SweepResult);
};

