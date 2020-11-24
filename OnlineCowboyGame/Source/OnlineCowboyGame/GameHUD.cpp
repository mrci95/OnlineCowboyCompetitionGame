// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUD.h"
#include "GameHUDWidget.h"

AGameHUD::AGameHUD()
{
	UE_LOG(LogTemp, Warning, TEXT("AGameHUD::AGameHUD()"));
	ConstructorHelpers::FClassFinder<UGameHUDWidget> WBP_GameHUD_BPClass(TEXT("/Game/Level/WBP_GameHUD"));
	if (!ensure(WBP_GameHUD_BPClass.Class != nullptr)) return;
	UE_LOG(LogTemp, Warning, TEXT("%x"),(void*)WBP_GameHUD_BPClass.Class.Get());
	GameHUDWidgetClass = WBP_GameHUD_BPClass.Class;
}


void AGameHUD::BeginPlay()
{
	Super::BeginPlay();

	CreateGameInterface();
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

void AGameHUD::ToggleAmmoHUD()
{
	if (GameHUDWidget)
	{
		GameHUDWidget->ToggleAmmoHud();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("GameHUDWidget is null"));
	}
}