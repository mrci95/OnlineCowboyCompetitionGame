// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UServerRow : public UUserWidget
{
	GENERATED_BODY()
	

public:



	void Setup(class UMainMenu* InParent, uint32 InIndex);

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ServerName;

	UPROPERTY(meta = (BindWidget))
	class UButton* ServerRowButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* HostUsername;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ConnectionInfo;

	UPROPERTY(BlueprintReadOnly)
	bool Selected;



private:

	UFUNCTION()
	void OnClicked();

	virtual bool Initialize();

	UPROPERTY()
	class UMainMenu* Parent;
	
	uint32 Index;

};
