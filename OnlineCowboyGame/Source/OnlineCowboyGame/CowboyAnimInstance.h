// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CowboyAnimInstance.generated.h"

/**
 * 
 */
class UViewComponent;

UCLASS()
class ONLINECOWBOYGAME_API UCowboyAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Status")
		bool bIsGunTaken = false;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		bool bIsAiming = false;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		float TppAimOffsetYaw = 0.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		float TppAimOffsetPitch = 0.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		float FppAimOffsetYaw = 0.0f;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Status")
		float FppAimOffsetPitch = 0.0f;
		
		UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* TakeGunMontage;

		UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* FireAimingMontage;

		UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* FireHipMontage;

		UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* ReloadMontage;

		void MontagePlay_TakeGun();

		void MontagePlay_FireHip();
		bool IsMontagePlaying_FireHip();

		void MontagePlay_FireAiming();

		void MontagePlay_ReloadStart();
		void MontagePlay_ReloadEnd();

		bool IsMontagePlaying_Reload();

		void SetTppAimOffset(float Yaw, float Pitch);

		void SetFppAimOffset(float Yaw, float Pitch);

		void SetIsAiming(bool Val) { bIsAiming = Val; };

		void Setup(UViewComponent* ViewComponent);

private:
		UFUNCTION(BlueprintCallable)
		void GunTaken();

		UFUNCTION(BlueprintCallable)
		void InsertingBullet();

		UFUNCTION(BlueprintCallable)
		void BulletInserted();

		UFUNCTION(BlueprintCallable)
		void ClearCylinder();

		UFUNCTION(BlueprintCallable)
		void ReloadEnd();

		UViewComponent* ViewComponent;
};


