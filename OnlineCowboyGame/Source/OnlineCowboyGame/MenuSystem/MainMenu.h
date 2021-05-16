// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MenuInterface.h"
#include "ConfirmationInterface.h"
#include "MainMenu.generated.h"

USTRUCT()
struct FServerData 
{
	GENERATED_BODY()

    FString Name;
	uint16 CurrentPlayers;
	uint16 MaxPlayers;
	FString HostUsername;
};

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UMainMenu : public UMenuWidget, public IConfirmationInterface
{
	GENERATED_BODY()

public:

	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerData);

	void SetSelectedIndex(uint32 intex);

	virtual void Confirm() override;
	virtual void Reject() override;


	//Main Menu widgets
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* HostMenuButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* JoinMenuButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* ExitButton;

	//Host menu widgets

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* HostMenuToMainMenuButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* HostServerButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableTextBox* ServerNameTextBox;


	//Join menu widgets
	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* JoinMenuToMainMenuButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* JoinMenuRefreshServersButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* JoinServerButton;


	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ServersList;

	//General widget
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* ExitGameButton;
	
	UPROPERTY(meta = (BindWidget))
	class UOverlay* MenuBar;


protected:

	virtual bool Initialize();


	UFUNCTION()
	void HostMenu();

	UFUNCTION()
	void JoinMenu();

	UFUNCTION()
	void BackMainMenu();

	UFUNCTION()
	void HostServer();

	UFUNCTION()
    void JoinServer();

	UFUNCTION()
	void Exit();

	UFUNCTION()
	void RefreshServerList();


private:

	TOptional <uint32> SelectedIndex;

	TSubclassOf<class UServerRow> ServerRowClass;
	TSubclassOf<class UUserWidget> SearchingServersClass;
	TSubclassOf<class UUserWidget> NoServersFoundClass;
	TSubclassOf<class UExitConfirmation> ExitConfirmationClass;

	UPROPERTY()
	class UExitConfirmation* ExitConfirmation = nullptr;

	void UpdateChildren();
	void SetSearchingServers();
	void MenuChange();
	void QuitGame();
};
