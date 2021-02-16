// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyPlayerController.h"
#include "OnlineCowboyGameGameModeBase.h"
#include "CowboyCompetitionGameState.h"
#include "GameHUD.h"
#include "CowboyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/PostProcessVolume.h"
#include "UObject/ConstructorHelpers.h"
#include "UObject/UObjectGlobals.h"

ACowboyPlayerController::ACowboyPlayerController()
{

	FString server = HasAuthority() ? "Server" : "Client";
	UE_LOG(LogTemp, Warning, TEXT("%s ACowboyPlayerController()"), *server);
}

void ACowboyPlayerController::BeginPlay()
{

	Super::BeginPlay();

	DisableInput(this);

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(this, APostProcessVolume::StaticClass(), Actors);
	if (Actors.Num() > 0)
	{
		DeathPostProcess = Cast<APostProcessVolume>(Actors[0]);
	}

	if (TimelineCurve)
	{
		FOnTimelineFloat TimelineProgress;
		TimelineProgress.BindUFunction(this, FName("OnTimelineTick"));
		DeathPostprocessTimeline.AddInterpFloat(TimelineCurve, TimelineProgress);
	}
}


void ACowboyPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	DeathPostprocessTimeline.TickTimeline(DeltaTime);
}

void ACowboyPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Reload",IE_Pressed, this, &ACowboyPlayerController::Reload);
	InputComponent->BindAction("Fire", IE_Pressed, this, &ACowboyPlayerController::OnFire);

	InputComponent->BindAxis("LookUp", this, &ACowboyPlayerController::LookUp);
	InputComponent->BindAxis("LookRight", this, &ACowboyPlayerController::LookRight);
	InputComponent->BindAction("Aiming", IE_Pressed, this, &ACowboyPlayerController::ToggleAimingView);
	InputComponent->BindAction("GrabGun", IE_Pressed, this, &ACowboyPlayerController::GrabGun);


	InputComponent->BindAction("DeathCam", IE_Pressed, this, &ACowboyPlayerController::OnPawnDeath);

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

	if(IsLocalController())
		DisableDeathPostProcessWithBlend();
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

void ACowboyPlayerController::Reload()
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		if (Cowboy->CanReload())
		{
			Cowboy->Reload();

			if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
			{
				GameHUD->ReloadStart();
			}
		}

	}
}


void ACowboyPlayerController::ClearCylinder()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->ClearCylinder();
	}
}

void ACowboyPlayerController::InsertingBullet()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->InsertingBullet();
	}
}

void ACowboyPlayerController::BulletInserted()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->BulletInserted();
	}
}

void ACowboyPlayerController::ReloadBreak()
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->ReloadBreak();
	}
}

void ACowboyPlayerController::ReloadEnd()
{
	if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
	{
		GameHUD->ReloadEnd();
	}
}

void ACowboyPlayerController::OnFire()
{
	UE_LOG(LogTemp, Warning, TEXT("PC fire"));
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		if (Cowboy->CanFire())
		{
			Cowboy->OnFire();

			if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
			{
				GameHUD->OnFire();
			}
		}
		else if (Cowboy->IsReloading())
		{
			ReloadBreak();
		}
	}
}


void ACowboyPlayerController::PawnRestarted()
{	
	if (IsLocalController())
	{
		UE_LOG(LogTemp, Warning, TEXT("PawnRestarted()"));
		if (AGameHUD* GameHUD = Cast<AGameHUD>(GetHUD()))
		{
			GameHUD->OnPawnPossessed();
		}
	}
}

void ACowboyPlayerController::LookUp(float Val)
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->LookUp(Val);
	}
}

void ACowboyPlayerController::LookRight(float Val)
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->LookRight(Val);
	}
}

void ACowboyPlayerController::ToggleAimingView()
{

	if (ACowboyCompetitionGameState* GS = GetWorld()->GetGameState<ACowboyCompetitionGameState>())
	{
		bool CanChangeView = GS->GetFPPAvailable();

		if (!CanChangeView) return;

		if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
		{
			Cowboy->ToggleAimingView();
		}
	}

	
}

void ACowboyPlayerController::GrabGun()
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		Cowboy->GrabGun();
	}
}


void ACowboyPlayerController::DisableAndResetInput()
{
	DisableInput(this);
	LookRight(0.f);
	LookUp(0.f);
}

void ACowboyPlayerController::OnPawnDeath()
{
	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(GetPawn()))
	{
		AActor* Target = Cowboy->GetDeathCamTarget();

		if (Target)
		{
			SetViewTargetWithBlend(Target, 1.5f, EViewTargetBlendFunction::VTBlend_Cubic);
		}

		EnableDeathPostProcessWithBlend();
	}
}


void ACowboyPlayerController::OnTimelineTick(float Value)
{
	if (DeathPostProcess)
	{
		UE_LOG(LogTemp, Warning, TEXT("OnTimelineTick %f"), Value);
		DeathPostProcess->BlendWeight = Value;
	}
}

void ACowboyPlayerController::EnableDeathPostProcessWithBlend()
{
	UE_LOG(LogTemp, Warning, TEXT("EnableDeathPostProcessWithBlend"));
	DeathPostprocessTimeline.PlayFromStart();
}

void ACowboyPlayerController::DisableDeathPostProcessWithBlend()
{
	if (DeathPostProcess && DeathPostProcess->BlendWeight > 0.0f)
		DeathPostprocessTimeline.ReverseFromEnd();
}


void ACowboyPlayerController::FPPViewDisabled()
{
	if (ACowboyCharacter* Cowboy = GetPawn<ACowboyCharacter>())
	{
		Cowboy->FPPDisabled();
	}
}
