// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConfirmationInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConfirmationInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class ONLINECOWBOYGAME_API IConfirmationInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void Confirm() = 0;
	virtual void Reject() = 0;
};
