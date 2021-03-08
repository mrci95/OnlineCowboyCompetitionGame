// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersIntroGameMode.h"
#include "PlayersIntroGameState.h"


APlayersIntroGameMode::APlayersIntroGameMode() :AGameMode()
{

}

void APlayersIntroGameMode::GenericPlayerInitialization(AController* NewPlayer)
{

	Super::GenericPlayerInitialization(NewPlayer);
	++NoOfCurrentPlayers;

	UE_LOG(LogTemp, Warning, TEXT("player logged in"));

	APlayerController* PC = Cast<APlayerController>(NewPlayer);
	if (PC)
		ConnectedPlayers.Add(PC);
}

void APlayersIntroGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	--NoOfCurrentPlayers;

	APlayerController* PC = Cast<APlayerController>(Exiting);
	if (PC)
	{
		ConnectedPlayers.Remove(PC);
	}

}

void APlayersIntroGameMode::PresentPlayers()
{
	UE_LOG(LogTemp, Warning, TEXT("All players ready. Start presentation"));
	if (APlayersIntroGameState* GS = GetGameState<APlayersIntroGameState>())
	{
		GS->BeginPlayersPresentation();
	}

}

void APlayersIntroGameMode::ClientReadyToStartGame()
{
	++ReadyClientsToStartGame;
	if (ReadyClientsToStartGame == 2)
	{
		RequestTravelToGame();
	}
}

void APlayersIntroGameMode::RequestTravelToGame()
{
	GetWorldTimerManager().SetTimer(DelayTimer, this, &APlayersIntroGameMode::StartGame, 4.0f);
}

void APlayersIntroGameMode::StartGame()
{
	bUseSeamlessTravel = true;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/GameLevel/GameLevel?listen");
}

void APlayersIntroGameMode::ClientReady()
{
	++ReadyClients;
	UE_LOG(LogTemp, Warning, TEXT("APlayersIntroGameMode::ClientReady()"));
	if (ReadyClients == 2)
	{
		PresentPlayers();
	}
}
