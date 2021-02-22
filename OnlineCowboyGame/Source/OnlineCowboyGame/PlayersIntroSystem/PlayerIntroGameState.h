// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "PlayerIntroGameState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API APlayerIntroGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	APlayerIntroGameState();
	void BeginPlay() override;
	void BeginPlayersPresentation();
	void PresentationDone();

private:

	class UMatchIntroHUD* MatchIntroHUD;
	
	void CreateMatchIntroHUD();
	void SetPlayersDataOnHUD();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_BeginPlayersPresentation();
	void Multi_BeginPlayersPresentation_Implementation();


};
