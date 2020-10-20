// Fill out your copyright notice in the Description page of Project Settings.


#include "MovementReplicator.h"
#include "Net/UnrealNetwork.h"

// Sets default values for this component's properties
UMovementReplicator::UMovementReplicator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	SetIsReplicatedByDefault(true);
	
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

	FTransform AzimuthGizmo = CowboyMovement->GetAzimuthGizmoTransform();
	float CameraPitch = CowboyMovement->GetCameraPitch();

	ServerState.AimuthGizmo = AzimuthGizmo;
	ServerState.CameraPitch = CameraPitch;
}

void UMovementReplicator::OnRep_ServerState()
{
	if (GetOwnerRole() == ROLE_SimulatedProxy)
	{
		if (!ensure(CowboyMovement != nullptr)) return;
			
		CowboyMovement->SetAzimuthGizmoTransform(ServerState.AimuthGizmo);
		CowboyMovement->SetCameraPitch(ServerState.CameraPitch);
	}
}

