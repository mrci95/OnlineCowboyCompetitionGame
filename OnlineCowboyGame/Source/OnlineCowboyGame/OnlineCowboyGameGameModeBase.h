// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "OnlineCowboyGameGameModeBase.generated.h"


UCLASS()
class ONLINECOWBOYGAME_API AOnlineCowboyGameGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:


	UFUNCTION(Exec)
		void SetFPP(bool FPPAvailable);


	virtual void GenericPlayerInitialization(AController* C) override;
	virtual void Logout(AController* Exiting) override;
	void DestoryAllPawns();
	
	void RespawnPawn(APlayerController* PC);
	uint8 GetMaxRounds(){ return MaxRounds; };
	void BackToLobby();
private:
	void SetPlayerData();
	TArray<AController*> ConnectedPlayerControllers;

	uint8 ConnectedPlayers = 0;
	uint8 MaxConnectedPlayers = 2;

	uint8 MaxRounds = 15;

	FTimerHandle DelayTimer;

	void GameStatePlayerPresentation();

};
