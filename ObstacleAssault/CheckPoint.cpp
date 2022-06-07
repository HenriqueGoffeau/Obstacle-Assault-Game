// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckPoint.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.h"
#include "Particles/ParticleSystem.h"

// Sets default values
ACheckPoint::ACheckPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = BoxCollision;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ACheckPoint::CheckPointCollision);
}

// Called when the game starts or when spawned
void ACheckPoint::BeginPlay()
{
	Super::BeginPlay();
	
	CheckPointRespawnLocation = BoxCollision->GetComponentLocation();
}

// Called every frame
void ACheckPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACheckPoint::CheckPointCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSeep, const FHitResult& SweepResult)
{
	FVector ParticleLocation = BoxCollision->GetComponentLocation();


	AMyCharacter* Char = Cast<AMyCharacter>(OtherActor);
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor == Char))
	{
		Char->HasCheckpoint = true;
		Char->NewSpawnLocation = CheckPointRespawnLocation;

		if (CheckPointParticle && CheckPointSound && (HasActivated == false))
		{
			UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), CheckPointParticle, ParticleLocation);
			UGameplayStatics::SpawnSoundAtLocation(GetWorld(), CheckPointSound, ParticleLocation);
			HasActivated = true;
		}
	}
}

