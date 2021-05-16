// Fill out your copyright notice in the Description page of Project Settings.

#include "ConfirmationInterface.h"
#include "ExitConfirmation.h"


bool UExitConfirmation::Initialize()
{
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(YesButton != nullptr)) return false;
	if (!ensure(NoButton != nullptr)) return false;

	//buttons callback
	NoButton->OnClicked.AddDynamic(this, &UExitConfirmation::NoAction);
	YesButton->OnClicked.AddDynamic(this, &UExitConfirmation::YesAction);

	return true;
}

void UExitConfirmation::Setup(IConfirmationInterface* Receiver)
{
	ConfirmationInterface = Receiver;
}

void UExitConfirmation::NoAction()
{
	if (ConfirmationInterface)
	{
		ConfirmationInterface->Reject();
	}
}

void UExitConfirmation::YesAction()
{
	if (ConfirmationInterface)
	{
		ConfirmationInterface->Confirm();
	}
}