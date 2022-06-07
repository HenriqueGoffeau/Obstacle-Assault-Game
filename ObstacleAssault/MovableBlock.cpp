// Fill out your copyright notice in the Description page of Project Settings.


#include "MovableBlock.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AMovableBlock::AMovableBlock()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

}

// Called when the game starts or when spawned
void AMovableBlock::BeginPlay()
{
	Super::BeginPlay();
	
	RespawnVector = GetActorLocation();
}

// Called every frame
void AMovableBlock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMovableBlock::Respawn()
{
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	FRotator Rotator = GetActorRotation();

	MB = GetWorld()->SpawnActor<AMovableBlock>(MBClass, RespawnVector, Rotator, SpawnParams);
}

