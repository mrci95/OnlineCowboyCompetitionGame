// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerController.h"
#include "../CowobyGameInstance.h"
#include "LobbyGameMode.h"
#include "LobbyPlayerState.h"

void ALobbyPlayerController::BeginPlay()
{
	if (UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>())
	{
		if(IsLocalController())
			GameInstance->SetupLobbyInterface(this);
	}
}

void ALobbyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

}

void ALobbyPlayerController::Client_UpdatePlayerList_Implementation(const TArray<FPlayerData>& PlayerDataArray)
{
	if (UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>())
	{
		GameInstance->UpdateLobbyPlayerList(PlayerDataArray);
	}

	FString players = "";
	for (FPlayerData Data : PlayerDataArray)
	{
		players.Append(Data.ToString());
	}

	UE_LOG(LogTemp, Warning, TEXT("Client_UpdatePlayerList_Implementation %s"), *players);
}

void ALobbyPlayerController::ReadyButtonClicked()
{
	UE_LOG(LogTemp, Warning, TEXT("ALobbyPlayerController::ReadyButtonClicked"));

	ALobbyPlayerState* PS = GetPlayerState<ALobbyPlayerState>();
	UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>();

	if (PS == nullptr) return;
	if (GameInstance == nullptr) return;

	
	if (PS->IsReady())
	{
		PS->SetIsReady(false);
		Server_NotReadyToPlay();
	}
	else
	{
		PS->SetIsReady(true);
		Server_ReadyToPlay();
	}

	GameInstance->UpdateLobbyPlayerReadyButton(PS->IsReady());
	
}


void ALobbyPlayerController::SendButtonClicked(const FString& Message)
{
	ALobbyPlayerState* PS = GetPlayerState<ALobbyPlayerState>();
	UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>();

	if (PS == nullptr || GameInstance == nullptr) return;

	FString NickAndMessage = FString::Printf(TEXT("%s: %s"), *PS->GetPlayerName(), *Message);

	GameInstance->MessageReceived(NickAndMessage);

	Server_SendMessage(NickAndMessage);

}

void ALobbyPlayerController::Server_SendMessage_Implementation(const FString& Message)
{
	if (ALobbyGameMode* GM = GetWorld()->GetAuthGameMode<ALobbyGameMode>())
	{
		GM->MessageReceived(Message, this);
	}
}

void ALobbyPlayerController::Client_MessageReceived_Implementation(const FString& Message)
{
	UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>();

	GameInstance->MessageReceived(Message);
}

void ALobbyPlayerController::Server_ReadyToPlay_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ALobbyPlayerController::Server_ReadyToPlay_Implementation"));

	if (ALobbyPlayerState* PS = GetPlayerState<ALobbyPlayerState>())
	{
		PS->SetIsReady(true);	
			
		if (ALobbyGameMode* GM = GetWorld()->GetAuthGameMode<ALobbyGameMode>())
		{
			GM->PlayerReady();
		}
	}

}

void ALobbyPlayerController::Server_NotReadyToPlay_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ALobbyPlayerController::Server_NotReadyToPlay_Implementation"));

	if (ALobbyPlayerState* PS = GetPlayerState<ALobbyPlayerState>())
	{
		PS->SetIsReady(false);

		if (ALobbyGameMode* GM = GetWorld()->GetAuthGameMode<ALobbyGameMode>())
		{
			GM->PlayerNotReady();
		}
	}
}