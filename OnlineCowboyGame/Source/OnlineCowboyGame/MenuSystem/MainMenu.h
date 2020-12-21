// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MenuInterface.h"
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
class ONLINECOWBOYGAME_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:

	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(TArray<FServerData> ServerData);

	void SetSelectedIndex(uint32 intex);


	//Main Menu widgets
	UPROPERTY(meta = (BindWidget))
	class UButton* HostMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuButton;

	//Host menu widgets

	UPROPERTY(meta = (BindWidget))
	class UButton* HostMenuToMainMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* HostServerButton;

	UPROPERTY(meta = (BindWidget))
	class UEditableText* ServerNameTextBox;


	//Join menu widgets
	UPROPERTY(meta = (BindWidget))
	class UButton* JoinMenuToMainMenuButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* JoinServerButton;


	UPROPERTY(meta = (BindWidget))
	class UScrollBox* ServersList;

	//General widget
	UPROPERTY(meta = (BindWidget))
	class UWidgetSwitcher* MenuSwitcher;


	UPROPERTY(meta = (BindWidget))
	class UButton* ExitGameButton;
	


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
	void QuitGame();


private:

	TOptional <uint32> SelectedIndex;

	TSubclassOf<class UServerRow> ServerRowClass;

	void UpdateChildren();
};
