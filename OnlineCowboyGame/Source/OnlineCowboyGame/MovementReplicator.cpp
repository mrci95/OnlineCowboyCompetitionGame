// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementReplicator.h"
#include "Net/UnrealNetwork.h"
#include "DrawDebugHelpers.h"

// Sets default values for this component's properties
UMovementReplicator::UMovementReplicator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicatedByDefault(true);
	SetIsReplicated(true);
}


// Called when the game starts
void UMovementReplicator::BeginPlay()
{
	Super::BeginPlay();

	Pawn = Cast<APawn>(GetOwner());
	CowboyMovement = GetOwner()->FindComponentByClass<UCowboyMovement>();
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
		if (!ensure(CowboyMovement != nullptr)) return;
		
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
	CowboyMovement->TakeGun();

	Multi_TakeGun();
}
bool UMovementReplicator::Server_TakeGun_Validate()
{
	return true;
}

void UMovementReplicator::Multi_TakeGun_Implementation()
{

	if (!Pawn->IsLocallyControlled())
	{
		CowboyMovement->TakeGun();
	}
}

bool UMovementReplicator::Multi_TakeGun_Validate()
{
	return true;
}


