// Fill out your copyright notice in the Description page of Project Settings.


#include "WinnerGameMode.h"
#include "WinnerGameState.h"
#include "../CowobyGameInstance.h"

void AWinnerGameMode::GenericPlayerInitialization(AController* NewPlayer)
{

	Super::GenericPlayerInitialization(NewPlayer);
	++NoOfCurrentPlayers;


	UE_LOG(LogTemp, Warning, TEXT("AWinnerGameMode::GenericPlayerInitialization()"));

	APlayerController* PC = Cast<APlayerController>(NewPlayer);
	if (PC)
		ConnectedPlayers.Add(PC);
}

void AWinnerGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	--NoOfCurrentPlayers;

	APlayerController* PC = Cast<APlayerController>(Exiting);
	if (PC)
	{
		ConnectedPlayers.Remove(PC);
	}

}

void AWinnerGameMode::ClientReady()
{
	++ReadyClients;
	UE_LOG(LogTemp, Warning, TEXT("AWinnerGameMode::ClientReady()"));
	if (ReadyClients == 2)
	{
		PresentWinner();
	}
}

void AWinnerGameMode::ClientReadyToBackToLobby()
{
	++ReadyClientsToBackToLobby;
	if (ReadyClientsToBackToLobby == 2)
	{
		RequestTravelToLobby();
	}
}

void AWinnerGameMode::PresentWinner()
{
	UE_LOG(LogTemp, Warning, TEXT("2 playeers logged start presentation"));
	if (AWinnerGameState* GS = GetGameState<AWinnerGameState>())
	{
		GS->BeginWinnerPresentation();
	}
}

void AWinnerGameMode::RequestTravelToLobby()
{
	GetWorldTimerManager().SetTimer(DelayTimer, this, &AWinnerGameMode::BackToLobby, 4.0f);
}

void AWinnerGameMode::BackToLobby()
{
	bUseSeamlessTravel = true;

	if (UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>())
	{
		GI->BackToLobby();
	}
}