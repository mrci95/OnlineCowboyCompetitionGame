// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "LobbyMenu.h"

#include "LobbyMenuInterface.h"
#include "LobbyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ALobbyPlayerController : public APlayerController, public ILobbyMenuInterface
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;
	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	UFUNCTION(Client, Reliable)
	void Client_UpdatePlayerList(const TArray<FPlayerData>& PlayerDataArray);
	void Client_UpdatePlayerList_Implementation(const TArray<FPlayerData>& PlayerDataArray);

	UFUNCTION(Server, Reliable)
	void Server_ClientInitialized();
	void Server_ClientInitialized_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_ReadyToPlay();
	void Server_ReadyToPlay_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_NotReadyToPlay();
	void Server_NotReadyToPlay_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_SendMessage(const FString& Message);
	void Server_SendMessage_Implementation(const FString& Message);

	UFUNCTION(Client, Reliable)
	void Client_MessageReceived(const FString& Message);
	void Client_MessageReceived_Implementation(const FString& Message);

	bool ClientInitialized = false;

	UFUNCTION(BlueprintCallable)
	bool IsJoiningPlayer(){ return bIsJoiningPlayer; };

	void SetIsJoiningPlayer(bool val) { bIsJoiningPlayer = val; };

private:

	UPROPERTY(Replicated)
	bool bIsJoiningPlayer = false;

	void CheckIfClientInitialized();
	void ReadyButtonClicked();

	void SendButtonClicked(const FString& Message);

	FTimerDelegate DelayTimerDelegate;
	FTimerHandle DelayTimer;

	void UpdateLobbyPlayerList(const TArray<FPlayerData>& PlayerDataArray);

};
