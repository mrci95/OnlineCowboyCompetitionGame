// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CowboyPlayerState.generated.h"



UCLASS()
class ONLINECOWBOYGAME_API ACowboyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ACowboyPlayerState();

protected:

	UPROPERTY(ReplicatedUsing = OnRep_RoundsWon)
	uint16 RoundsWon;

	UFUNCTION()
	void OnRep_RoundsWon();

	virtual void PostInitializeComponents() override;


public:
	void RoundWin();

	

	uint16 GetRoundsWon() { return RoundsWon; };
};
