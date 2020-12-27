// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "LobbyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ALobbyGameMode : public AGameModeBase
{
	GENERATED_BODY()
	

public:

	void PostLogin(APlayerController* NewPlayer) override;

	void Logout(AController* Exiting) override;

	void PlayerReady();

	void PlayerNotReady();

	void MessageReceived(FString Message, class ALobbyPlayerController* Sender);

private:

	TArray<class ALobbyPlayerController*> ConnectedPlayers;

	uint32 NoOfCurrentPlayers = 0;

	FTimerHandle DelayTimer;
	FTimerHandle StartSessionTimer;

	void StartSession();

	void UpdatePlayersList();

	bool CheckIfAllPlayersReady();

};
