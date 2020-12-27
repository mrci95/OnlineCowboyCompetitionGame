// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "LobbyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ALobbyPlayerState : public APlayerState
{
	GENERATED_BODY()
	

	public:
	void SetIsReady(bool bIsReady_In);
	bool IsReady();

	private:
	bool bIsReady = false;

};
