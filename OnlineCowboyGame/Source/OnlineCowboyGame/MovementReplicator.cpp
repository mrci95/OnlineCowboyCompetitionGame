// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementReplicator.h"
#include "CowboyCharacter.h"
#include "WeaponBase.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMovementReplicator::UMovementReplicator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("UMovementReplicator()"));

	SetIsReplicatedByDefault(true);
	SetIsReplicated(true);
}

// Called when the game starts
void UMovementReplicator::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("UMovementReplicator::BeginPlay()"));
	Pawn = Cast<APawn>(GetOwner());
}

void UMovementReplicator::Setup(UCowboyMovement* Component)
{
	CowboyMovement = Component;

	UE_LOG(LogTemp, Warning, TEXT("UMovementReplicator::Setup"));
}

void UMovementReplicator::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UMovementReplicator, ServerState);
}


// Called every frame
void UMovementReplicator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!ensure(CowboyMovement != nullptr)) return;
	if (Pawn->IsLocallyControlled())
	{

		if (GetOwnerRole() == ROLE_AutonomousProxy)
		{
			Server_SendMove(CowboyMovement->GetLastMouseMovement());
		}
		else
		{
			UpdateServerState();
		}
	}
}

void UMovementReplicator::Server_SendMove_Implementation(FMouseMovement Move)
{
	CowboyMovement->SimulateMouseMovement(Move);

	UpdateServerState();
}

bool UMovementReplicator::Server_SendMove_Validate(FMouseMovement Move)
{
	return true;
}

void UMovementReplicator::UpdateServerState()
{
	if (!ensure(CowboyMovement != nullptr)) return;

	float CameraYaw = CowboyMovement->GetCameraYaw();
	float CameraPitch = CowboyMovement->GetCameraPitch();
	uint8 View = static_cast<uint8>(CowboyMovement->GetAimingView().GetValue());


	ServerState.CameraYaw = CameraYaw;
	ServerState.CameraPitch = CameraPitch;
	ServerState.View = View;
}

void UMovementReplicator::OnRep_ServerState()
{
	if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		if (CowboyMovement == nullptr) return;
		
		CowboyMovement->SetAimingView(ServerState.View==1 ? View::FPP : View::TPP);
		CowboyMovement->SetCameraYaw(ServerState.CameraYaw);
		CowboyMovement->SetCameraPitch(ServerState.CameraPitch);
	}
}

void UMovementReplicator::ToggleAimingView()
{
	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		Server_ToggleAimingView();
	}
}

void UMovementReplicator::Server_ToggleAimingView_Implementation()
{
	if (CowboyMovement == nullptr) return;

	CowboyMovement->ToggleAimingView();

	UpdateServerState();
}

bool UMovementReplicator::Server_ToggleAimingView_Validate()
{
	return true;
}

void UMovementReplicator::TakeGun()
{
	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		Server_TakeGun();
	}
	else
	{
		Multi_TakeGun();
	}
}

void UMovementReplicator::Server_TakeGun_Implementation()
{
	if (CowboyMovement == nullptr) return;

	CowboyMovement->TakeGun();

	Multi_TakeGun();
}
bool UMovementReplicator::Server_TakeGun_Validate()
{
	return true;
}

void UMovementReplicator::Multi_TakeGun_Implementation()
{
	if (Pawn == nullptr) return;

	if (!Pawn->IsLocallyControlled() && GetOwnerRole() == ROLE_SimulatedProxy)
	{
		CowboyMovement->TakeGun();
	}
}

bool UMovementReplicator::Multi_TakeGun_Validate()
{
	return true;
}

void UMovementReplicator::OnFire()
{
	if (CowboyMovement == nullptr) return;

	if (GetOwnerRole() == ROLE_AutonomousProxy)
	{
		Server_OnFire(CowboyMovement->GetBulletHitPoint());
	}
	else
	{
		Multi_OnFire(CowboyMovement->GetBulletHitPoint());
	}
}

void UMovementReplicator::Server_OnFire_Implementation(FVector HitPoint)
{
	if (CowboyMovement == nullptr) return;

	CowboyMovement->OnFire();

	Multi_OnFire(CowboyMovement->GetBulletHitPoint());
}

bool UMovementReplicator::Server_OnFire_Validate(FVector HitPoint)
{
	return true;
}

void UMovementReplicator::Multi_OnFire_Implementation(FVector HitPoint)
{
	if (Pawn == nullptr) return;
	if (CowboyMovement == nullptr) return;

	if (!Pawn->IsLocallyControlled() && GetOwnerRole() == ROLE_SimulatedProxy)
	{
		CowboyMovement->OnFire();
	}
}
bool UMovementReplicator::Multi_OnFire_Validate(FVector HitPoint)
{
	return true;
}

void UMovementReplicator::Respawn()
{

	if (Pawn == nullptr) return;
	if (CowboyMovement == nullptr) return;

	if (Pawn->HasAuthority())
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, TEXT("RESPAWN"));
		}

		UE_LOG(LogTemp, Warning, TEXT("UMovementReplicator::Respawn()"));
		Multi_Respawn();
	}
}

void UMovementReplicator::Multi_Respawn_Implementation()
{
	UE_LOG(LogTemp, Warning, TEXT("UMovementReplicator::Multi_Respawn_Implementation()"));
	if (CowboyMovement == nullptr) return;
	CowboyMovement->Respawn();
}
bool UMovementReplicator::Multi_Respawn_Validate()
{
	return true;
}

void UMovementReplicator::DestroyWeapons()
{
	if (Pawn == nullptr) return;

	if (Pawn->HasAuthority())
	{
		Multi_DestroyWeapons();
	}
}

void UMovementReplicator::Multi_DestroyWeapons_Implementation()
{
	if (Pawn == nullptr) return;

	if (ACowboyCharacter* Cowboy = Cast<ACowboyCharacter>(Pawn))
	{
		Cowboy->GetFPPWeapon()->Destroy();
		Cowboy->GetTPPWeapon()->Destroy();
	}
}
bool UMovementReplicator::Multi_DestroyWeapons_Validate()
{
	return true;
}



