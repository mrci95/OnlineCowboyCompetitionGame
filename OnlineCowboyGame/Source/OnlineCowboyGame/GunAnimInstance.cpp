// Fill out your copyright notice in the Description page of Project Settings.


#include "GunAnimInstance.h"

void UGunAnimInstance::MontagePlay_Fire()
{
	if (!ensure(FireMontage != nullptr)) return;

	if (Montage_IsPlaying(FireMontage)) return;

	Montage_Play(FireMontage);
}

void UGunAnimInstance::MontagePlay_ReloadStart()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	if (Montage_IsPlaying(ReloadMontage)) return;

	Montage_Play(ReloadMontage);
}

void UGunAnimInstance::MontagePlay_ReloadBreak()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	Montage_JumpToSection(FName("ReloadEnd"), ReloadMontage);
}