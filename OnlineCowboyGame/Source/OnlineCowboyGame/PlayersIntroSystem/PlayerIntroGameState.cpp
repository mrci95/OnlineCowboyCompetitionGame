// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerIntroGameState.h"
#include "../MatchIntroHUD.h"
#include "../CowobyGameInstance.h"
#include "PlayersIntroGameMode.h"


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
	UE_LOG(LogTemp, Warning, TEXT("Multi_BeginPlayersPresentation_Implementation"));

	if (!ensure(MatchIntroHUD != nullptr)) return;

	MatchIntroHUD->BeginPresentation();
}

void APlayerIntroGameState::PresentationDone()
{
	if (!HasAuthority())
		return;

	APlayersIntroGameMode* GM = GetWorld()->GetAuthGameMode<APlayersIntroGameMode>();
	if (GM)
	{
		GM->RequestTravelToGame();
	}
}
