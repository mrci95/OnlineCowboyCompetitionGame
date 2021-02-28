// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CowboyPlayerState.generated.h"

class UTextureRenderTarget2D;

UCLASS()
class ONLINECOWBOYGAME_API ACowboyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ACowboyPlayerState();

	virtual void PostInitializeComponents() override;

protected:

	//Network related

	UPROPERTY(ReplicatedUsing = OnRep_RoundsWon)
	uint16 RoundsWon;

	UPROPERTY(Replicated)
	bool Winner = false;

	UFUNCTION()
	void OnRep_RoundsWon();

	virtual void CopyProperties(APlayerState* PlayerState) override;

public:
	void RoundWin();

	uint16 GetRoundsWon() { return RoundsWon; };

	void SetWinner(bool bWinner);
};
