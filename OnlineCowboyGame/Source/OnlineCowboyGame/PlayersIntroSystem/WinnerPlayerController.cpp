// Fill out your copyright notice in the Description page of Project Settings.


#include "WinnerPlayerController.h"
#include "../CowobyGameInstance.h"
#include "WinnerGameMode.h"


AWinnerPlayerController::AWinnerPlayerController():APlayerController()
{

}


void AWinnerPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("AWinnerPlayerController::BeginPlay()"));

	if (IsLocalController())
	{
		CheckIfWidgetAvailable();
	}
}

void AWinnerPlayerController::CheckIfWidgetAvailable()
{
	if (UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>())
	{
		if (GameInstance->GetWinnerWidget())
		{
			UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::CheckIfWidgetAvailable() intro widget available"));
			Server_ClientReady();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::CheckIfWidgetAvailable() intro not widget available"));
			GetWorld()->GetTimerManager().SetTimer(DelayTimer, this, &AWinnerPlayerController::CheckIfWidgetAvailable, 0.5f);
		}
	}
}


void AWinnerPlayerController::Server_ClientReady_Implementation()
{
	if (AWinnerGameMode* GM = GetWorld()->GetAuthGameMode<AWinnerGameMode>())
	{
		GM->ClientReady();
	}
}

void AWinnerPlayerController::PresentationDone()
{
	Server_PresentationDone();
}


void AWinnerPlayerController::Server_PresentationDone_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::Server_PresentationDone_Implementation()"));

	if (AWinnerGameMode* GM = GetWorld()->GetAuthGameMode<AWinnerGameMode>())
	{
		GM->ClientReadyToBackToLobby();
	}
}