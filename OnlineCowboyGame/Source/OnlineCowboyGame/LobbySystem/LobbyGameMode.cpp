// Fill out your copyright notice in the Description page of Project Settings.



#include "LobbyGameMode.h"
#include "../CowboyAnimInstance.h"
#include "GameFramework/PlayerState.h"
#include "GameFramework/PlayerController.h"
#include "LobbyPlayerState.h"
#include "LobbyPlayerController.h"
#include "LobbyMenu.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
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
		//start timer start session
	}
}

void ALobbyGameMode::PlayerNotReady()
{
	UpdatePlayersList();

	if (CheckIfAllPlayersReady())
	{
		//start timer start session
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
	//UPuzzlePlatformsGameInstance* GameInstance = Cast<UPuzzlePlatformsGameInstance>(GetGameInstance());
	//GameInstance->StartSession();

	//UWorld* World = GetWorld();
	//if (!ensure(World != nullptr)) return;

	//World->ServerTravel("/Game/ThirdPersonCPP/Maps/Game?listen");
}


bool ALobbyGameMode::CheckIfAllPlayersReady()
{
	return false;
}