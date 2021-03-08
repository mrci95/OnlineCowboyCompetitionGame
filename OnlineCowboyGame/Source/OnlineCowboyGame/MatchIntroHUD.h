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

	void BeginPresentation();

	void SetPlayersData(FString PlayerOne, FString PlayerTwo);
	
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player1Name;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Player2Name;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* BeginPresentationAnimation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* TeardownAnimation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* Reset;

	UFUNCTION(BlueprintCallable)
	void PresentationDone();

	void TeardownPresentation();

	void ResetWidget();

private:

};
