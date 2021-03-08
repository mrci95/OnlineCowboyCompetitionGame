// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PlayersIntroGameState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API APlayersIntroGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	APlayersIntroGameState();

	void BeginPlayersPresentation();

private:

	uint8 ClientsWithFinishedPresentation = 0;

	UFUNCTION(NetMulticast,Reliable)
	void Multi_BeginPlayersPresentation();
	void Multi_BeginPlayersPresentation_Implementation();


};
