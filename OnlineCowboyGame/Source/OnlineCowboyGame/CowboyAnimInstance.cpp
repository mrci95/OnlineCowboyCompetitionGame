// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyAnimInstance.h"
#include "ViewComponent.h"

void UCowboyAnimInstance::MontagePlay_TakeGun()
{
	if (!ensure(TakeGunMontage != nullptr)) return;

	if (Montage_IsPlaying(TakeGunMontage) || bIsGunTaken) return;

	Montage_Play(TakeGunMontage);
}

void UCowboyAnimInstance::MontagePlay_FireHip()
{
	if (!ensure(FireHipMontage != nullptr)) return;

	if (Montage_IsPlaying(FireHipMontage)) return;

	Montage_Play(FireHipMontage);
}

void UCowboyAnimInstance::MontagePlay_FireAiming()
{
	if (!ensure(FireAimingMontage != nullptr)) return;

	if (Montage_IsPlaying(FireAimingMontage)) return;

	Montage_Play(FireAimingMontage);
}

void UCowboyAnimInstance::SetTppAimOffset(float Yaw, float Pitch)
{
	TppAimOffsetYaw = Yaw;
	TppAimOffsetPitch = Pitch;
}

void UCowboyAnimInstance::SetFppAimOffset(float Yaw, float Pitch)
{
	FppAimOffsetYaw = Yaw;
	FppAimOffsetPitch = Pitch;
}


void UCowboyAnimInstance::Setup(UViewComponent* ViewComponentArg)
{
	ViewComponent = ViewComponentArg;
}

void UCowboyAnimInstance::GunTaken()
{
	bIsGunTaken = true;
	ViewComponent->GunTaken();
}