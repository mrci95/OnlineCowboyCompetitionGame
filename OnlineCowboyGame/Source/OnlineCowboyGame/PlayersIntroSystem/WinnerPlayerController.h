// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "WinnerPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AWinnerPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	AWinnerPlayerController();

	void PresentationDone();

protected:

	virtual void BeginPlay() override;

private:
	void CheckIfWidgetAvailable();

	FTimerHandle DelayTimer;

	UFUNCTION(Server, Reliable)
	void Server_ClientReady();
	void Server_ClientReady_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_PresentationDone();
	void Server_PresentationDone_Implementation();
};
