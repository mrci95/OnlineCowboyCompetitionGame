// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyPlayerState.h"


void ALobbyPlayerState::SetIsReady(bool bIsReady_In)
{
	bIsReady = bIsReady_In;
}
bool ALobbyPlayerState::IsReady()
{
	return bIsReady;
}