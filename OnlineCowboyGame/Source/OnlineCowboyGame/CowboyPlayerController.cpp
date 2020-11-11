// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPlayerController.h"
#include "OnlineCowboyGameGameModeBase.h"

ACowboyPlayerController::ACowboyPlayerController()
{

}

void ACowboyPlayerController::RequestRespawn()
{
	if (HasAuthority())
	{
		UE_LOG(LogTemp, Warning, TEXT("Server: ACowboyPlayerController::RequestRespawn() - request respawn on GM"));
		RequestRespawnFromGM();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Client: ACowboyPlayerController::RequestRespawn() - send request to the server in order to request respawn on GM"));
		Server_RequestRespawn();
	}
}

void ACowboyPlayerController::RequestRespawnFromGM()
{
	if (UWorld* World = GetWorld())
	{
		if (AOnlineCowboyGameGameModeBase* GM = World->GetAuthGameMode<AOnlineCowboyGameGameModeBase>())
		{
			GM->RespawnPawn(this);
		}
	}
}

void ACowboyPlayerController::Server_RequestRespawn_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("Server: ACowboyPlayerController::Server_RequestRespawn_Implementation() - respawn request came from client. Call GM"));
	RequestRespawnFromGM();
}
bool ACowboyPlayerController::Server_RequestRespawn_Validate()
{
	return true;
}