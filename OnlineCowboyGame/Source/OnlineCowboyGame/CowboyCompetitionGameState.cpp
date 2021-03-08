// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCompetitionGameState.h"
#include "OnlineCowboyGameGameModeBase.h"
#include "CowobyGameInstance.h"
#include "UObject/ConstructorHelpers.h"
#include "Net/UnrealNetwork.h"
#include "CowboyPlayerState.h"
#include "CowboyPlayerController.h"
#include "GameHUD.h"
#include "MatchIntroHUD.h"
#include "CowboyCharacter.h"	
#include "Kismet/GameplayStatics.h"

ACowboyCompetitionGameState::ACowboyCompetitionGameState()
{
	CurrentGameState = EGameState::WAITING_FOR_PLAYERS;
	CurrentRound = 1;
	RoundStartCounter = 0;
	FPPAvailable = true;
}

void ACowboyCompetitionGameState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACowboyCompetitionGameState, CurrentGameState);
	DOREPLIFETIME(ACowboyCompetitionGameState, CurrentRound);
	DOREPLIFETIME(ACowboyCompetitionGameState, RoundStartCounter);
	DOREPLIFETIME(ACowboyCompetitionGameState, FPPAvailable);
}

void ACowboyCompetitionGameState::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* PC = UGameplayStatics::GetPlayerControllerFromID(this, 0);
	UE_LOG(LogTemp, Warning, TEXT(" ACowboyCompetitionGameState::BeginPlay() PC %x"), (void*)PC);
	if (PC)
	{
		GameHUD = PC->GetHUD<AGameHUD>();
	}

	UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>();
	MatchIntroHUD = GI->GetPlayersIntroWidget();

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
		case EGameState::PLAYERS_PRESENTATION_DONE:
			PresentationDone();
			break;
		case EGameState::STARTING_MATCH:
			StartingMatch();
			break;
		case EGameState::STARTING_ROUND:
			StartingRound();
			break;
		case EGameState::ROUND_PENDING:
			RoundPending();
			break;
		case EGameState::ROUND_OVER:
			RoundOver();
			break;
		case EGameState::MATCH_END:
			MatchEnd();
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
		case EGameState::PLAYERS_PRESENTATION_DONE:
			PresentationDone();
			break;	
		case EGameState::STARTING_MATCH:
			StartingMatch();
			break;
		case EGameState::STARTING_ROUND:
			StartingRound();
			break;
		case EGameState::ROUND_PENDING:
			RoundPending();
			break;
		case EGameState::ROUND_OVER:
			RoundOver();
			break;
		case EGameState::MATCH_END:
			MatchEnd();
			break;
		default:
			break;
	}
}

void ACowboyCompetitionGameState::SetPlayersDataOnHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::SetPlayersDataOnHUD()"));

	if (GameHUD)
	{
		if (PlayerArray.Num() != 2) return;

		ACowboyPlayerState* FirstCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[0]);
		ACowboyPlayerState* SecondCowboyPS = Cast< ACowboyPlayerState>(PlayerArray[1]);

		if (FirstCowboyPS == nullptr) return;
		if (SecondCowboyPS == nullptr) return;

		GameHUD->SetPlayersData(FirstCowboyPS->GetPlayerName(), SecondCowboyPS->GetPlayerName());
	}
}

