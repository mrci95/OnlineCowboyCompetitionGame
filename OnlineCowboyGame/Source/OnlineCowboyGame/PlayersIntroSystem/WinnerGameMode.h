// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "WinnerGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AWinnerGameMode : public AGameMode
{
	GENERATED_BODY()

public:

	void GenericPlayerInitialization(AController* NewPlayer) override;

	void Logout(AController* Exiting) override;

	void RequestTravelToLobby();

private:

	uint8 NoOfCurrentPlayers = 0;

	TArray<class APlayerController*> ConnectedPlayers;

	FTimerHandle DelayTimer;

	void PresentWinner();
	void BackToLobby();
};
