// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "CowboyPlayerState.generated.h"

class UTextureRenderTarget2D;

UCLASS()
class ONLINECOWBOYGAME_API ACowboyPlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ACowboyPlayerState();

	virtual void PostInitializeComponents() override;

protected:

	//Network related

	UPROPERTY(ReplicatedUsing = OnRep_RoundsWon)
	uint16 RoundsWon;

	UFUNCTION()
	void OnRep_RoundsWon();

	//Not network related

	UTextureRenderTarget2D* MatchIntroView;

public:
	void RoundWin();

	uint16 GetRoundsWon() { return RoundsWon; };


	UTextureRenderTarget2D* GetMatchIntroView() { return MatchIntroView; };

	void SetMatchIntroView(UTextureRenderTarget2D* RT) { 

		FString User = HasAuthority()?"Server":"Client";

		UE_LOG(LogTemp, Warning, TEXT("%s ACowboyPlayerState::SetMatchIntroView"), *User);

		MatchIntroView = RT; 
	};

	void UpdateMatchIntroView();
};
