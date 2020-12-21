
// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyMovement.h"
#include "ViewComponent.h"
#include "CowboyCharacter.h"

// Sets default values for this component's properties
UCowboyMovement::UCowboyMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("UCowboyMovement()"));
}

void UCowboyMovement::Setup(APawn* Owner, UViewComponent* Component)
{
	UE_LOG(LogTemp, Warning, TEXT("UCowboyMovement::Setup"));
	Pawn = Cast<ACowboyCharacter>(Owner);
	ViewComponent = Component;
}


// Called when the game starts
void UCowboyMovement::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("UCowboyMovement::BeginPlay()"));

	Super::BeginPlay();

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
	ViewComponent->TakeGun();
}

bool UCowboyMovement::CanFire()
{
	if (!ensure(ViewComponent != nullptr)) return false;

	return ViewComponent->CanFire() && CurrentAmmo > 0 && !IsReloading();

}

void UCowboyMovement::OnFire()
{
	if (Pawn == nullptr) return;
	if (!ensure(ViewComponent != nullptr)) return;


	CurrentAmmo--;

	ViewComponent->OnFire();
}

FVector UCowboyMovement::GetBulletHitPoint()
{
	if (!ensure(ViewComponent != nullptr)) return FVector::ZeroVector;

	return ViewComponent->GetBulletHitPoint();
}

void UCowboyMovement::Respawn()
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->Respawn();
}


bool UCowboyMovement::CanReload()
{

	if (!ensure(ViewComponent != nullptr)) return false;

	return ViewComponent->CanReload() && !IsReloading();
}

void UCowboyMovement::Reload()
{
	if (!ensure(ViewComponent != nullptr)) return;

	CurrentAmmo = 0;
	Reloading = true;
	ViewComponent->Reload();
}

void UCowboyMovement::BulletInserted()
{
	CurrentAmmo++;
	if (CurrentAmmo == 6)
	{
		if (Pawn)
		{
			Pawn->ReloadBreak();
		}
	}
}

void UCowboyMovement::ReloadBreak()
{
	if (!ensure(ViewComponent != nullptr)) return;

	Reloading = false;

	ViewComponent->ReloadBreak();
}

bool UCowboyMovement::IsReloading()
{
	return Reloading;
}


void UCowboyMovement::Death()
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->Death();
}

void UCowboyMovement::Winner()
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->Winner();
}


void UCowboyMovement::OnHit(FVector HitNormal, FVector Location, FName BoneName)
{
	if (!ensure(ViewComponent != nullptr)) return;

	ViewComponent->OnHit(HitNormal, Location, BoneName);

	Pawn->Death();
}