// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewComponent.h"
#include "TPPAimingComponent.h"

// Sets default values for this component's properties
UViewComponent::UViewComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UViewComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentView = View::TPP;

	TPPAimingComponent = GetOwner()->FindComponentByClass<UTPPAimingComponent>();

}


// Called every frame
void UViewComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//TO DO - no need to tick
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UViewComponent::ToggleCurrentView()
{
	if (CurrentView == View::FPP)
	{
		CurrentView = View::TPP;
	}
	else
	{
		CurrentView = View::FPP;
	}
}

void UViewComponent::SimulateMouseMovement(const FMouseMovement& Move)
{
	//UE_LOG(LogTemp, Warning, TEXT("UViewComponent Move: %s, DeltaTime: %d"), *Move.MouseMoveVector.ToString(), Move.DeltaTime);

	switch (CurrentView)
	{
		case View::FPP:
			FPP_SimulateMouseMovement(Move);
			break;
		case View::TPP:
			TPP_SimulateMouseMovement(Move);
			break;
		default:
			break;
	}
}

void UViewComponent::FPP_SimulateMouseMovement(const FMouseMovement& Move)
{

}

void UViewComponent::TPP_SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(TPPAimingComponent!= nullptr)) return;

	TPPAimingComponent->SimulateMouseMovement(Move);
}

FTransform UViewComponent::GetAzimuthGizmoTransform()
{
	FTransform AzimuthGizmo;
	switch (CurrentView)
	{
	case View::FPP:
		AzimuthGizmo = FPP_GetAzimuthGizmoTransform();
		break;
	case View::TPP:
		AzimuthGizmo = TPP_GetAzimuthGizmoTransform();
		break;
	default:
		break;
	}

	return AzimuthGizmo;
}

FTransform UViewComponent::FPP_GetAzimuthGizmoTransform()
{
	FTransform AzimuthGizmo;
	return AzimuthGizmo;
}

FTransform UViewComponent::TPP_GetAzimuthGizmoTransform()
{
	FTransform AzimuthGizmo;
	if (!ensure(TPPAimingComponent != nullptr)) return AzimuthGizmo;
	
	AzimuthGizmo = TPPAimingComponent->GetAzimuthGizmoTransform();
	return AzimuthGizmo;
}


void UViewComponent::SetAzimuthGizmoTransform(FTransform Transform)
{
	switch (CurrentView)
	{
	case View::FPP:
		FPP_SetAzimuthGizmoTransform(Transform);
		break;
	case View::TPP:
		TPP_SetAzimuthGizmoTransform(Transform);
		break;
	default:
		break;
	}
}

void UViewComponent::FPP_SetAzimuthGizmoTransform(FTransform Transform)
{

}

void UViewComponent::TPP_SetAzimuthGizmoTransform(FTransform Transform)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetAzimuthGizmoTransform(Transform);
}

float UViewComponent::GetCameraPitch()
{
	float CameraPitch;
	switch (CurrentView)
	{
	case View::FPP:
		CameraPitch = FPP_GetCameraPitch();
		break;
	case View::TPP:
		CameraPitch = TPP_GetCameraPitch();
		break;
	default:
		break;
	}

	return CameraPitch;
}

float UViewComponent::FPP_GetCameraPitch()
{
	return 0;
}
float UViewComponent::TPP_GetCameraPitch()
{
	if (!ensure(TPPAimingComponent != nullptr)) return 0;

	return TPPAimingComponent->GetCameraPitch();
}

void UViewComponent::SetCameraPitch(float Val)
{
	switch (CurrentView)
	{
	case View::FPP:
		FPP_SetCameraPitch(Val);
		break;
	case View::TPP:
		TPP_SetCameraPitch(Val);
		break;
	default:
		break;
	}
}


void UViewComponent::FPP_SetCameraPitch(float Val)
{

}
void UViewComponent::TPP_SetCameraPitch(float Val)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetCameraPitch(Val);
}


