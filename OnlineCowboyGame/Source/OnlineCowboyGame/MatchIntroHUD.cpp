// Fill out your copyright notice in the Description page of Project Settings.


#include "MatchIntroHUD.h"
#include "WaitingForPlayersHUD.h"
#include "Components/TextBlock.h"
#include "CowboyCompetitionGameState.h"
#include "CowboyRenderTargetHUD.h"

void UMatchIntroHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UMatchIntroHUD::BeginWaitingForPlayers()
{
	AddToViewport();
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


void UMatchIntroHUD::SetPlayersData(FString PlayerOne, FString PlayerTwo,UTextureRenderTarget2D* PlayerOneView, UTextureRenderTarget2D* PlayerTwoView)
{
	bool server = GetWorld()->GetFirstPlayerController<APlayerController>()->HasAuthority();

	FString User = server ? "Server: " : "Client: ";

	UE_LOG(LogTemp, Warning, TEXT("%s PlayerOne %s, PlayerTwo %s"),*User, *PlayerOne, *PlayerTwo);
	Player1Name->SetText(FText::FromString(PlayerOne));
	Player2Name->SetText(FText::FromString(PlayerTwo));

	GetWorld()->GetFirstPlayerController<APlayerController>()->HasAuthority();
	
	UE_LOG(LogTemp, Warning, TEXT("%s PlayerOneView %x, PlayerTwoView %x"), *User, (void*)PlayerOneView, (void*)PlayerTwoView);

	WBP_Player1Image->SetRenderView(PlayerOneView);
	WBP_Player2Image->SetRenderView(PlayerTwoView);
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


void UMatchIntroHUD::BeginMatchSummary()
{
	UE_LOG(LogTemp, Warning, TEXT("UMatchIntroHUD::BeginMatchSummary()"));

	AddToViewport();
	PlayAnimationForward(BeginMatchOutro);
}

void UMatchIntroHUD::ShowWinner(FString PlayerName, UTextureRenderTarget2D* View)
{
	WBP_WinnerView->SetRenderView(View);
	WinnerName->SetText(FText::FromString(PlayerName));

	PlayAnimation(WinnerAnimation);
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
			RemoveFromViewport();
		}
		else if (Animation == BeginMatchOutro)
		{
			UE_LOG(LogTemp, Warning, TEXT("MatchOutroLoaded"));
			GS->MatchOutroLoaded();
		}
	}
	
}