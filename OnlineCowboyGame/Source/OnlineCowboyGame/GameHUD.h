// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AGameHUD();

	void ToggleAmmoHUD();

protected:

	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameHUDWidget> GameHUDWidgetClass;
private:

	class UGameHUDWidget* GameHUDWidget;

	void CreateGameInterface();
};
