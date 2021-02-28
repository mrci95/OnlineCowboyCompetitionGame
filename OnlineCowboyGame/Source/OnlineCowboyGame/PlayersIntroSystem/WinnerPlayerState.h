// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "WinnerPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AWinnerPlayerState : public APlayerState
{
	GENERATED_BODY()
	
	public:

	AWinnerPlayerState();

	virtual void PostInitializeComponents() override;

	UPROPERTY(Replicated)
	bool Winner = false;


};
