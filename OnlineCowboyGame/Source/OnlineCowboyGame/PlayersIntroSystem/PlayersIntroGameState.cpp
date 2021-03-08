// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersIntroGameState.h"
#include "../CowobyGameInstance.h"
#include "../MatchIntroHUD.h"
#include "PlayersIntroGameMode.h"


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
		if (UMatchIntroHUD* MatchIntroHUD = GI->GetPlayersIntroWidget())
		{
			MatchIntroHUD->BeginPresentation();
		}
	}
}
