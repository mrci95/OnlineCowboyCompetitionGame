// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GunAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UGunAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
	public:

	void MontagePlay_Fire();
	void MontagePlay_ReloadStart();
	void MontagePlay_ReloadBreak();

	protected:

	UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* FireMontage;

	UPROPERTY(EditAnywhere, Category = "Montages")
		UAnimMontage* ReloadMontage;


};
