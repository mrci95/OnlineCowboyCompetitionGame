// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameHUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UGameHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void ReloadStart();
	void ClearCylinder();
	void InsertingBullet();
	void BulletInserted();
	void ReloadEnd();
	void OnFire();
	void OnPawnPossessed();

protected:


private:

	UPROPERTY(meta = (BindWidget))
	class UAmmoHUD* AmmoHUD;

	
};
