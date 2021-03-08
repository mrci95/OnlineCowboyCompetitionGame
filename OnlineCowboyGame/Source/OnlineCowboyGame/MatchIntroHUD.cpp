// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchIntroHUD.h"
#include "WaitingForPlayersHUD.h"
#include "Components/TextBlock.h"
#include "PlayersIntroSystem/PlayersIntroPlayerController.h"
#include "PlayersIntroSystem/WinnerPlayerController.h"

void UMatchIntroHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMatchIntroHUD::BeginPresentation()
{
	PlayAnimation(BeginPresentationAnimation);
}

void UMatchIntroHUD::SetPlayersData(FString PlayerOne, FString PlayerTwo)
{
	bool server = GetWorld()->GetFirstPlayerController<APlayerController>()->HasAuthority();

	FString User = server ? "Server: " : "Client: ";

	UE_LOG(LogTemp, Warning, TEXT("%s PlayerOne %s, PlayerTwo %s"),*User, *PlayerOne, *PlayerTwo);
	Player1Name->SetText(FText::FromString(PlayerOne));
	Player2Name->SetText(FText::FromString(PlayerTwo));
}

void UMatchIntroHUD::PresentationDone()
{
	FString LevelName = GetWorld()->GetMapName();
	UE_LOG(LogTemp, Warning, TEXT("%s"),*LevelName);
	//UEDPIE_0_PlayersIntroLevel

	if (LevelName.Contains("PlayersIntroLevel"))
	{
		if (APlayersIntroPlayerController* PC = GetWorld()->GetFirstPlayerController< APlayersIntroPlayerController>())
		{
			PC->PresentationDone();
		}
	}
	else
	{
		if (AWinnerPlayerController* PC = GetWorld()->GetFirstPlayerController< AWinnerPlayerController>())
		{
			PC->PresentationDone();
		}
	}
}

void UMatchIntroHUD::TeardownPresentation()
{
	PlayAnimation(TeardownAnimation);
}


void UMatchIntroHUD::ResetWidget()
{
	PlayAnimation(Reset);
}
