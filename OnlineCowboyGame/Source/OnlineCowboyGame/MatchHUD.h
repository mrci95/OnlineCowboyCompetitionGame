// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UMatchHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerScore_1;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerScore_2;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CurrentRound;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Show;

	void ShowAtGameStart();

	void SetPlayerOneScore(uint16 Score);
	void SetPlayerTwoScore(uint16 Score);

	void SetCurrentRound(uint8 Round);
};
