// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersIntroGameState.h"
#include "../CowobyGameInstance.h"
#include "../MatchIntroHUD.h"
#include "PlayersIntroGameMode.h"	
#include "GameFramework/PlayerState.h"


APlayersIntroGameState::APlayersIntroGameState() :AGameState()
{

}


void APlayersIntroGameState::BeginPlayersPresentation()
{
	Multi_BeginPlayersPresentation();
}

void APlayersIntroGameState::Multi_BeginPlayersPresentation_Implementation()
{
	if (UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>())
	{
		SetPlayersData();
		if (UMatchIntroHUD* MatchIntroHUD = GI->GetPlayersIntroWidget())
		{
			MatchIntroHUD->BeginPresentation();
		}
	}
}


void APlayersIntroGameState::SetPlayersData()
{
	if (UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>())
	{
		FString PlayersName[2] = { "N/A","N/A" };
		int i = 0;
		for (APlayerState* PS : PlayerArray)
		{
			if (PS == nullptr) continue;

			PlayersName[i] = PS->GetPlayerName();
			i++;
		}

		if (UMatchIntroHUD* MatchIntroHUD = GI->GetPlayersIntroWidget())
		{
			MatchIntroHUD->SetPlayersData(PlayersName[0], PlayersName[1]);
		}
	}
}