void ACowboyCompetitionGameState::PresentationDone()
{
	UCowobyGameInstance* GI = GetGameInstance<UCowobyGameInstance>();

	if (GI)
	{
		GI->UnloadMatchIntro();
	}

	SetPlayersDataOnHUD();

	if (HasAuthority())
	{
		DelayTimerDelegate.BindUFunction(this, FName("SetGameState"), EGameState::STARTING_MATCH);
		GetWorld()->GetTimerManager().SetTimer(DelayTimer, DelayTimerDelegate, 2.f, false);
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
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::StartingGame(), NoOfPlayers %d"), PlayerArray.Num());

	if (GameHUD != nullptr)
	{
		GameHUD->ShowMatchHUDAtGameStart();
	}

	if (HasAuthority())
	{
		DelayTimerDelegate.BindUFunction(this, FName("SetGameState"), EGameState::STARTING_ROUND);
		GetWorld()->GetTimerManager().SetTimer(DelayTimer, DelayTimerDelegate, 2.f, false);
	}
}

void ACowboyCompetitionGameState::StartingRound()
{
	if(HasAuthority())
		StartCounting();
}

void ACowboyCompetitionGameState::StartCounting()
{
	if (HasAuthority())
	{
		RoundStartCounter = 3;
		UE_LOG(LogTemp, Warning, TEXT("Server timer: %u"), RoundStartCounter);
		SetRoundStartCounterHUD(RoundStartCounter);
		GetWorld()->GetTimerManager().SetTimer(DelayTimer, this, &ACowboyCompetitionGameState::OneSecondInterval, 1.0f);
	}
}

void ACowboyCompetitionGameState::OneSecondInterval()
{
	if (HasAuthority())
	{
		--RoundStartCounter;
		UE_LOG(LogTemp, Warning, TEXT("Server timer: %u"), RoundStartCounter);

		SetRoundStartCounterHUD(RoundStartCounter);
		if (RoundStartCounter > 0)
		{
			GetWorld()->GetTimerManager().SetTimer(DelayTimer, this, &ACowboyCompetitionGameState::OneSecondInterval, 1.0f);
		}
		else
		{
			SetGameState(EGameState::ROUND_PENDING);
		}
	}
}

void ACowboyCompetitionGameState::OnRep_RoundStartCounter()
{
	UE_LOG(LogTemp, Warning, TEXT("Client timer: %u"), RoundStartCounter);

	SetRoundStartCounterHUD(RoundStartCounter);
}

void ACowboyCompetitionGameState::RoundPending()
{
	UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::StartingRound()"));


	if (ACowboyPlayerController* PC = Cast<ACowboyPlayerController>(UGameplayStatics::GetPlayerControllerFromID(this, 0)))
	{
		PC->EnableInput(PC);
	}
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
}

void ACowboyCompetitionGameState::OnRep_CurrentRound()
{

}

void ACowboyCompetitionGameState::RoundOver()
{
	if (ACowboyPlayerController* PC = Cast<ACowboyPlayerController>(UGameplayStatics::GetPlayerControllerFromID(this, 0)))
	{
		PC->DisableAndResetInput();
	}

	if (!HasAuthority()) return;

	if (CheckIfAnyPlayerWon())
	{
		DelayTimerDelegate.BindUFunction(this, FName("SetGameState"), EGameState::MATCH_END);
		GetWorld()->GetTimerManager().SetTimer(DelayTimer, DelayTimerDelegate, 5.f, false);
	}
	else
	{
		GetWorldTimerManager().SetTimer(RespawnTimer, this, &ACowboyCompetitionGameState::OnRespawnTimerExpiration, 5.0f, false);
	}
}


bool ACowboyCompetitionGameState::CheckIfAnyPlayerWon()
{
	for (APlayerState* PS : PlayerArray)
	{
		if (ACowboyPlayerState* CowboyPS = Cast< ACowboyPlayerState>(PS))
		{
			if (CowboyPS->GetRoundsWon() == 1)
			{
				CowboyPS->SetWinner(true);
				return true;
			}
		}
	}
	return false;
}

void ACowboyCompetitionGameState::OnRespawnTimerExpiration()
{
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

	DelayTimerDelegate.BindUFunction(this, FName("SetGameState"), EGameState::STARTING_ROUND);
	GetWorld()->GetTimerManager().SetTimer(DelayTimer, DelayTimerDelegate, 1.f, false);
}

void ACowboyCompetitionGameState::Multi_Respawn_Implementation()
{
	if (UWorld* World = GetWorld())
	{
		UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation() world ok"));
		ACowboyPlayerController* PC = Cast<ACowboyPlayerController>(UGameplayStatics::GetPlayerControllerFromID(this, 0));
		UE_LOG(LogTemp, Warning, TEXT("ACowboyCompetitionGameState::Multi_Respawn_Implementation() %x"), (void*)PC);

		if (PC)
		{
			PC->RequestRespawn();
		}
	}

	if (GameHUD == nullptr) return;

	GameHUD->SetCurrentRound(CurrentRound);
}
bool ACowboyCompetitionGameState::Multi_Respawn_Validate()
{
	return true;
}


void ACowboyCompetitionGameState::SetRoundStartCounterHUD(uint8 Counter)
{
	if (GameHUD == nullptr) return;

	GameHUD->SetRoundStartCounter(Counter);
}


void ACowboyCompetitionGameState::MatchEnd()
{
	UE_LOG(LogTemp, Warning, TEXT("MatchEnd"));

	TravelToWinnerPresentation();
}


void ACowboyCompetitionGameState::MatchOutroLoaded()
{
	if (GameHUD == nullptr) return;
	
	ACowboyPlayerState* CowboyPS1 = Cast< ACowboyPlayerState>(PlayerArray[0]);
	ACowboyPlayerState* CowboyPS2 = Cast< ACowboyPlayerState>(PlayerArray[1]);

	if (CowboyPS1->GetRoundsWon() == 8)
	{
		if (ACowboyCharacter* Cowoby = CowboyPS1->GetPawn<ACowboyCharacter>())
		{
			Cowoby->Winner();
		}

	}
	else
	{
		if (ACowboyCharacter* Cowoby = CowboyPS2->GetPawn<ACowboyCharacter>())
		{
			Cowoby->Winner();
		}
	}

	GetWorldTimerManager().SetTimer(DelayTimer, this, &ACowboyCompetitionGameState::TravelToWinnerPresentation, 5.0f, false);
}

void ACowboyCompetitionGameState::TravelToWinnerPresentation()
{
	if (UWorld* World = GetWorld())
	{
		if (AOnlineCowboyGameGameModeBase* GM = World->GetAuthGameMode<AOnlineCowboyGameGameModeBase>())
		{
			GM->TravelToWinnerPresentation();
		}
	}
}

void ACowboyCompetitionGameState::SetFPPAvailable(bool Var)
{
	FPPAvailable = Var; 	
	
	if (FPPAvailable == false)
	{
		ACowboyPlayerController* PC = Cast<ACowboyPlayerController>(UGameplayStatics::GetPlayerControllerFromID(this, 0));
		if (PC)
		{
			PC->FPPViewDisabled();
		}
	}
};

void ACowboyCompetitionGameState::OnRep_FPPAvailable()
{
	if (FPPAvailable == false)
	{
		ACowboyPlayerController* PC = Cast<ACowboyPlayerController>(UGameplayStatics::GetPlayerControllerFromID(this, 0));
		if (PC)
		{
			PC->FPPViewDisabled();
		}
	}
}