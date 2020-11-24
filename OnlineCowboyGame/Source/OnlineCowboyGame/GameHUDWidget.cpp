// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "AmmoHUD.h"



void UGameHUDWidget::ToggleAmmoHud()
{
	if (AmmoHUD)
	{
			AmmoHUD->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AmmoHUD is null"));
	}
}