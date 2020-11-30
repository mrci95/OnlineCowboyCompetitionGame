// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPlayerController.h"
#include "OnlineCowboyGameGameModeBase.h"
#include "GameHUD.h"
#include "CowboyCharacter.h"

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
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACowboyPlayerController::OnFire);
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
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		if (Cowboy->CanReload())
		{
			Cowboy->Reload();

			if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
			{
				GameHUD->ReloadStart();
			}
		}

	}
}


void ACowboyPlayerController::ClearCylinder()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->ClearCylinder();
	}
}

void ACowboyPlayerController::InsertingBullet()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->InsertingBullet();
	}
}

void ACowboyPlayerController::BulletInserted()
{

	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->BulletInserted();	
		if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
		{
			GameHUD->BulletInserted();
		}
	}
}

void ACowboyPlayerController::FinishReload()
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->ReloadEnd();
	}
}

void ACowboyPlayerController::ReloadEnd()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->ReloadEnd();
	}
}

void ACowboyPlayerController::OnFire()
{
	UE_LOG(LogTemp, Warning, TEXT("PC fire"));
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		if (Cowboy->CanFire())
		{
			Cowboy->OnFire();

			if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
			{
				GameHUD->OnFire();
			}
		}
		else if (Cowboy->IsReloading())
		{
			FinishReload();
		}
	}
}


void ACowboyPlayerController::PawnRestarted()
{	
	
	if (IsLocalController())
	{
		if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
		{
			GameHUD->OnPawnPossessed();
		}
	}
}
