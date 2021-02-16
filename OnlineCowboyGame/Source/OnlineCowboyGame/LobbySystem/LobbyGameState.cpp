// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameState.h"
#include "../CowobyGameInstance.h"
#include "Net/UnrealNetwork.h"


void ALobbyGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGameState, SecondsToStart);
}


void ALobbyGameState::SetSecondsToStart(int8 Seconds)
{
	SecondsToStart = Seconds;
	if (UCowobyGameInstance* GI = GetGameInstance< UCowobyGameInstance>())
	{
		GI->SetLobbyStartingTimer(SecondsToStart);
	}
}

void ALobbyGameState::OnRep_SecondsToStart()
{
	if (UCowobyGameInstance* GI = GetGameInstance< UCowobyGameInstance>())
	{
		GI->SetLobbyStartingTimer(SecondsToStart);
	}
}


void ALobbyGameState::Multi_StartingGame_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Multi_StartingGame_Implementation"));
	if (UCowobyGameInstance* GI = GetGameInstance< UCowobyGameInstance>())
	{
		GI->LobbyMenuTeardown();
	}
}