// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayersIntroPlayerController.h"
#include "../CowobyGameInstance.h"
#include "PlayersIntroGameMode.h"



APlayersIntroPlayerController::APlayersIntroPlayerController():APlayerController()
{

}

void APlayersIntroPlayerController::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::BeginPlay()"));

	if (IsLocalController())
	{
		if (UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>())
		{
			if (GameInstance->GetPlayersIntroWidget())
			{
				UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::BeginPlay() intro widget available"));
				Server_ClientReady();
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::BeginPlay() intro widget not available"));
				GetWorld()->GetTimerManager().SetTimer(DelayTimer, this, &APlayersIntroPlayerController::CheckIfWidgetAvailable, 0.5f);
			}
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::BeginPlay() no game instance"));
		}
	}
}

void APlayersIntroPlayerController::CheckIfWidgetAvailable()
{
	if (UCowobyGameInstance* GameInstance = GetGameInstance<UCowobyGameInstance>())
	{
		if (GameInstance->GetPlayersIntroWidget())
		{
			UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::CheckIfWidgetAvailable() intro widget available"));
			Server_ClientReady();
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::CheckIfWidgetAvailable() intro widget not available"));
			GetWorld()->GetTimerManager().SetTimer(DelayTimer,this, &APlayersIntroPlayerController::CheckIfWidgetAvailable, 0.5f);
		}
	}
}


void APlayersIntroPlayerController::Server_ClientReady_Implementation()
{
	if (APlayersIntroGameMode* GM = GetWorld()->GetAuthGameMode<APlayersIntroGameMode>())
	{
		GM->ClientReady();
	}
}

void APlayersIntroPlayerController::PresentationDone()
{
	Server_PresentationDone();
}


void APlayersIntroPlayerController::Server_PresentationDone_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("APlayersIntroPlayerController::Server_PresentationDone_Implementation()"));

	if (APlayersIntroGameMode* GM = GetWorld()->GetAuthGameMode<APlayersIntroGameMode>())
	{
		GM->ClientReadyToStartGame();
	}
}