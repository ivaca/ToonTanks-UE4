// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.h"
#include "PawnTurret.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API APawnTurret : public APawnBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRate = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat", meta=(AllowPrivateAccess="true"))
	float FireRange = 150.0f;

	void CheckFireCondition();
	float GetDistanceToPlayer();


	FTimerHandle FireRateTimerHandle;
	APawnTank* PlayerPawn;
public:
	APawnTurret();


	virtual void Tick(float DeltaTime) override;

	virtual void HandleDestruction() override;
protected:
	virtual void BeginPlay() override;
};
