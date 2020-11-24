// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPAnimInstance.h"

void UFPPAnimInstance::MontagePlay_Fire()
{
	if (!ensure(FireMontage != nullptr)) return;

	if (Montage_IsPlaying(FireMontage)) return;

	Montage_Play(FireMontage);
}