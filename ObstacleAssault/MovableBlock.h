// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovableBlock.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovableBlock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovableBlock();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Respawn();

private:

	UPROPERTY(EditDefaultsOnly)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, Category = "Respawn Infos")
		FVector RespawnVector;

	UPROPERTY()
		AMovableBlock* MB;
	UPROPERTY(EditAnywhere)
		TSubclassOf<AMovableBlock> MBClass;
};
