// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPlayerState.h"
#include "CowboyCompetitionGameState.h"
#include "Net/UnrealNetwork.h"
#include "CowboyCharacter.h"
#include "PlayersIntroSystem/WinnerPlayerState.h"


ACowboyPlayerState::ACowboyPlayerState()
{
	RoundsWon = 0;
	Winner = false;
}

void ACowboyPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	UWorld* World = GetWorld();
	// Register this PlayerState with the Game's ReplicationInfo
	if (World->GetGameState() != nullptr)
	{
		World->GetGameState()->AddPlayerState(this);
	}
}

void ACowboyPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACowboyPlayerState, RoundsWon);
	DOREPLIFETIME(ACowboyPlayerState, Winner);
}

void ACowboyPlayerState::RoundWin()
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("ACowboyPlayerState::RoundWin()"));
		++RoundsWon;
		UE_LOG(LogTemp, Warning, TEXT("Server: RoundsWon: %d"), RoundsWon);

		UWorld* World = GetWorld();

		if (ACowboyCompetitionGameState* GS = World->GetGameState<ACowboyCompetitionGameState>())
		{
			GS->UpdateScore();
			GS->NextRound();
		}
	}
}

void ACowboyPlayerState::OnRep_RoundsWon()
{
	UWorld* World = GetWorld();
	if (ACowboyCompetitionGameState* GS = World->GetGameState<ACowboyCompetitionGameState>())
	{
		GS->UpdateScore();
	}
}

void ACowboyPlayerState::SetWinner(bool bWinner)
{
	if (HasAuthority())
	{
		Winner = bWinner;
	}
}

void ACowboyPlayerState::CopyProperties(APlayerState* PlayerState)
{
	Super::CopyProperties(PlayerState);

	if (PlayerState != nullptr)
	{
		AWinnerPlayerState* WinnerPS = Cast<AWinnerPlayerState>(PlayerState);

		if (WinnerPS)
		{

			WinnerPS->Winner = Winner;

		}

	}
}