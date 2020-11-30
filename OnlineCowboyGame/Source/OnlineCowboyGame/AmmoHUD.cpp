// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoHUD.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "BulletHUD.h"


void UAmmoHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (!Bullet1) return;
	if (!Bullet2) return;
	if (!Bullet3) return;
	if (!Bullet4) return;
	if (!Bullet5) return;
	if (!Bullet6) return;

	Bullets.Add(Bullet1);
	Bullets.Add(Bullet2);
	Bullets.Add(Bullet3);
	Bullets.Add(Bullet4);
	Bullets.Add(Bullet5);
	Bullets.Add(Bullet6);
}

void UAmmoHUD::NativeTick(const FGeometry& MyGeometry, float DeltaTime)
{
	Super::NativeTick(MyGeometry, DeltaTime);

	if (ResetCylinderAngle)
	{
		//float NewAngle = FMath::FInterpTo(CurrentCylinderAngle, TargetCylinderAngle, DeltaTime, 2.0f);
		float NewAngle = FMath::FInterpConstantTo(CurrentCylinderAngle, TargetCylinderAngle, DeltaTime, 1000.0f);

		UE_LOG(LogTemp, Warning, TEXT("ResetCylinderAngle current angle %f, target %f, new %f"), CurrentCylinderAngle, TargetCylinderAngle, NewAngle);

		if (NewAngle == 0)
		{
			ResetCylinderAngle = false;
			CurrentCylinderIndex = 0;
		}
		CurrentCylinderAngle = NewAngle;
		Root->SetRenderTransformAngle(NewAngle);
	}
}

void UAmmoHUD::Fire()
{
	if (CurrentAmmo <= 0) return;

	PlayAnimation(FireAnimation);

	CurrentCylinderAngle += 60;
	CurrentAmmo--;

	Bullets[CurrentCylinderIndex]->Fired();

	CurrentCylinderIndex++;
}

void UAmmoHUD::StartReload()
{
	PlayAnimation(ReloadStart);
}

void UAmmoHUD::ClearCylinder()
{
	for (UBulletHUD* Bullet : Bullets)
	{
		Bullet->RemoveBullet();
	}
	CurrentAmmo = 0;
}

void UAmmoHUD::InsertingBullet()
{
	PlayAnimation(InjectBullet);
}

void UAmmoHUD::BulletInserted()
{
	UE_LOG(LogTemp, Warning, TEXT("UAmmoHUD::BulletInserted() %d"), CurrentAmmo);
	Bullets[CurrentAmmo]->InsertBullet();
	CurrentAmmo++;
}

void UAmmoHUD::ReloadEnd()
{
	PlayAnimation(ReloadEndAnimation);
	ResetCylinderAngle = true;
	UE_LOG(LogTemp, Warning, TEXT("UAmmoHUD::BulletInserted() current angle %d"), CurrentCylinderAngle);
	TargetCylinderAngle = 0;
}

void UAmmoHUD::Reset()
{
	CurrentAmmo = 6;

	for (UBulletHUD* Bullet : Bullets)
	{
		Bullet->Reset();
	}
	CurrentCylinderIndex = 0;
	ResetCylinderAngle = false;
	Root->SetRenderTransformAngle(0);
}