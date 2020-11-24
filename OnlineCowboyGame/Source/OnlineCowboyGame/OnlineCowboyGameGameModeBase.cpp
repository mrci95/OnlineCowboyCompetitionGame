// Copyright Epic Games, Inc. All Rights Reserved.


#include "OnlineCowboyGameGameModeBase.h"
#include "CowboyCompetitionGameState.h"
#include "CowboyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

void AOnlineCowboyGameGameModeBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::PostLogin"));
	++ConnectedPlayers;
	ConnectedPlayerControllers.AddUnique(NewPlayer);
	if (ConnectedPlayers == MaxConnectedPlayers)
	{
		GetWorldTimerManager().SetTimer(StartGame, this, &AOnlineCowboyGameGameModeBase::SetGameStateStart, 1.0f);
	}
}

void AOnlineCowboyGameGameModeBase::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	UE_LOG(LogTemp, Warning, TEXT("AOnlineCowboyGameGameModeBase::Logout"));
	--ConnectedPlayers;
	ConnectedPlayerControllers.Remove(Exiting);
}

void AOnlineCowboyGameGameModeBase::SetGameStateStart()
{
	UE_LOG(LogTemp, Warning, TEXT("START GAME!"));
	if (ACowboyCompetitionGameState* GS = GetGameState<ACowboyCompetitionGameState>())
	{
		GS->SetGameState(EGameState::STARTING_ROUND);
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