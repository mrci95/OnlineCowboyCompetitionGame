// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "FPPAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UFPPAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, Category = "Montages")
	UAnimMontage* FireMontage;

	UPROPERTY(EditAnywhere, Category = "Montages")
	UAnimMontage* ReloadMontage;


	void MontagePlay_Fire();
	bool IsMontagePlaying_Fire();

	void MontagePlay_ReloadStart();

	void MontagePlay_ReloadBreak();

	bool IsMontagePlaying_Reload();
};
