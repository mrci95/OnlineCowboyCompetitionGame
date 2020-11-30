// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPAnimInstance.h"

void UFPPAnimInstance::MontagePlay_Fire()
{
	if (!ensure(FireMontage != nullptr)) return;

	if (Montage_IsPlaying(FireMontage)) return;

	Montage_Play(FireMontage);
}


bool UFPPAnimInstance::IsMontagePlaying_Fire()
{
	if (!ensure(FireMontage != nullptr)) return false;

	return Montage_IsPlaying(FireMontage);
}

void UFPPAnimInstance::MontagePlay_ReloadStart()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	if (Montage_IsPlaying(ReloadMontage)) return;

	Montage_Play(ReloadMontage);
}

void UFPPAnimInstance::MontagePlay_ReloadEnd()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	Montage_JumpToSection(FName("ReloadEnd"), ReloadMontage);
}

bool UFPPAnimInstance::IsMontagePlaying_Reload()
{
	if (!ensure(ReloadMontage != nullptr)) return false;

	return Montage_IsPlaying(ReloadMontage);
}