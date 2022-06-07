// Fill out your copyright notice in the Description page of Project Settings.


#include "Coin.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "OA_GameMode.h"

// Sets default values
ACoin::ACoin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collision"));
	Collision->InitSphereRadius(SphereRadius);
	Collision->SetCollisionProfileName("Trigger");
	RootComponent = Collision;

	MeshCoin = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Coin"));
	MeshCoin->SetupAttachment(RootComponent);

	PickUpSound = CreateDefaultSubobject<UAudioComponent>(TEXT("PickUp Sound"));
	PickUpSound->bAutoActivate = false;
	PickUpSound->SetupAttachment(RootComponent);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &ACoin::PickCollision);
}

// Called when the game starts or when spawned
void ACoin::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Rotate Coin
	FRotator CurrentRotation = GetActorRotation();
	CurrentRotation += Velocity * DeltaTime;
	SetActorRotation(CurrentRotation);
}

void ACoin::PickCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSeep, const FHitResult& SweepResult)
{
	AMyCharacter* Char = Cast<AMyCharacter>(OtherActor);
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && (OtherActor == Char))
	{
		PickUpSound->Activate(true);
		PickUpSound->bStopWhenOwnerDestroyed = false;
		PickUpSound->Play(0.0f);
		Destroy();

		Char->GetCoin();
	}
}

