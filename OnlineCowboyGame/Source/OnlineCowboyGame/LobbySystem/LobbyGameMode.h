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

	void GenericPlayerInitialization(AController* NewPlayer) override;

	void Logout(AController* Exiting) override;

	void ClientInitialized();

	void PlayerReady();

	void PlayerNotReady();

	void MessageReceived(FString Message, class ALobbyPlayerController* Sender);

	UFUNCTION(BlueprintCallable)
	int GetNumberOfConnectedPlayers() { return ConnectedPlayers.Num(); };

private:

	TArray<class ALobbyPlayerController*> ConnectedPlayers;

	uint32 NoOfCurrentPlayers = 0;
	bool GameStarted = false;

	FTimerHandle DelayTimer;
	FTimerHandle SessionStartTimer;

	void StartingSessionTimer();

	void StartSession();

	void UpdatePlayersList();

	bool CheckIfAllPlayersReady();

};
