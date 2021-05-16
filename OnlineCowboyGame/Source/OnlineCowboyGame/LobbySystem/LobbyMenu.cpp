// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyMenu.h"
#include "Components/Button.h"
#include "LobbyConnectedPlayerRow.h"
#include "Components/ScrollBox.h"
#include "Components/TextBlock.h"
#include "Styling/SlateColor.h"
#include "Components/EditableText.h"

ULobbyMenu::ULobbyMenu(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<ULobbyConnectedPlayerRow> LobbyConnectedPlayerRowBPClass(TEXT("/Game/LobbySystem/WBP_LobbyConnectedPlayerRow"));

	if (!ensure(LobbyConnectedPlayerRowBPClass.Class != nullptr)) return;
	LobbyConnectedPlayerRowClass = LobbyConnectedPlayerRowBPClass.Class;
}


void ULobbyMenu::SetupInterface(ILobbyMenuInterface* LobbyInterfaceArg)
{
	LobbyInterface = LobbyInterfaceArg;
}

bool ULobbyMenu::Initialize()
{

	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(ReadyButton != nullptr)) return false;
	if (!ensure(SendButton != nullptr)) return false;

	ReadyButton->OnClicked.AddDynamic(this, &ULobbyMenu::ReadyButtonClicked);
	SendButton->OnClicked.AddDynamic(this, &ULobbyMenu::SendButtonClicked);

	return true;
}

void ULobbyMenu::UpdatePlayerList(const TArray<FPlayerData>& PlayerDataArray)
{
	ConnectedPlayersList->ClearChildren();
	
	for (const FPlayerData& PlayerData : PlayerDataArray)
	{
		ULobbyConnectedPlayerRow* LobbyConnectedPlayerRow = CreateWidget<ULobbyConnectedPlayerRow>(this, LobbyConnectedPlayerRowClass);
		LobbyConnectedPlayerRow->PlayerName->SetText(FText::FromString(PlayerData.PlayerName));
		LobbyConnectedPlayerRow->ReadyText->SetText(FText::FromString(PlayerData.bIsReady ? "READY":"NOT READY"));


		LobbyConnectedPlayerRow->ReadyText->SetColorAndOpacity(PlayerData.bIsReady ? FSlateColor(FLinearColor(0,1,0)) : FSlateColor(FLinearColor(1, 0, 0)));
		ConnectedPlayersList->AddChild(LobbyConnectedPlayerRow);
	}
}


void ULobbyMenu::ReadyButtonClicked()
{
	if (LobbyInterface != nullptr)
	{
		LobbyInterface->ReadyButtonClicked();
	}
}

void ULobbyMenu::Setup()
{
	Reset();
	Super::Setup();
}

void ULobbyMenu::SendButtonClicked()
{

	FText Message = MessageInput->GetText();

	if (!Message.IsEmptyOrWhitespace())
	{
		FString MessageString = Message.ToString();

		if (LobbyInterface != nullptr)
		{
			LobbyInterface->SendButtonClicked(MessageString);
		}
	}

	MessageInput->SetText(FText());
}


void ULobbyMenu::UpdateReadyButton(bool bPlayerReady)
{
	if (bPlayerReady)
	{
		ReadyButton->SetBackgroundColor(FLinearColor::Red);
		ReadyButtonText->SetText(FText::FromString("NOT READY"));
	}
	else
	{
		ReadyButton->SetBackgroundColor(FLinearColor::Green);
		ReadyButtonText->SetText(FText::FromString("READY"));
	}
}


void ULobbyMenu::MessageReceived(const FString& Message)
{
	UE_LOG(LogTemp, Warning, TEXT("MessageReceived : %s "), *Message);

	UTextBlock* MessageWidget = NewObject<UTextBlock>(UTextBlock::StaticClass());
	MessageWidget->SetText(FText::FromString(Message));

	Chat->AddChild(MessageWidget);
}


void ULobbyMenu::StartingMatchSeconds(int8 Seconds)
{
	FText StartMatch = FText::FromString(FString::Printf(TEXT("Starting match in %d ..."), Seconds));
	StartingMatchText->SetText(StartMatch);

	if (Seconds == 3)
		StartingMatchText->SetVisibility(ESlateVisibility::Visible);

	if (Seconds == 0)
		StartingMatchText->SetVisibility(ESlateVisibility::Hidden);
}

void ULobbyMenu::Reset()
{
	StartingMatchText->SetVisibility(ESlateVisibility::Hidden);
	Chat->ClearChildren();

	ReadyButton->SetBackgroundColor(FLinearColor::Green);
	ReadyButtonText->SetText(FText::FromString("READY"));

	ConnectedPlayersList->ClearChildren();
}