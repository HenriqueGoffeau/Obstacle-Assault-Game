// Fill out your copyright notice in the Description page of Project Settings.


#include "RespawnBox.h"
#include "Components/BoxComponent.h"
#include "MyCharacter.h"
#include "MovableBlock.h"

// Sets default values
ARespawnBox::ARespawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Collision"));
	BoxCollision->SetCollisionProfileName("Trigger");
	RootComponent = BoxCollision;

	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ARespawnBox::RespawnCollision);
}

// Called when the game starts or when spawned
void ARespawnBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARespawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARespawnBox::RespawnCollision(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMyCharacter* MyChar = Cast<AMyCharacter>(OtherActor);
	AMovableBlock* MB = Cast<AMovableBlock>(OtherActor);

	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (OtherActor == MyChar)
		{
			MyChar->RespawnPlayer();
		}
		else if (OtherActor == MB)
		{
			MB->Respawn();
		}
	}
}

