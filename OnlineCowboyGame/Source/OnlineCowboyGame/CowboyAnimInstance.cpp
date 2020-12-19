// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyAnimInstance.h"
#include "ViewComponent.h"
#include "CowboyCharacter.h"

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

bool UCowboyAnimInstance::IsMontagePlaying_FireHip()
{
	if (!ensure(FireHipMontage != nullptr)) return false;

	return Montage_IsPlaying(FireHipMontage);
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

void UCowboyAnimInstance::MontagePlay_ReloadStart()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	if (Montage_IsPlaying(ReloadMontage)) return;

	Montage_Play(ReloadMontage);
}


bool UCowboyAnimInstance::IsMontagePlaying_Reload()
{
	if (!ensure(ReloadMontage != nullptr)) return false;

	return Montage_IsPlaying(ReloadMontage);
}

void UCowboyAnimInstance::MontagePlay_ReloadBreak()
{
	if (!ensure(ReloadMontage != nullptr)) return;

	Montage_JumpToSection(FName("ReloadEnd"), ReloadMontage);
}

void UCowboyAnimInstance::ClearCylinder()
{
	if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(TryGetPawnOwner()))
	{
		Pawn->ClearCylinder();
	}
}


void UCowboyAnimInstance::InsertingBullet()
{
	if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(TryGetPawnOwner()))
	{
		Pawn->InsertingBullet();
	}
}

void UCowboyAnimInstance::BulletInserted()
{
	if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(TryGetPawnOwner()))
	{
		Pawn->BulletInserted();
	}
}

void UCowboyAnimInstance::ReloadEnd()
{
	if (ACowboyCharacter* Pawn = Cast<ACowboyCharacter>(TryGetPawnOwner()))
	{
		Pawn->ReloadEnd();
	}
}
