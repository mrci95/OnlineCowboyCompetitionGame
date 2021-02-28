// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "WinnerGameState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AWinnerGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	AWinnerGameState();
	void BeginPlay() override;
	void BeginWinnerPresentation();
	virtual void HandlePresentationDone() override;

private:

	class UMatchIntroHUD* MatchWinnerHUD;

	void CreateMatchWinnerHUD();
	void SetPlayersDataOnHUD();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_BeginWinnerPresentation();
	void Multi_BeginWinnerPresentation_Implementation();

};
