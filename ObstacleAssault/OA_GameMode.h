// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OA_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class OBSTACLEASSAULT_API AOA_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	class ACoin* Coin;
	class AMyCharacter* Char;

public:

	UPROPERTY(EditAnywhere)
	int32 CoinsWorld;

	UFUNCTION(BlueprintPure)
	int32 GetCoinAmount();

	UFUNCTION(BlueprintPure)
	bool LevelComplete();
};
