// Copyright Epic Games, Inc. All Rights Reserved.


#include "OnlineCowboyGameGameModeBase.h"
#include "CowboyCompetitionGameState.h"
#include "CowboyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "CowboyPlayerState.h"
#include "CowobyGameInstance.h"

void AOnlineCowboyGameGameModeBase::GenericPlayerInitialization(AController* NewPlayer)
{
	Super::GenericPlayerInitialization(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::GenericPlayerInitialization"));
	++ConnectedPlayers;
	ConnectedPlayerControllers.AddUnique(NewPlayer);
	if (ConnectedPlayers == MaxConnectedPlayers)
	{
		GetWorldTimerManager().SetTimer(DelayTimer, this, &AOnlineCowboyGameGameModeBase::GameStatePlayerPresentation, 1.0f);
	}
}

void AOnlineCowboyGameGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::Logout"));
	--ConnectedPlayers;
	ConnectedPlayerControllers.Remove(Exiting);
}


void AOnlineCowboyGameGameModeBase::GameStatePlayerPresentation()
{
	UE_LOG(LogTemp, Warning, TEXT("Begin Match"));

	SetPlayerData();
	if (ACowboyCompetitionGameState* GS = GetGameState<ACowboyCompetitionGameState>())
	{
		GS->SetGameState(EGameState::PLAYERS_PRESENTATION_DONE);
	}
}

void AOnlineCowboyGameGameModeBase::SetPlayerData()
{
	for (AController* Controller : ConnectedPlayerControllers)
	{
		APlayerController* PC = Cast< APlayerController>(Controller);

		if (PC)
		{
			if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(PC->GetPawn()))
			{
				if (ACowboyPlayerState* PS = Pawn->GetPlayerState<ACowboyPlayerState>())
				{
					FString Name = PS->GetPlayerName();
					PS->SetPlayerName(Name);
				}
			}
		}
	}
}

void AOnlineCowboyGameGameModeBase::DestoryAllPawns()
{
	for (AController* Controller : ConnectedPlayerControllers)
	{
		APlayerController* PC = Cast< APlayerController>(Controller);

		if (PC)
		{
			if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(PC->GetPawn()))
			{

				Pawn->DestroyWeapons();
				Pawn->Destroy();
			}
		}
	}

	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);

	for (AActor* SpawnPoint : SpawnPoints)
	{
		if (APlayerStart* Start = Cast< APlayerStart>(SpawnPoint))
		{
			Start->PlayerStartTag = FName(FString("None"));
		}
	}
}

void AOnlineCowboyGameGameModeBase::RespawnPawn(APlayerController* PC)
{
	if (PC == nullptr) return;

	UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::RespawnPawn"));

	if (UWorld* World = GetWorld())
	{
		FTransform SpawnTransform;
		TArray<AActor*> SpawnPoints;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);

		for (AActor* SpawnPoint : SpawnPoints)
		{
			if (APlayerStart* Start = Cast< APlayerStart>(SpawnPoint))
			{
				if (Start->PlayerStartTag == FName(FString("None")))
				{
					SpawnTransform = Start->GetTransform();
					Start->PlayerStartTag = FName(FString("Taken"));
					break;
				}
			}
		}

		APawn* NewCowboy = World->SpawnActor<APawn>(GetDefaultPawnClassForController(PC), SpawnTransform);
		UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::RespawnPawn %x"),(void*)NewCowboy);

		PC->Possess(NewCowboy);
	}

}

void AOnlineCowboyGameGameModeBase::TravelToWinnerPresentation()
{
	bUseSeamlessTravel = true;

	if (UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>())
	{
		GI->TravelToWinnerPresentation();
	}
}


void AOnlineCowboyGameGameModeBase::SetFPP(bool FPPAvailable)
{
	UE_LOG(LogTemp, Warning, TEXT(" AOnlineCowboyGameGameModeBase::SetFPP %d"), FPPAvailable);
	if (ACowboyCompetitionGameState* GS = GetGameState<ACowboyCompetitionGameState>())
	{
		GS->SetFPPAvailable(FPPAvailable);
	}
}
