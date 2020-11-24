// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPlayerController.h"
#include "OnlineCowboyGameGameModeBase.h"
#include "GameHUD.h"

ACowboyPlayerController::ACowboyPlayerController()
{
	//ConstructorHelpers::FClassFinder<UUserWidget> MatchHUD_BPClass(TEXT("/Game/Level/MatchHUD"));
	//if (!ensure(MatchHUD_BPClass.Class != nullptr)) return;
	//MatchHUDClass = MatchHUD_BPClass.Class;

	FString server = HasAuthority() ? "Server" : "Client";
	UE_LOG(LogTemp, Warning, TEXT("%s ACowboyPlayerController()"), *server);
}

void ACowboyPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void ACowboyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Reload",IE_Pressed, this, &ACowboyPlayerController::Reload);
}

void ACowboyPlayerController::RequestRespawn()
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Server: ACowboyPlayerController::RequestRespawn() - request respawn on GM"));
		RequestRespawnFromGM();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client: ACowboyPlayerController::RequestRespawn() - send request to the server in order to request respawn on GM"));
		Server_RequestRespawn();
	}
}

void ACowboyPlayerController::RequestRespawnFromGM()
{
	if (UWorld* World = GetWorld())
	{
		if (AOnlineCowboyGameGameModeBase* GM = World->GetAuthGameMode<AOnlineCowboyGameGameModeBase>())
		{
			GM->RespawnPawn(this);
		}
	}
}

void ACowboyPlayerController::Server_RequestRespawn_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Server: ACowboyPlayerController::Server_RequestRespawn_Implementation() - respawn request came from client. Call GM"));
	RequestRespawnFromGM();
}
bool ACowboyPlayerController::Server_RequestRespawn_Validate()
{
	return true;
}

void ACowboyPlayerController::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("PC Reload"));
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->ToggleAmmoHUD();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to get GameHUD"));

	}
}
