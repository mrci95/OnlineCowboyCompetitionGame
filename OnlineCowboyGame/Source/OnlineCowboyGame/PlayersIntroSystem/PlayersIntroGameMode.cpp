// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersIntroGameMode.h"
#include "PlayerIntroGameState.h"

void APlayersIntroGameMode::GenericPlayerInitialization(AController* NewPlayer)
{

	Super::GenericPlayerInitialization(NewPlayer);
	++NoOfCurrentPlayers;


	APlayerController* PC = Cast<APlayerController>(NewPlayer);
	if (PC)
		ConnectedPlayers.Add(PC);

	if (NoOfCurrentPlayers == 2)
	{
		GetWorldTimerManager().SetTimer(DelayTimer, this, &APlayersIntroGameMode::PresentPlayers, 2.5f);
	}

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
	UE_LOG(LogTemp, Warning, TEXT("2 playeers logged start presentation"));
	if (APlayerIntroGameState* GS = GetGameState<APlayerIntroGameState>())
	{
		GS->BeginPlayersPresentation();
	}
}

void APlayersIntroGameMode::RequestTravelToGame()
{
	GetWorldTimerManager().SetTimer(DelayTimer, this, &APlayersIntroGameMode::StartGame, 3.0f);
}

void APlayersIntroGameMode::StartGame()
{
	bUseSeamlessTravel = true;

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;
	World->ServerTravel("/Game/GameLevel/GameLevel?listen");
}
