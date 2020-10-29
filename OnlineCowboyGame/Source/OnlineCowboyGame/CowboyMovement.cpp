// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyMovement.h"
#include "ViewComponent.h"

// Sets default values for this component's properties
UCowboyMovement::UCowboyMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UCowboyMovement::BeginPlay()
{
	Super::BeginPlay();

	Pawn = Cast<APawn>(GetOwner());

	ViewComponent = GetOwner()->FindComponentByClass<UViewComponent>();

	CurrentCowboyState = CowboyState::Idle;
}


// Called every frame
void UCowboyMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!ensure(Pawn != nullptr)) return;
	if (Pawn->IsLocallyControlled())
	{
		LastMouseMovement = CreateMouseMovement(DeltaTime);

		SimulateMouseMovement(LastMouseMovement);
	}
}

void UCowboyMovement::SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->SimulateMouseMovement(Move);
}

FMouseMovement UCowboyMovement::CreateMouseMovement(float DeltaTime)
{

	FMouseMovement Movement;
	Movement.MouseMoveVector = MouseMoveVector;
	Movement.DeltaTime = DeltaTime;

	return Movement;
}

float UCowboyMovement::GetCameraYaw()
{
	if (!ensure(ViewComponent != nullptr)) return 0;

	return ViewComponent->GetCameraYaw();
}

void UCowboyMovement::SetCameraYaw(float Val)
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->SetCameraYaw(Val);
}

float UCowboyMovement::GetCameraPitch()
{
	if (!ensure(ViewComponent != nullptr)) return 0;

	return ViewComponent->GetCameraPitch();
}
void UCowboyMovement::SetCameraPitch(float Val)
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->SetCameraPitch(Val);
}

void UCowboyMovement::ToggleAimingView()
{
	if (!ensure(ViewComponent != nullptr)) return;

	if (CurrentCowboyState == CowboyState::Idle) return;

	ViewComponent->ToggleAimingView();
}

void UCowboyMovement::SetAimingView(TEnumAsByte<View> Val)
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->SetAimingView(Val);
}


TEnumAsByte<View> UCowboyMovement::GetAimingView()
{
	if (!ensure(ViewComponent != nullptr)) return View::TPP;

	return ViewComponent->GetAimingView();
}

void UCowboyMovement::TakeGun()
{
	if (!ensure(ViewComponent != nullptr)) return;

	if (CurrentCowboyState.GetValue() != CowboyState::Idle) return;

	CurrentCowboyState = CowboyState::TakingGun;
	return ViewComponent->TakeGun();
}

