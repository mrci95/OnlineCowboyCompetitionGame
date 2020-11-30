// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "GameHUDWidget.h"
#include "MatchHUD.h"

AGameHUD::AGameHUD()
{
	ConstructorHelpers::FClassFinder<UGameHUDWidget> WBP_GameHUD_BPClass(TEXT("/Game/Level/WBP_GameHUD"));
	if (!ensure(WBP_GameHUD_BPClass.Class != nullptr)) return;
	GameHUDWidgetClass = WBP_GameHUD_BPClass.Class;


	ConstructorHelpers::FClassFinder<UUserWidget> MatchHUD_BPClass(TEXT("/Game/Level/MatchHUD"));
	if (!ensure(MatchHUD_BPClass.Class != nullptr)) return;
	MatchHUDClass = MatchHUD_BPClass.Class;
}


void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateGameInterface();

	CreateMatchHUD();
}

void AGameHUD::CreateGameInterface()
{

	UE_LOG(LogTemp, Warning, TEXT("%x"), (void*)GameHUDWidgetClass.Get());
	if (!ensure(GameHUDWidgetClass != nullptr)) return;

	if (UWorld* World = GetWorld())
	{
		if (APlayerController* PC = World->GetFirstPlayerController())
		{
			UE_LOG(LogTemp, Warning, TEXT("AGameHUD::CreateGameInterface()"));
			GameHUDWidget = CreateWidget<UGameHUDWidget>(PC, GameHUDWidgetClass);

			GameHUDWidget->AddToViewport();
		}
	}
}


void AGameHUD::CreateMatchHUD()
{
	if (!ensure(MatchHUDClass != nullptr)) return;
	
	
	if (APlayerController* PC = GetOwningPlayerController())
	{
		UE_LOG(LogTemp, Warning, TEXT("AGameHUD::CreateMatchHUD()"));
		MatchHUD = CreateWidget<UMatchHUD>(PC, MatchHUDClass);
	}
}

void AGameHUD::ShowMatchHUDAtGameStart()
{
	if (!ensure(MatchHUD != nullptr)) return;
	MatchHUD->ShowAtGameStart();
}


void AGameHUD::UpdatePlayersScore(uint16 PlayerOne, uint16 PlayerTwo)
{
	if (!ensure(MatchHUD != nullptr)) return;

	MatchHUD->SetPlayerOneScore(PlayerOne);
	MatchHUD->SetPlayerTwoScore(PlayerTwo);

}

void AGameHUD::SetCurrentRound(uint16 Round)
{
	if (!ensure(MatchHUD != nullptr)) return;
	MatchHUD->SetCurrentRound(Round);
}

void AGameHUD::ReloadStart()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->ReloadStart();
	}
}

void AGameHUD::ClearCylinder()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->ClearCylinder();
	}
}

void AGameHUD::InsertingBullet()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->InsertingBullet();
	}
}

void AGameHUD::BulletInserted()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->BulletInserted();
	}
}


void AGameHUD::ReloadEnd()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->ReloadEnd();
	}
}

void AGameHUD::OnFire()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->OnFire();
	}
}


void AGameHUD::OnPawnPossessed()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->OnPawnPossessed();
	}
}