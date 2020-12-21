// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "ServerRow.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableText.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"

UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UServerRow> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));

	if (!ensure(ServerRowBPClass.Class != nullptr)) return;
	ServerRowClass = ServerRowBPClass.Class;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(HostServerButton != nullptr)) return false;
	if (!ensure(JoinMenuButton != nullptr)) return false;
	if (!ensure(JoinMenuToMainMenuButton != nullptr)) return false;
	if (!ensure(JoinServerButton != nullptr)) return false;

	//Main menu buttons callback
	HostMenuButton->OnClicked.AddDynamic(this, &UMainMenu::HostMenu);
	JoinMenuButton->OnClicked.AddDynamic(this, &UMainMenu::JoinMenu);

	//Host menu buttons callback
	HostMenuToMainMenuButton->OnClicked.AddDynamic(this, &UMainMenu::BackMainMenu);
	HostServerButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	//Join menu buttons callback
	JoinMenuToMainMenuButton->OnClicked.AddDynamic(this, &UMainMenu::BackMainMenu);
	JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	ExitGameButton->OnClicked.AddDynamic(this, &UMainMenu::QuitGame);

	return true;
}

void UMainMenu::QuitGame()
{
	if (!ensure(MenuInterface != nullptr)) return;

	MenuInterface->QuitGame();
}

void UMainMenu::HostServer()
{
	if (!ensure(MenuInterface != nullptr)) return;
	if (!ensure(ServerNameTextBox != nullptr)) return;

	MenuInterface->Host(ServerNameTextBox->GetText().ToString());
	
}

void UMainMenu::HostMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Switch to host menu"));
	MenuSwitcher->SetActiveWidgetIndex(1);
}

void UMainMenu::JoinMenu()
{

	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MenuInterface != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Switch to join menu"));
	MenuSwitcher->SetActiveWidgetIndex(2);

	MenuInterface->RefreshServerList();
}

void UMainMenu::BackMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Switch to main menu"));
	if (!ensure(MenuSwitcher != nullptr)) return;
	MenuSwitcher->SetActiveWidgetIndex(0);
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr && SelectedIndex.IsSet())
	{
		UE_LOG(LogTemp, Warning, TEXT("Set index: %d"), SelectedIndex.GetValue());
		MenuInterface->Join(SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Index not set or MenuInterface is NULL"));
	}
}

void UMainMenu::SetServerList(TArray<FServerData> ServerData)
{
	ServersList->ClearChildren();

	uint32 index = 0;
	for(const FServerData& Server : ServerData)
	{
		UServerRow* ServerRow = CreateWidget<UServerRow>(this, ServerRowClass);
		ServerRow->ServerName->SetText(FText::FromString(Server.Name));
		ServerRow->HostUsername->SetText(FText::FromString(Server.HostUsername));
		FString ConnectionInfo("");
		ConnectionInfo.AppendInt(Server.CurrentPlayers);
		ConnectionInfo.Append("/");
		ConnectionInfo.AppendInt(Server.MaxPlayers);
		ServerRow->ConnectionInfo->SetText(FText::FromString(ConnectionInfo));
		ServerRow->Setup(this, index);
		ServersList->AddChild(ServerRow);
		++index;
	}
}

void UMainMenu::SetSelectedIndex(uint32 index)
{
	SelectedIndex = index;
	UpdateChildren();
}

void UMainMenu::UpdateChildren()
{
	if (ServersList != nullptr)
	{
		for (int32 i = 0; i<ServersList->GetChildrenCount(); i++)
		{
			auto Row = Cast<UServerRow>(ServersList->GetChildAt(i));
			if (Row != nullptr)
			{
				Row->Selected = (SelectedIndex.IsSet() && SelectedIndex.GetValue() == i);
			}
		}
	}
}