// Fill out your copyright notice in the Description page of Project Settings.


#include "GameHUDWidget.h"
#include "AmmoHUD.h"


void UGameHUDWidget::ReloadStart()
{
	if (AmmoHUD)
	{
		AmmoHUD->StartReload();
	}
}

void UGameHUDWidget::ClearCylinder()
{
	if (AmmoHUD)
	{
		AmmoHUD->ClearCylinder();
	}
}

void UGameHUDWidget::InsertingBullet()
{
	if (AmmoHUD)
	{
		AmmoHUD->InsertingBullet();
	}
}

void UGameHUDWidget::BulletInserted()
{
	if (AmmoHUD)
	{
		AmmoHUD->BulletInserted();
	}
}

void UGameHUDWidget::ReloadEnd()
{
	if (AmmoHUD)
	{
		AmmoHUD->ReloadEnd();
	}
}

void UGameHUDWidget::OnFire()
{
	if (AmmoHUD)
	{
		AmmoHUD->Fire();
	}
}

void UGameHUDWidget::OnPawnPossessed()
{
	if (AmmoHUD)
	{
		AmmoHUD->Reset();
	}
}
