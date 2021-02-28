// Fill out your copyright notice in the Description page of Project Settings.


#include "WinnerPlayerState.h"


AWinnerPlayerState::AWinnerPlayerState()
{
	Winner = false;
}

void AWinnerPlayerState::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AWinnerPlayerState::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AWinnerPlayerState, Winner);
}