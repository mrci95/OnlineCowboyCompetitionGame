// Fill out your copyright notice in the Description page of Project Settings.



#include "LobbyGameMode.h"
#include "../CowobyGameInstance.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerState.h"
#include "LobbyPlayerController.h"
#include "LobbyMenu.h"
#include "LobbyGameState.h"

void ALobbyGameMode::GenericPlayerInitialization(AController* NewPlayer)
{
	Super::GenericPlayerInitialization(NewPlayer);
	++NoOfCurrentPlayers;

	ALobbyPlayerController* JoiningPlayer = Cast<ALobbyPlayerController>(NewPlayer);

	//if the joining player is a lobby player controller, add him to a list of connected Players
	if (JoiningPlayer)
		ConnectedPlayers.Add(JoiningPlayer);

	GetWorldTimerManager().SetTimer(DelayTimer, this, &ALobbyGameMode::UpdatePlayersList, 0.5f);

}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	--NoOfCurrentPlayers;

	ALobbyPlayerController* LobbyPlayerController = Cast<ALobbyPlayerController>(Exiting);
	if (LobbyPlayerController)
	{
		ConnectedPlayers.Remove(LobbyPlayerController);

		GetWorldTimerManager().SetTimer(DelayTimer, this, &ALobbyGameMode::UpdatePlayersList, 0.5f);
	}

}


void ALobbyGameMode::UpdatePlayersList()
{
	//Empty the PlayersData Array to re-populate it
	TArray<FPlayerData> PlayersDataArray;

	//get all the player data from all the connected players
	for (ALobbyPlayerController* Player : ConnectedPlayers)
	{
		//temporary LobbyPlayerData var to hold the player info
		FPlayerData TempLobbyPlayerData;

		if (ALobbyPlayerState* PS = Player->GetPlayerState<ALobbyPlayerState>())
		{
			TempLobbyPlayerData.PlayerName = PS->GetPlayerName();
			TempLobbyPlayerData.bIsReady = PS->IsReady();
		}
		else
		{
			TempLobbyPlayerData.PlayerName = "N/A";
			TempLobbyPlayerData.bIsReady = false;
		}

		PlayersDataArray.Add(TempLobbyPlayerData);
	}

	//call all the players to make them update and pass in the player info array
	for (ALobbyPlayerController* Player : ConnectedPlayers)
		Player->Client_UpdatePlayerList(PlayersDataArray);
}


void ALobbyGameMode::PlayerReady()
{
	UpdatePlayersList();

	if (CheckIfAllPlayersReady())
	{
		if (ALobbyGameState* GS = GetGameState<ALobbyGameState>())
		{
			GameStarted = true;
			GS->SetSecondsToStart(3);
			GetWorldTimerManager().SetTimer(SessionStartTimer, this, &ALobbyGameMode::StartingSessionTimer, 1.0f);
		}
	}
}

void ALobbyGameMode::PlayerNotReady()
{
	UpdatePlayersList();

	GameStarted = false;

	GetWorldTimerManager().ClearTimer(SessionStartTimer);

	if (ALobbyGameState* GS = GetGameState<ALobbyGameState>())
	{
		GS->SetSecondsToStart(0);
	}
}


void ALobbyGameMode::MessageReceived(FString Message, class ALobbyPlayerController* Sender)
{
	for (ALobbyPlayerController* Player : ConnectedPlayers)
	{
		if (Player != Sender)
		{
			Player->Client_MessageReceived(Message);
		}
	}
}

void ALobbyGameMode::StartSession()
{
	bUseSeamlessTravel = true;

	UCowobyGameInstance* GameInstance = Cast<UCowobyGameInstance>(GetGameInstance());
	GameInstance->StartSession();

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/Level/TestLevel?listen");
}


bool ALobbyGameMode::CheckIfAllPlayersReady()
{
	bool AllReady = true;

	for (ALobbyPlayerController* PC : ConnectedPlayers)
	{
		if (ALobbyPlayerState* PS = PC->GetPlayerState< ALobbyPlayerState>())
		{
			if (!PS->IsReady())
			{
				AllReady = false;
				break;
			}
		}
	}

	return AllReady;
}


void ALobbyGameMode::StartingSessionTimer()
{
	if (ALobbyGameState* GS = GetGameState<ALobbyGameState>())
	{
		if (GameStarted)
		{
			if (GS->GetSecondsToStart() > 0)
			{
				GS->SetSecondsToStart(GS->GetSecondsToStart() - 1);
				GetWorldTimerManager().SetTimer(DelayTimer, this, &ALobbyGameMode::StartingSessionTimer, 1.0f);
			}
			else
			{
				GS->Multi_StartingGame();
				StartSession();
			}
		}
	}
}