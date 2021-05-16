// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BulletHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UBulletHUD : public UUserWidget
{
public:

	GENERATED_BODY()

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	void Fired();

	void RemoveBullet();

	void InsertBullet();

	void Reset();

	void Show();


	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* ShowAnimation;

	// We need an Image widget in our Blueprint class named "IconImage"
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* BulletIcon = nullptr;

	// Our base material that will be the template for our material instance
	UPROPERTY(EditDefaultsOnly)
	UMaterialInterface* BulletMaterial = nullptr;

	// Our actual material instance
	UMaterialInstanceDynamic* BulletMaterialInstance = nullptr;
};
