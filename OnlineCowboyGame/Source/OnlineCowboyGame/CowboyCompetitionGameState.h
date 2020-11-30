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

	void SetGameState(EGameState State);

	void Subscribe(IGameStateInterface* Obj);

	void UpdateScore();

	void NextRound();


protected:

	UPROPERTY(ReplicatedUsing = OnRep_CurrentGameState)
	EGameState CurrentGameState;

	UPROPERTY(ReplicatedUsing = OnRep_CurrentRound)
	uint8 CurrentRound;


	UFUNCTION()
	void OnRep_CurrentGameState();

	UFUNCTION()
	void OnRep_CurrentRound();
private:
	TArray<IGameStateInterface*> SubscribedObj;

	class AGameHUD* GameHUD;
	void WaitingForPlayers();
	void StartingRound();
	void RoundOver();

	FTimerHandle RespawnTimer;
	void OnRespawnTimerExpiration();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_Respawn();
	void Multi_Respawn_Implementation();
	bool Multi_Respawn_Validate();
};
