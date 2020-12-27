// Fill out your copyright notice in the Description page of Project Settings.


#include "CowobyGameInstance.h"

#include "UObject/ConstructorHelpers.h"

#include "MenuSystem/MainMenu.h"
#include "MenuSystem/GameMenu.h"
#include "LobbySystem/LobbyMenu.h"

#include "OnlineSessionSettings.h"
#include "Interfaces/OnlineSessionInterface.h"

#include "GenericPlatform/GenericPlatformMisc.h"

const static FName SESSION_NAME = NAME_GameSession;

UCowobyGameInstance::UCowobyGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MainMenuBPClass(TEXT("/Game/MenuSystem/WBP_MainMenu"));
	ConstructorHelpers::FClassFinder<UUserWidget> GameMenuBPClass(TEXT("/Game/MenuSystem/WBP_GameMenu"));
	ConstructorHelpers::FClassFinder<UUserWidget> LobbyMenuBPClass(TEXT("/Game/LobbySystem/WBP_LobbyMenu"));

	if (!ensure(MainMenuBPClass.Class != nullptr)) return;
	MenuClass = MainMenuBPClass.Class;

	if (!ensure(GameMenuBPClass.Class != nullptr)) return;
	GameMenuClass = GameMenuBPClass.Class;

	if (!ensure(LobbyMenuBPClass.Class != nullptr)) return;
	LobbyMenuClass = LobbyMenuBPClass.Class;
}

void UCowobyGameInstance::Init()
{
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();

	if (OnlineSubsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Found subsystem %s"), *OnlineSubsystem->GetSubsystemName().ToString());

		SessionInterface = OnlineSubsystem->GetSessionInterface();

		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(this, &UCowobyGameInstance::OnCreateSessionComplete);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(this, &UCowobyGameInstance::OnDestroySessionComplete);
			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(this, &UCowobyGameInstance::OnFindSessionsComplete);
			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(this, &UCowobyGameInstance::OnJoinSessionComplete);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Not found subsystem"));
	}

}

void UCowobyGameInstance::LoadMenuWidget()
{
	if (!ensure(MenuClass != nullptr)) return;

	Menu = CreateWidget<UMainMenu>(this, MenuClass);
	if (!ensure(Menu != nullptr)) return;

	Menu->SetMenuInterface(this);

	Menu->Setup();
}

void UCowobyGameInstance::LoadGameMenu()
{

	if (!ensure(GameMenuClass != nullptr)) return;

	GameMenu = CreateWidget<UGameMenu>(this, GameMenuClass);
	if (!ensure(GameMenu != nullptr)) return;

	GameMenu->SetMenuInterface(this);

	GameMenu->Setup();
}


void UCowobyGameInstance::LoadLobbyMenu()
{
	if (!ensure(LobbyMenuClass != nullptr)) return;

	LobbyMenu = CreateWidget<ULobbyMenu>(this, LobbyMenuClass);
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->Setup();
}


void UCowobyGameInstance::Host(FString InServerName)
{
	ServerName = InServerName;
	if (SessionInterface.IsValid())
	{
		auto ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);

		if (ExistingSession != nullptr) // destroy existing session
		{
			DestorySession();
		}
		else
		{
			CreateSession();
		}
	}
}

void UCowobyGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if (SessionSearch.IsValid() && SessionInterface.IsValid())
	{
		UE_LOG(LogTemp, Warning, TEXT("Search active sessions"));

		if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
		{
			SessionSearch->bIsLanQuery = true;
		}
		else
		{
			SessionSearch->bIsLanQuery = false;
		}

		SessionSearch->MaxSearchResults = 100;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());
	}
}

void UCowobyGameInstance::Join(uint32 Index)
{
	if (!SessionInterface.IsValid()) return;
	if (!SessionSearch.IsValid()) return;

	SessionInterface->JoinSession(0, SESSION_NAME, SessionSearch->SearchResults[Index]);
}

void UCowobyGameInstance::Quit()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;
	PlayerController->ClientTravel("/Game/MenuSystem/MenuLevel", ETravelType::TRAVEL_Absolute);
}

void UCowobyGameInstance::QuitGame()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ConsoleCommand("Exit");
}

void UCowobyGameInstance::OnCreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (!bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		return;
	}

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	if (!ensure(Menu != nullptr)) return;

	Menu->Teardown();

	World->ServerTravel("/Game/LobbySystem/LobbyLevel?listen");
}

void UCowobyGameInstance::OnDestroySessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		CreateSession();
	}
}

void UCowobyGameInstance::OnFindSessionsComplete(bool bWasSuccessful)
{

	UE_LOG(LogTemp, Warning, TEXT("Search finished"));
	TArray<FServerData> ServersData;

	if (bWasSuccessful)
	{
		UE_LOG(LogTemp, Warning, TEXT("Search success"));
		for (const FOnlineSessionSearchResult& Result : SessionSearch->SearchResults)
		{
			FServerData Data;
			Data.HostUsername = Result.Session.OwningUserName;
			Data.MaxPlayers = Result.Session.SessionSettings.NumPublicConnections;
			Data.CurrentPlayers = Data.MaxPlayers - Result.Session.NumOpenPublicConnections;
			FString HostedServerName;
			if (Result.Session.SessionSettings.Get(TEXT("PuzzleGame"), HostedServerName))
			{
				UE_LOG(LogTemp, Warning, TEXT("Data found in setting: %s"), *HostedServerName);

				Data.Name = HostedServerName;
			}
			else
			{
				UE_LOG(LogTemp, Warning, TEXT("Not expected data"));
				Data.Name = Result.GetSessionIdStr();
			}
			ServersData.Add(Data);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Search failed"));
	}
	Menu->SetServerList(ServersData);
}

void UCowobyGameInstance::CreateSession()
{
	FOnlineSessionSettings SessionSettings;


	if (IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
	{
		SessionSettings.bIsLANMatch = true;
	}
	else
	{
		SessionSettings.bIsLANMatch = false;
	}

	SessionSettings.NumPublicConnections = 2;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.Set(TEXT("PuzzleGame"), ServerName, EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
	SessionInterface->CreateSession(0, SESSION_NAME, SessionSettings);
}

void UCowobyGameInstance::DestorySession()
{
	SessionInterface->DestroySession(SESSION_NAME);
}

void UCowobyGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type SessionResult)
{
	if (!SessionInterface.IsValid()) return;

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	FString ServerIP;
	if (!SessionInterface->GetResolvedConnectString(SessionName, ServerIP))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not get connect string"));
		return;
	}

	if (!ensure(PlayerController != nullptr)) return;

	Menu->Teardown();

	PlayerController->ClientTravel(ServerIP, ETravelType::TRAVEL_Absolute);

}

void UCowobyGameInstance::StartSession()
{
	if (!SessionInterface.IsValid()) return;

	SessionInterface->StartSession(SESSION_NAME);
}


void UCowobyGameInstance::UpdateLobbyPlayerList(const TArray<FPlayerData>& PlayerDataArray)
{
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->UpdatePlayerList(PlayerDataArray);
}


void UCowobyGameInstance::SetupLobbyInterface(ILobbyMenuInterface* InterfaceArg)
{
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->SetupInterface(InterfaceArg);
}


void UCowobyGameInstance::UpdateLobbyPlayerReadyButton(bool bPlayerReady)
{
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->UpdateReadyButton(bPlayerReady);
}


void UCowobyGameInstance::MessageReceived(const FString& Message)
{
	if (!ensure(LobbyMenu != nullptr)) return;

	LobbyMenu->MessageReceived(Message);
}
