// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchIntroHUD.h"
#include "WaitingForPlayersHUD.h"
#include "Components/TextBlock.h"
#include "GameFramework/GameState.h"

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
	AGameState* GS = GetWorld()->GetGameState<AGameState>();

	if (GS)
	{
		GS->HandlePresentationDone();
	}
}

void UMatchIntroHUD::TeardownPresentation()
{
	PlayAnimation(TeardownAnimation);
}
