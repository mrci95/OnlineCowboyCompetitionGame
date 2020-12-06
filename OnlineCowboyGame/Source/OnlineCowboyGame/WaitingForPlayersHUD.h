// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WaitingForPlayersHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UWaitingForPlayersHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeOnInitialized() override;

	void Show();
	void Hide();

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Root;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* ShowAnimation;

};
