// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 * 

 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMenuChangeDelegate);

UCLASS()
class ONLINECOWBOYGAME_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable)
	FMenuChangeDelegate OnMenuChange;

	void MenuChange();
};
