// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "GameHUDWidget.h"
#include "MatchHUD.h"
#include "MatchIntroHUD.h"

AGameHUD::AGameHUD()
{
	ConstructorHelpers::FClassFinder<UGameHUDWidget> WBP_GameHUD_BPClass(TEXT("/Game/GameLevel/WBP_GameHUD"));
	if (!ensure(WBP_GameHUD_BPClass.Class != nullptr)) return;
	GameHUDWidgetClass = WBP_GameHUD_BPClass.Class;


	ConstructorHelpers::FClassFinder<UUserWidget> MatchHUD_BPClass(TEXT("/Game/GameLevel/MatchHUD"));
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
		if (APlayerController* PC = GetOwningPlayerController())
		{
			GameHUDWidget = CreateWidget<UGameHUDWidget>(PC, GameHUDWidgetClass);

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


void AGameHUD::BeginPlayersPresentation()
{
	//To be removed
	//if (!MatchIntroHUD) return;

	GetWorldTimerManager().SetTimer(DelayTimer, this, &AGameHUD::PresentPlayers, 0.5f);
}


void AGameHUD::EndPlayersPresentation()
{
	//To be removed
	//if (!MatchIntroHUD) return;

}

void AGameHUD::BeginMatchSummary()
{
	//To be removed
	//if (!MatchIntroHUD) return;

}

void AGameHUD::ShowWinner(FString PlayerName, UTextureRenderTarget2D* View)
{
	//To be removed
	//if (!MatchIntroHUD) return;

}

void AGameHUD::PresentPlayers()
{
	//To be removed
	//if (!MatchIntroHUD) return;

	GetWorldTimerManager().SetTimer(DelayTimer, this, &AGameHUD::PresentPlayersName, 1.0f);
}


void AGameHUD::SetPlayersData(FString PlayerOne, FString PlayerTwo)
{
	if (!ensure(MatchHUD != nullptr)) return;
	MatchHUD->SetPlayersName(PlayerOne, PlayerTwo);
}

void AGameHUD::PresentPlayersName()
{
	//To be removed
	//if (!MatchIntroHUD) return;

}

void AGameHUD::ShowMatchHUDAtGameStart()
{
	if (!ensure(MatchHUD != nullptr)) return;
	MatchHUD->ShowAtGameStart();

	if (!ensure(GameHUDWidget != nullptr)) return;
	GameHUDWidget->Show();
}

void AGameHUD::Hide()
{
	if (!ensure(MatchHUD != nullptr)) return;
	MatchHUD->Hide();

	if (!ensure(GameHUDWidget != nullptr)) return;
	GameHUDWidget->Hide();
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


void AGameHUD::SetRoundStartCounter(uint8 Counter)
{
	if (!ensure(GameHUDWidget != nullptr)) return;
	GameHUDWidget->SetRoundStartCounter(Counter);
}