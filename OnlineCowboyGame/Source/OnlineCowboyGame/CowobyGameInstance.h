// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "MenuSystem/MenuInterface.h"
#include "OnlineSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "CowobyGameInstance.generated.h"

/**
 *
 */
UCLASS()
class ONLINECOWBOYGAME_API UCowobyGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:
	UCowobyGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void Init();

	UFUNCTION(BlueprintCallable)
		void LoadMenuWidget();

	UFUNCTION(BlueprintCallable)
		void LoadGameMenu();

	UFUNCTION(Exec)
		void Host(FString InServerName);

	UFUNCTION(Exec)
		void Join(uint32 Index);

	UFUNCTION(Exec)
		void RefreshServerList();

	UFUNCTION(Exec)
		void Quit();

	UFUNCTION(Exec)
		void QuitGame();

	void StartSession();

private:
	TSubclassOf<class UMenuWidget> MenuClass;
	TSubclassOf<class UMenuWidget> GameMenuClass;

	IOnlineSessionPtr SessionInterface;

	void OnCreateSessionComplete(FName SessionName, bool bWasSuccessful);
	void OnDestroySessionComplete(FName SessionName, bool bWasSuccessful);
	void OnFindSessionsComplete(bool bWasSuccessful);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type CompleteResult);

	class UMainMenu* Menu;
	class UGameMenu* GameMenu;

	TSharedPtr<class FOnlineSessionSearch>		SessionSearch;

	void CreateSession();
	void DestorySession();

	FString ServerName;

};

