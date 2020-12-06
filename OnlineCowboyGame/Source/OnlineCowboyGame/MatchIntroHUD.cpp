// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchIntroHUD.h"
#include "WaitingForPlayersHUD.h"
#include "Components/TextBlock.h"
#include "CowboyCompetitionGameState.h"

void UMatchIntroHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMatchIntroHUD::BeginWaitingForPlayers()
{
	WaitingForPlayers->Show();
}


void UMatchIntroHUD::StopWaitingForPlayers()
{
	WaitingForPlayers->Hide();
}

void UMatchIntroHUD::PresentPlayers()
{
	PlayAnimationForward(Player1Show);
	PlayAnimationForward(Player2Show);
}


void UMatchIntroHUD::SetPlayersName(FString PlayerOne, FString PlayerTwo)
{
	UE_LOG(LogTemp, Warning, TEXT("PlayerOne %s, PlayerTwo %s"), *PlayerOne, *PlayerTwo);
	Player1Name->SetText(FText::FromString(PlayerOne));
	Player2Name->SetText(FText::FromString(PlayerTwo));
}

void UMatchIntroHUD::PresentPlayersName()
{
	PlayAnimationForward(PlayersNamePresentation);
}

void UMatchIntroHUD::EndPlayersPresentation()
{
	PlayAnimationReverse(Player1Show);
	PlayAnimationReverse(Player2Show);
	PlayAnimationForward(EndPresentation);
}


void UMatchIntroHUD::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
	if (ACowboyCompetitionGameState* GS = GetWorld()->GetGameState<ACowboyCompetitionGameState>())
	{
		if (Animation == PlayersNamePresentation)
		{
			UE_LOG(LogTemp, Warning, TEXT("PlayersNamePresentation finished"));

			GS->PresentationDone();
			
		}
		else if (Animation == EndPresentation)
		{
			GS->PresentationEnded();
		}
	}
	
}