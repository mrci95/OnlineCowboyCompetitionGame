// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "GameStateInterface.h"
#include "CowboyCompetitionGameState.generated.h"

UENUM(BlueprintType)
enum class EGameState : uint8

{
	WAITING_FOR_PLAYERS,
	PLAYERS_PRESENTATION,
	STARTING_MATCH,
	STARTING_ROUND,
	ROUND_PENDING,
	ROUND_OVER,
	MATCH_END
};

UCLASS()
class ONLINECOWBOYGAME_API ACowboyCompetitionGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	ACowboyCompetitionGameState();

	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

	virtual void AddPlayerState(APlayerState* PlayerState) override;

	EGameState GetGameState(){ return CurrentGameState;};

	void SetFPPAvailable(bool Var);
	bool GetFPPAvailable() { return FPPAvailable; };

	UFUNCTION()
	void SetGameState(EGameState State);

	void Subscribe(IGameStateInterface* Obj);

	void UpdateScore();

	void NextRound();

	void PresentationDone();

	void PresentationEnded();

	void MatchOutroLoaded();

protected:

	UPROPERTY(ReplicatedUsing = OnRep_CurrentGameState)
	EGameState CurrentGameState;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentRound)
	uint8 CurrentRound;

	UPROPERTY(ReplicatedUsing = OnRep_RoundStartCounter)
	uint8 RoundStartCounter;


	UFUNCTION()
	void OnRep_CurrentGameState();

	UFUNCTION()
	void OnRep_CurrentRound();

	UFUNCTION()
	void OnRep_RoundStartCounter();


private:

	UPROPERTY(ReplicatedUsing = OnRep_FPPAvailable)
	bool FPPAvailable;

	UFUNCTION()
	void OnRep_FPPAvailable();

	FTimerDelegate DelayTimerDelegate;
	FTimerHandle DelayTimer;

	TArray<IGameStateInterface*> SubscribedObj;

	class AGameHUD* GameHUD;
	void PlayersPresentation();
	void StartingMatch();
	void StartingRound();
	void RoundPending();
	void RoundOver();
	void MatchEnd();



	void TriggerPresentationEndForAllPlayers();
	bool CheckIfAnyPlayerWon();

	void StartCounting();
	void OneSecondInterval();
	void SetRoundStartCounterHUD(uint8 Counter);
	void BackToLobby();

	FTimerHandle RespawnTimer;
	void OnRespawnTimerExpiration();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_Respawn();
	void Multi_Respawn_Implementation();
	bool Multi_Respawn_Validate();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_TriggerPresentationEnd();
	void Multi_TriggerPresentationEnd_Implementation();
	bool Multi_TriggerPresentationEnd_Validate();

};
