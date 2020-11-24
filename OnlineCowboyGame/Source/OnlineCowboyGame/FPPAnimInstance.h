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

	void MontagePlay_Fire();
};
