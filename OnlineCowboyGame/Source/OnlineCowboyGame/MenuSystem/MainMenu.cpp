// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "ServerRow.h"
#include "ExitConfirmation.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Components/Overlay.h"
#include "MainMenuPlayerController.h"

UMainMenu::UMainMenu(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UServerRow> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	ConstructorHelpers::FClassFinder<UUserWidget> SearchingServersBPClass(TEXT("/Game/MenuSystem/WBP_SearchingServers"));
	ConstructorHelpers::FClassFinder<UUserWidget> NoServersFoundBPClass(TEXT("/Game/MenuSystem/WBP_NoServersFound"));
	ConstructorHelpers::FClassFinder<UExitConfirmation> ExitConfirmationBPClass(TEXT("/Game/MenuSystem/WBP_ExitConfirmation"));

	if (!ensure(ServerRowBPClass.Class != nullptr)) return;
	ServerRowClass = ServerRowBPClass.Class;

	if (!ensure(SearchingServersBPClass.Class != nullptr)) return;
	SearchingServersClass = SearchingServersBPClass.Class;

	if (!ensure(NoServersFoundBPClass.Class != nullptr)) return;
	NoServersFoundClass = NoServersFoundBPClass.Class;

	if (!ensure(ExitConfirmationBPClass.Class != nullptr)) return;
	ExitConfirmationClass = ExitConfirmationBPClass.Class;
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
	ExitButton->OnClicked.AddDynamic(this, &UMainMenu::Exit);

	//Host menu buttons callback
	HostMenuToMainMenuButton->OnClicked.AddDynamic(this, &UMainMenu::BackMainMenu);
	HostServerButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	//Join menu buttons callback
	JoinMenuToMainMenuButton->OnClicked.AddDynamic(this, &UMainMenu::BackMainMenu);
	JoinMenuRefreshServersButton->OnClicked.AddDynamic(this, &UMainMenu::RefreshServerList);
	JoinServerButton->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	ExitGameButton->OnClicked.AddDynamic(this, &UMainMenu::Exit);

	//Create ExitConfirmation widget
	if (ExitConfirmationClass == nullptr) return false;
	ExitConfirmation = CreateWidget<UExitConfirmation>(this, ExitConfirmationClass);
	ExitConfirmation->Setup(this);

	return true;
}


void UMainMenu::MenuChange()
{
	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	AMainMenuPlayerController* PlayerController = World->GetFirstPlayerController<AMainMenuPlayerController>();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->MenuChange();
}
void UMainMenu::Exit()
{
	if (!ensure(ExitConfirmation != nullptr)) return;

	MenuBar->SetVisibility(ESlateVisibility::HitTestInvisible);
	ExitGameButton->SetVisibility(ESlateVisibility::HitTestInvisible);

	ExitConfirmation->AddToViewport();
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

	MenuChange();
}

void UMainMenu::JoinMenu()
{

	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MenuInterface != nullptr)) return;

	UE_LOG(LogTemp, Warning, TEXT("Switch to join menu"));
	MenuSwitcher->SetActiveWidgetIndex(2);

	ServersList->ClearChildren();
	SetSearchingServers();

	MenuChange();

	MenuInterface->RefreshServerList();
}

void UMainMenu::BackMainMenu()
{
	UE_LOG(LogTemp, Warning, TEXT("Switch to main menu"));
	if (!ensure(MenuSwitcher != nullptr)) return;
	MenuSwitcher->SetActiveWidgetIndex(0);
	ServersList->ClearChildren();
	MenuChange();
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

	if (ServerData.Num() > 0)
	{
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
	else
	{
		if (NoServersFoundClass == nullptr) return;
		UUserWidget* NoServerFoundWidget = CreateWidget<UUserWidget>(this, NoServersFoundClass);
		ServersList->AddChild(NoServerFoundWidget);
	}

}

void UMainMenu::SetSearchingServers()
{
	if (SearchingServersClass == nullptr) return;
	UE_LOG(LogTemp, Warning, TEXT("Searching servers"));
	UUserWidget* SearchingServers = CreateWidget<UUserWidget>(this, SearchingServersClass);
	ServersList->AddChild(SearchingServers);
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

void UMainMenu::RefreshServerList()
{
	ServersList->ClearChildren();
	SetSearchingServers();
	MenuInterface->RefreshServerList();
}

void UMainMenu::Confirm()
{
	QuitGame();
}

void UMainMenu::Reject()
{
	if (!ensure(ExitConfirmation != nullptr)) return;

	MenuBar->SetVisibility(ESlateVisibility::Visible);
	ExitGameButton->SetVisibility(ESlateVisibility::Visible);

	ExitConfirmation->RemoveFromViewport();
}