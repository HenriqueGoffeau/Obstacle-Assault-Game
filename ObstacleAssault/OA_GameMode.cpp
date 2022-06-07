// Fill out your copyright notice in the Description page of Project Settings.


#include "OA_GameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Coin.h"
#include "MyCharacter.h"

void AOA_GameMode::BeginPlay()
{
	Super::BeginPlay();

}

int32 AOA_GameMode::GetCoinAmount()
{
	TArray<AActor*>Coins;
	UGameplayStatics::GetAllActorsOfClass(this, ACoin::StaticClass(), Coins);

	CoinsWorld = Coins.Num();
	return Coins.Num();
}

bool AOA_GameMode::LevelComplete()
{
	bool Win = false;

	if (CoinsWorld == 0)
	{
		Win = true;
	}

	return Win;
}
