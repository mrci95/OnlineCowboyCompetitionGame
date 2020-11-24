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

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
	void DestoryAllPawns();
	
	void RespawnPawn(APlayerController* PC);
	uint8 GetMaxRounds(){ return MaxRounds; };
private:
	TArray<AController*> ConnectedPlayerControllers;

	uint8 ConnectedPlayers = 0;
	uint8 MaxConnectedPlayers = 2;

	uint8 MaxRounds = 15;

	FTimerHandle StartGame;
	void SetGameStateStart();

};
