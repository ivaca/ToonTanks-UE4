// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ToonTanks/Controllers/PlayerControllerBase.h"
#include "TankGameModeBase.generated.h"

class APawnTank;
/**
 * 
 */
UCLASS()
class TOONTANKS_API ATankGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

	APawnTank* PlayerTank;
	int32 TargetTurrets = 0;
	APlayerControllerBase*  PlayerControllerRef;

	void HandleGameStart();
	void HandleGameOver(bool PlayerWon);


public:
	void ActorDied(AActor* DeadActor);
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Game Loop")
	int32 StartDelay;

	virtual void BeginPlay() override;
	UFUNCTION(BlueprintImplementableEvent)
	void GameStart();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);
};
