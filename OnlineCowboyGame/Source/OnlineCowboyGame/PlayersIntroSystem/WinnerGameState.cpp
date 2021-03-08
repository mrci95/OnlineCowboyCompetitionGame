// Fill out your copyright notice in the Description page of Project Settings.


#include "WinnerGameState.h"


#include "../MatchIntroHUD.h"
#include "../CowobyGameInstance.h"
#include "GameFramework/PlayerState.h"
#include "WinnerPlayerState.h"


AWinnerGameState::AWinnerGameState()
{

}

void AWinnerGameState::BeginWinnerPresentation()
{
	//Method should be called only on server
	if (!HasAuthority())
		return;

	Multi_BeginWinnerPresentation();
}


void AWinnerGameState::Multi_BeginWinnerPresentation_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Multi_BeginWinnerPresentation_Implementation"));

	if (UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>())
	{
		MatchWinnerHUD = GI->GetWinnerWidget();
		if (MatchWinnerHUD != nullptr)
		{
			SetPlayersDataOnHUD();
			MatchWinnerHUD->BeginPresentation();
		}
	}
}



void AWinnerGameState::SetPlayersDataOnHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("AWinnerGameState::SetPlayersDataOnHUD()"));

	if (MatchWinnerHUD)
	{
		if (PlayerArray.Num() > 1)
		{
			AWinnerPlayerState* Player1 = Cast<AWinnerPlayerState>(PlayerArray[0]);
			AWinnerPlayerState* Player2 = Cast<AWinnerPlayerState>(PlayerArray[1]);

			if (Player1 == nullptr) return;
			if (Player2 == nullptr) return;

			if (Player1->Winner)
			{
				MatchWinnerHUD->SetPlayersData(Player1->GetPlayerName(), Player2->GetPlayerName());
			}
			else
			{
				MatchWinnerHUD->SetPlayersData(Player2->GetPlayerName(), Player1->GetPlayerName());
			}


		}

	}
}
