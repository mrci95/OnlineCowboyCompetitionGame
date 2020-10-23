// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewComponent.h"
#include "TPPAimingComponent.h"
#include "FPPAimingComponent.h"

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
	FPPAimingComponent = GetOwner()->FindComponentByClass<UFPPAimingComponent>();
}


// Called every frame
void UViewComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//TO DO - no need to tick
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UViewComponent::ToggleAimingView()
{
	if (CurrentView == View::FPP)
	{
		ChangeViewToTPP();
	}
	else
	{
		ChangeViewToFPP();
	}
}

void UViewComponent::SimulateMouseMovement(const FMouseMovement& Move)
{
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
	if (!ensure(FPPAimingComponent != nullptr)) return;

	FPPAimingComponent->SimulateMouseMovement(Move);
}

void UViewComponent::TPP_SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(TPPAimingComponent!= nullptr)) return;

	TPPAimingComponent->SimulateMouseMovement(Move);
}

float UViewComponent::GetCameraYaw()
{
	float Yaw = 0;
	switch (CurrentView)
	{
	case View::FPP:
		Yaw = FPP_GetCameraYaw();
		break;
	case View::TPP:
		Yaw = TPP_GetCameraYaw();
		break;
	default:
		break;
	}

	return Yaw;
}

float UViewComponent::FPP_GetCameraYaw()
{
	if (!ensure(FPPAimingComponent != nullptr)) return 0;

	return FPPAimingComponent->GetCameraYaw();
}

float UViewComponent::TPP_GetCameraYaw()
{
	if (!ensure(TPPAimingComponent != nullptr)) return 0;
	
	return TPPAimingComponent->GetCameraYaw();
}


void UViewComponent::SetCameraYaw(float Val)
{
	switch (CurrentView)
	{
	case View::FPP:
		FPP_SetCameraYaw(Val);
		break;
	case View::TPP:
		TPP_SetCameraYaw(Val);
		break;
	default:
		break;
	}
}

void UViewComponent::FPP_SetCameraYaw(float Val)
{
	if (!ensure(FPPAimingComponent != nullptr)) return;

	FPPAimingComponent->SetCameraYaw(Val);
}

void UViewComponent::TPP_SetCameraYaw(float Val)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetCameraYaw(Val);
}

float UViewComponent::GetCameraPitch()
{
	float CameraPitch = 0;
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
	if (!ensure(FPPAimingComponent != nullptr)) return 0;

	return FPPAimingComponent->GetCameraPitch();
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
	if (!ensure(FPPAimingComponent != nullptr)) return;

	FPPAimingComponent->SetCameraPitch(Val);
}
void UViewComponent::TPP_SetCameraPitch(float Val)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetCameraPitch(Val);
}


void UViewComponent::ChangeViewToTPP()
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	CurrentView = View::TPP;

	TPPAimingComponent->SetViewActive(true);
	FPPAimingComponent->SetViewActive(false);
}

void UViewComponent::ChangeViewToFPP()
{

	if (!ensure(FPPAimingComponent != nullptr)) return;

	CurrentView = View::FPP;

	TPPAimingComponent->SetViewActive(false);
	FPPAimingComponent->SetViewActive(true);

}

void UViewComponent::SetAimingView(TEnumAsByte<View> Val)
{
	switch (Val)
	{
	case View::FPP:
		ChangeViewToFPP();
		break;
	case View::TPP:
		ChangeViewToTPP();
		break;
	default:
		break;
	}

}


