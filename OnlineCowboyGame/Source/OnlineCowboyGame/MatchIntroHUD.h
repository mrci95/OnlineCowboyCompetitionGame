// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchIntroHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UMatchIntroHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeOnInitialized() override;

	void BeginWaitingForPlayers();

	void StopWaitingForPlayers();

	void PresentPlayers();

	void PresentPlayersName();

	void EndPlayersPresentation();

	void SetPlayersName(FString PlayerOne, FString PlayerTwo);


	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(meta = (BindWidget))
	class UWaitingForPlayersHUD* WaitingForPlayers;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player1Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player2Name;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Player1Show;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Player2Show;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* PlayersNamePresentation;
	
	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* EndPresentation;

private:

};
