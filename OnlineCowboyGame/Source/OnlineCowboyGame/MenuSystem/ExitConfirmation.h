// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ExitConfirmation.generated.h"

class IConfirmationInterface;
/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UExitConfirmation : public UUserWidget
{
	GENERATED_BODY()

public:

	void Setup(IConfirmationInterface* Receiver);

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* NoButton;

	UPROPERTY(meta = (BindWidget), BlueprintReadWrite)
	class UButton* YesButton;

protected:

	virtual bool Initialize();

	UFUNCTION()
		void NoAction();

	UFUNCTION()
		void YesAction();

private:

	IConfirmationInterface* ConfirmationInterface = nullptr;
	
};
