// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MatchIntroHUD.generated.h"

class UTextureRenderTarget2D;
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

	void BeginMatchSummary();

	void ShowWinner(FString PlayerName, UTextureRenderTarget2D* View );

	void SetPlayersData(FString PlayerOne, FString PlayerTwo, UTextureRenderTarget2D* PlayerOneView, UTextureRenderTarget2D* PlayerTwoView);


	virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation) override;

	UPROPERTY(meta = (BindWidget))
	class UWaitingForPlayersHUD* WaitingForPlayers;
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player1Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player2Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* WinnerName;

	UPROPERTY(meta = (BindWidget))
	class UCowboyRenderTargetHUD* WBP_Player1Image;

	UPROPERTY(meta = (BindWidget))
	class UCowboyRenderTargetHUD* WBP_Player2Image;

	UPROPERTY(meta = (BindWidget))
	class UCowboyRenderTargetHUD* WBP_WinnerView;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Player1Show;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Player2Show;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* PlayersNamePresentation;
	
	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* EndPresentation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* WinnerAnimation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* BeginMatchOutro;

private:

};
