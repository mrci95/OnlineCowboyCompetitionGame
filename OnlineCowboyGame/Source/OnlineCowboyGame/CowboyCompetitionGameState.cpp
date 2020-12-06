// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCompetitionGameState.h"
#include "OnlineCowboyGameGameModeBase.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"
#include "CowboyPlayerState.h"
#include "CowboyPlayerController.h"
#include "GameHUD.h"

ACowboyCompetitionGameState::ACowboyCompetitionGameState()
{
	CurrentGameState = EGameState::WAITING_FOR_PLAYERS;
	CurrentRound = 1;
	PlayersWithPresentationDone = 0;
}

void ACowboyCompetitionGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACowboyCompetitionGameState, CurrentGameState);
	DOREPLIFETIME(ACowboyCompetitionGameState, CurrentRound);
}

void ACowboyCompetitionGameState::BeginPlay()
{
	Super::BeginPlay();

	GameHUD = Cast<AGameHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());
}

void ACowboyCompetitionGameState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ACowboyCompetitionGameState::AddPlayerState(APlayerState* PlayerState)
{
	if (!PlayerState->IsInactive())
	{
		PlayerArray.AddUnique(PlayerState);
	}
}


void ACowboyCompetitionGameState::Subscribe(IGameStateInterface* Obj)
{
	SubscribedObj.Add(Obj);
}

void ACowboyCompetitionGameState::SetGameState(EGameState State)
{ 
	if (!HasAuthority()) return;

	CurrentGameState = State; 

	switch (CurrentGameState)
	{
		case EGameState::PLAYERS_PRESENTATION:
			PlayersPresentation();
			break;
		case EGameState::STARTING_MATCH:
			StartingMatch();
			break;
		case EGameState::STARTING_ROUND:
			StartingRound();
			break;
		case EGameState::ROUND_PENDING:
			break;
		case EGameState::ROUND_OVER:
			RoundOver();
			break;
		default:
			break;
	}
}

void ACowboyCompetitionGameState::OnRep_CurrentGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::OnRep_CurrentGameState() %d"), (uint8)CurrentGameState);

	switch (CurrentGameState)
	{
		case EGameState::PLAYERS_PRESENTATION:
			PlayersPresentation();
			break;	
		case EGameState::STARTING_MATCH:
			StartingMatch();
			break;
		case EGameState::STARTING_ROUND:
			StartingRound();
			break;
		case EGameState::ROUND_PENDING:
			break;
		case EGameState::ROUND_OVER:
			RoundOver();
			break;
		default:
			break;
	}
}

void ACowboyCompetitionGameState::PlayersPresentation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::PlayersPresentation()"));

	if (GameHUD)
	{
		ACowboyPlayerState* FirstCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[0]);
		ACowboyPlayerState* SecondCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[1]);

		if (FirstCowboyPS == nullptr) return;
		if (SecondCowboyPS == nullptr) return;

		GameHUD->SetPlayersName(FirstCowboyPS->GetPlayerName(), SecondCowboyPS->GetPlayerName());

		GameHUD->BeginPlayersPresentation();
		
	}
}

void ACowboyCompetitionGameState::PresentationDone()
{
	if (HasAuthority())
	{
		GetWorldTimerManager().SetTimer(DelayTimer, this, &ACowboyCompetitionGameState::TriggerPresentationEndForAllPlayers, 3.0f);
	}
}

void ACowboyCompetitionGameState::PresentationEnded()
{
	if (HasAuthority())
	{
		SetGameState(EGameState::STARTING_MATCH);
	}
}

void ACowboyCompetitionGameState::TriggerPresentationEndForAllPlayers()
{
	Multi_TriggerPresentationEnd();
}

void ACowboyCompetitionGameState::Multi_TriggerPresentationEnd_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_TriggerPresentationEnd_Implementation()"));
	if (GameHUD)
	{
		GameHUD->EndPlayersPresentation();
	}

}

bool ACowboyCompetitionGameState::Multi_TriggerPresentationEnd_Validate()
{
	return true;
}

void ACowboyCompetitionGameState::StartingMatch()
{
	//Inform all subs about starting game
	for (IGameStateInterface* Sub : SubscribedObj)
	{
		if (Sub)
		{
			Sub->OnStartingGame();
		}
	}
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::StartingGame(), NoOfPlayers %d"), PlayerArray.Num());

	if (GameHUD != nullptr)
	{
		GameHUD->ShowMatchHUDAtGameStart();
	}

	DelayTimerDelegate.BindUFunction(this, FName("SetGameState"), EGameState::STARTING_ROUND);
	GetWorld()->GetTimerManager().SetTimer(DelayTimer, DelayTimerDelegate, 2.0f, false);
}

void ACowboyCompetitionGameState::StartingRound()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::StartingRound()"));
}

void ACowboyCompetitionGameState::UpdateScore()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::UpdateScore()"));
	if (PlayerArray.Num() != 2) return;
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::UpdateScore(), no of players 2"));

	ACowboyPlayerState* FirstCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[0]);
	ACowboyPlayerState* SecondCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[1]);
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::UpdateScore() FirstCowboyPS: %x, SecondCowboyPS: %x"), (void*)FirstCowboyPS, (void*)SecondCowboyPS);

	if (FirstCowboyPS == nullptr) return;
	if (SecondCowboyPS == nullptr) return;
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::UpdateScore() no nulls :)"));

	if (GameHUD != nullptr)
	{
		GameHUD->UpdatePlayersScore(FirstCowboyPS->GetRoundsWon(), SecondCowboyPS->GetRoundsWon());
	}

}

void ACowboyCompetitionGameState::NextRound()
{
	++CurrentRound;
	if (GameHUD == nullptr) return;

	GameHUD->SetCurrentRound(CurrentRound);
}

void ACowboyCompetitionGameState::OnRep_CurrentRound()
{
	if (GameHUD == nullptr) return;

	GameHUD->SetCurrentRound(CurrentRound);
}

void ACowboyCompetitionGameState::RoundOver()
{
	//RespawnAllPlayers in 5 seconds
	if (!HasAuthority()) return;
	GetWorldTimerManager().SetTimer(RespawnTimer, this, &ACowboyCompetitionGameState::OnRespawnTimerExpiration, 5.0f, false);
}

void ACowboyCompetitionGameState::OnRespawnTimerExpiration()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::OnRespawnTimerExpiration()"));

	//Destory all pawns and inform local PC to request respawn
	if (UWorld* World = GetWorld())
	{
		if (AOnlineCowboyGameGameModeBase* GM = World->GetAuthGameMode< AOnlineCowboyGameGameModeBase>())
		{
			GM->DestoryAllPawns();
		}
	}
	//Each client should request own new pawn
	Multi_Respawn();
}

void ACowboyCompetitionGameState::Multi_Respawn_Implementation()
{
	//Get My local PC
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation()"));
	if (UWorld* World = GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation() world ok"));
		UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation() %x"), (void*)World->GetFirstPlayerController());
		ACowboyPlayerController* PC = World->GetFirstPlayerController< ACowboyPlayerController>();
		UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation() %x"), (void*)PC);

		if (PC)
		{

			PC->RequestRespawn();
		}
	}
}
bool ACowboyCompetitionGameState::Multi_Respawn_Validate()
{
	return true;
}