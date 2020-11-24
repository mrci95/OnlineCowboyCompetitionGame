// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CowboyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ACowboyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACowboyPlayerController();

	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	void RequestRespawn();

private:

	void Reload();

	void RequestRespawnFromGM();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_RequestRespawn();
	void Server_RequestRespawn_Implementation();
	bool Server_RequestRespawn_Validate();


};
