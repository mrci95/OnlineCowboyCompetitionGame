// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AmmoHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UAmmoHUD : public UUserWidget
{
	GENERATED_BODY()
	
public:

	virtual void NativeOnInitialized() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float DeltaTime) override;


	void Fire();
	void StartReload();
	void ClearCylinder();
	void InsertingBullet();
	void BulletInserted();
	void ReloadEnd();
	void Reset();
	void Show();
	void Hide();

	UPROPERTY(meta = (BindWidget))
	class UCanvasPanel* Root;

	UPROPERTY(meta = (BindWidget))
	class UBulletHUD* Bullet1;

	UPROPERTY(meta = (BindWidget))
	class UBulletHUD* Bullet2;

	UPROPERTY(meta = (BindWidget))
	class UBulletHUD* Bullet3;

	UPROPERTY(meta = (BindWidget))
	class UBulletHUD* Bullet4;

	UPROPERTY(meta = (BindWidget))
	class UBulletHUD* Bullet5;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* FireAnimation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* ReloadStart;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* InjectBullet;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* ReloadEndAnimation;

	UPROPERTY(meta = (BindWidgetAnim))
	class UWidgetAnimation* ShowAnimation;
	


private:

	uint16 CurrentAmmo = 5;
	uint16 CurrentCylinderIndex = 0;
	float CurrentCylinderAngle = 0;

	bool ResetCylinderAngle = false;
	float TargetCylinderAngle = 0;

	TArray<class UBulletHUD*> Bullets;

	FTimerHandle DelayTimer1;
	FTimerHandle DelayTimer2;
};
