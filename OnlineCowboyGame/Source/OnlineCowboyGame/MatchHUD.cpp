// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchHUD.h"
#include "Animation/WidgetAnimation.h"
#include "Components/TextBlock.h"

void UMatchHUD::ShowAtGameStart()
{
	AddToViewport();

	PlayAnimation(Show);
}

void UMatchHUD::SetPlayerOneScore(uint16 Score)
{
	if (!ensure(PlayerScore_1 != nullptr)) return;
	PlayerScore_1->SetText(FText::FromString(FString::FromInt(Score)));
}

void UMatchHUD::SetPlayerTwoScore(uint16 Score)
{
	if (!ensure(PlayerScore_2 != nullptr)) return;
	PlayerScore_2->SetText(FText::FromString(FString::FromInt(Score)));
}

void UMatchHUD::SetCurrentRound(uint8 Round)
{
	UE_LOG(LogTemp, Warning, TEXT("UMatchHUD::SetCurrentRound %d"), Round);
	CurrentRound->SetText(FText::FromString(FString::FromInt(Round)));
}


void UMatchHUD::SetPlayersName(FString P1, FString P2)
{
	PlayerName_1->SetText(FText(FText::FromString(P1)));
	PlayerName_2->SetText(FText(FText::FromString(P2)));
}