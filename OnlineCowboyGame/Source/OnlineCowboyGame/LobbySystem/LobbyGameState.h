// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "LobbyGameState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ALobbyGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	int8 GetSecondsToStart(){ return SecondsToStart; };

	void SetSecondsToStart(int8 Seconds);


	UFUNCTION(NetMulticast, Reliable)
	void Multi_StartingGame();
	void Multi_StartingGame_Implementation();

private:

	UPROPERTY(ReplicatedUsing = OnRep_SecondsToStart)
		int8 SecondsToStart = -1;

	UFUNCTION()
	void OnRep_SecondsToStart();
};
