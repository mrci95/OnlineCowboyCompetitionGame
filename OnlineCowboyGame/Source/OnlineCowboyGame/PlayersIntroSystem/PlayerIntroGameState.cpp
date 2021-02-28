// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIntroGameState.h"
#include "../MatchIntroHUD.h"
#include "../CowobyGameInstance.h"
#include "PlayersIntroGameMode.h"
#include "GameFramework/PlayerState.h"


APlayerIntroGameState::APlayerIntroGameState()
{

}

void APlayerIntroGameState::BeginPlay()
{
	Super::BeginPlay();

	CreateMatchIntroHUD();
}

void APlayerIntroGameState::CreateMatchIntroHUD()
{
	UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>();

	MatchIntroHUD = GameInstance->CreatePlayersIntroWidget();
	
	if (!ensure(MatchIntroHUD != nullptr)) return;

	MatchIntroHUD->AddToViewport();
}

void APlayerIntroGameState::BeginPlayersPresentation()
{
	//Method should be called only on server
	if (!HasAuthority())
		return;

	Multi_BeginPlayersPresentation();
}


void APlayerIntroGameState::Multi_BeginPlayersPresentation_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Multi_BeginWinnerPresentation_Implementation"));

	if (!ensure(MatchIntroHUD != nullptr)) return;

	SetPlayersDataOnHUD();

	MatchIntroHUD->BeginPresentation();
}

void APlayerIntroGameState::HandlePresentationDone()
{
	if (!HasAuthority())
		return;

	APlayersIntroGameMode* GM = GetWorld()->GetAuthGameMode<APlayersIntroGameMode>();
	if (GM)
	{
		GM->RequestTravelToGame();
	}
}

void APlayerIntroGameState::SetPlayersDataOnHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("APlayerIntroGameState::SetPlayersDataOnHUD()"));

	if (MatchIntroHUD)
	{
		if (PlayerArray.Num() > 0)
		{
			APlayerState* Player1 = PlayerArray[0];
			APlayerState* Player2 = PlayerArray[1];

			if (Player1 == nullptr) return;
			if (Player2 == nullptr) return;

			MatchIntroHUD->SetPlayersData(Player1->GetPlayerName(), Player2->GetPlayerName());
		}

	}
}
