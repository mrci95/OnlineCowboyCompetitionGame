// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletHUD.h"
#include "Components/Image.h"
#include "Materials/MaterialInstanceDynamic.h"

void UBulletHUD::NativeConstruct()
{
	Super::NativeConstruct();

	// Create dynamic material instance, based on parent
	BulletMaterialInstance = UMaterialInstanceDynamic::Create(BulletMaterial, this);

	BulletMaterialInstance->SetScalarParameterValue("Desaturation", 0.0f);
	BulletIcon->SetBrushFromMaterial(BulletMaterialInstance);
}

void UBulletHUD::Fired()
{
	BulletIcon->SetVisibility(ESlateVisibility::Hidden);
}
void UBulletHUD::RemoveBullet()
{
	BulletIcon->SetVisibility(ESlateVisibility::Hidden);
}

void UBulletHUD::InsertBullet()
{
	BulletIcon->SetVisibility(ESlateVisibility::Visible);
}


void UBulletHUD::Reset()
{
	BulletIcon->SetVisibility(ESlateVisibility::Visible);
}