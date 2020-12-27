// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LobbyConnectedPlayerRow.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ULobbyConnectedPlayerRow : public UUserWidget
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* PlayerName;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ReadyText;
};
