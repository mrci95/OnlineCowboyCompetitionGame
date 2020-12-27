// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "../MenuSystem/MenuWidget.h"
#include "LobbyMenuInterface.h"
#include "LobbyMenu.generated.h"

USTRUCT()
struct FPlayerData
{
	GENERATED_BODY()

	UPROPERTY()
	FString PlayerName;

	UPROPERTY()
	bool bIsReady;

	FString ToString() { return FString::Printf(TEXT("Name = %s isReady = %d; "), *PlayerName, bIsReady); }
};
/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ULobbyMenu : public UMenuWidget
{
	GENERATED_BODY()
	
public:
	ULobbyMenu(const FObjectInitializer& ObjectInitializer);

	void SetupInterface(ILobbyMenuInterface* LobbyInterfaceArg);

	void UpdatePlayerList(const TArray<FPlayerData>& PlayerDataArray);

	void UpdateReadyButton(bool bPlayerReady);

	void MessageReceived(const FString& Message);

protected:

	virtual bool Initialize();

private:

	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ConnectedPlayersList;

	UPROPERTY(meta = (BindWidget))
	class UScrollBox* Chat;

	UPROPERTY(meta = (BindWidget))
	class UButton* ReadyButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ReadyButtonText;

	UPROPERTY(meta = (BindWidget))
	class UButton* SendButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* MessageInput;

	TSubclassOf<class ULobbyConnectedPlayerRow> LobbyConnectedPlayerRowClass;

	UFUNCTION()
	void ReadyButtonClicked();

	UFUNCTION()
	void SendButtonClicked();

	ILobbyMenuInterface* LobbyInterface = nullptr;
};
