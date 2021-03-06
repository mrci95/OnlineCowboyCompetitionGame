// Fill out your copyright notice in the Description page of Project Settings.


#include "WaitingForPlayersHUD.h"
#include "Components/CanvasPanel.h"

void UWaitingForPlayersHUD::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UWaitingForPlayersHUD::Show()
{
	PlayAnimationForward(ShowAnimation);
}
void UWaitingForPlayersHUD::Hide()
{
	PlayAnimationReverse(ShowAnimation);
}