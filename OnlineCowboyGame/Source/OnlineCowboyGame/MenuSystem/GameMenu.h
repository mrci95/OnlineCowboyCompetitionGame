// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "GameMenuInterface.h"
#include "GameMenu.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UGameMenu : public UMenuWidget
{
	GENERATED_BODY()
	
public:

	UPROPERTY(meta = (BindWidget))
	class UButton* CancelButton;

	UPROPERTY(meta = (BindWidget))
	class UButton* QuitButton;

protected:

	virtual bool Initialize();

	UFUNCTION()
		void Cancel();

	UFUNCTION()
		void Quit();
};
