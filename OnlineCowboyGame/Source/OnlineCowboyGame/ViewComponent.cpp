// Fill out your copyright notice in the Description page of Project Settings.


#include "ViewComponent.h"
#include "CowboyCharacter.h"
#include "TPPAimingComponent.h"
#include "FPPAimingComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "CowboyAnimInstance.h"
#include "WeaponBase.h"

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

	UE_LOG(LogTemp, Warning, TEXT("UViewComponent::BeginPlay()"));
	CurrentView = View::TPP;


	Pawn = Cast<APawn>(GetOwner());
	TPPAimingComponent = GetOwner()->FindComponentByClass<UTPPAimingComponent>();
	FPPAimingComponent = GetOwner()->FindComponentByClass<UFPPAimingComponent>();
	CoboyTppMesh = Cast<USkeletalMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("CowboyTPPMesh")));

	CowboyFppMesh = Cast<USkeletalMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("CowboyFPPMesh")));

	if (!ensure(CoboyTppMesh != nullptr)) return;

	TPPAnimInstance = Cast<UCowboyAnimInstance>(CoboyTppMesh->GetAnimInstance());
	TPPAnimInstance->Setup(this);
}


// Called every frame
void UViewComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//TO DO - no need to tick
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}



void UViewComponent::Setup(AWeaponBase* FPPWeaponArg, AWeaponBase* TPPWeaponArg)
{
	FPPWeapon = FPPWeaponArg;
	TPPWeapon = TPPWeaponArg;

	UE_LOG(LogTemp, Warning, TEXT("UViewComponent::Setup, FPP %p, TPP %p"), (void*)FPPWeapon, (void*)TPPWeapon);
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

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	FPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetFppAimOffset(Yaw, Pitch);

}

void UViewComponent::TPP_SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(TPPAimingComponent!= nullptr)) return;

	TPPAimingComponent->SimulateMouseMovement(Move);

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	TPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetTppAimOffset(Yaw, Pitch);
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

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	FPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetFppAimOffset(Yaw, Pitch);

}

void UViewComponent::TPP_SetCameraYaw(float Val)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetCameraYaw(Val);

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	TPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetTppAimOffset(Yaw, Pitch);
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

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	FPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetFppAimOffset(Yaw, Pitch);

}
void UViewComponent::TPP_SetCameraPitch(float Val)
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	TPPAimingComponent->SetCameraPitch(Val);

	if (!ensure(TPPAnimInstance != nullptr)) return;

	float Yaw;
	float Pitch;
	TPPAimingComponent->GetAimingOffset(Yaw, Pitch);

	TPPAnimInstance->SetTppAimOffset(Yaw, Pitch);
}


void UViewComponent::ChangeViewToTPP()
{
	if (!ensure(TPPAimingComponent != nullptr)) return;

	CurrentView = View::TPP;

	TPPAimingComponent->SetViewActive(true);
	FPPAimingComponent->SetViewActive(false);

	//SetCameraLookAtRotationPreviousView(View::FPP);

	if (Pawn->IsLocallyControlled())
	{
		CoboyTppMesh->SetVisibility(true);
		TPPWeapon->SetVisibility(true);

		FPPWeapon->SetVisibility(false);
		CowboyFppMesh->SetVisibility(false);

	}

	if (!ensure(TPPAnimInstance != nullptr)) return;
	TPPAnimInstance->SetIsAiming(false);

}

void UViewComponent::ChangeViewToFPP()
{
	if (!ensure(FPPAimingComponent != nullptr)) return;

	CurrentView = View::FPP;

	TPPAimingComponent->SetViewActive(false);
	FPPAimingComponent->SetViewActive(true);

	//SetCameraLookAtRotationPreviousView(View::TPP);

	if (Pawn->IsLocallyControlled())
	{
		CoboyTppMesh->SetVisibility(false);
		TPPWeapon->SetVisibility(false);

		FPPWeapon->SetVisibility(true);
		CowboyFppMesh->SetVisibility(true);
	}

	if (!ensure(TPPAnimInstance != nullptr)) return;
	TPPAnimInstance->SetIsAiming(true);
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

void UViewComponent::SetCameraLookAtRotationPreviousView(View PreviousView)
{
	FHitResult OutHit;
	FCollisionQueryParams CollisionParams;
	CollisionParams.AddIgnoredComponent(CoboyTppMesh);

	FVector PreviousViewCameraWorldLocation = PreviousView == View::FPP ? FPPAimingComponent->GetCamera()->GetComponentLocation() : TPPAimingComponent->GetCamera()->GetComponentLocation();
	FVector PreviousViewCameraForwardVector = PreviousView == View::FPP ? FPPAimingComponent->GetCamera()->GetForwardVector() : TPPAimingComponent->GetCamera()->GetForwardVector();

	FVector LookAtPoint = PreviousViewCameraWorldLocation + PreviousViewCameraForwardVector.GetSafeNormal() * 1500.f;

	if (Pawn->GetWorld()->LineTraceSingleByChannel(OutHit, PreviousViewCameraWorldLocation, LookAtPoint, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			LookAtPoint = OutHit.Location;
		}
	}

	if (CurrentView == View::FPP)
	{
		FPPAimingComponent->SetCameraLookAtPoint(LookAtPoint);
	}
	else
	{
		TPPAimingComponent->SetCameraLookAtPoint(LookAtPoint);
	}
}

void UViewComponent::TakeGun()
{
	TPPAnimInstance->MontagePlay_TakeGun();
}

void UViewComponent::GunTaken()
{
	UE_LOG(LogTemp, Warning, TEXT("UViewComponent::Setup, FPP %p, TPP %p"), (void*)FPPWeapon, (void*)TPPWeapon);

	if (!ensure(TPPWeapon != nullptr)) return;
	if (!ensure(CoboyTppMesh != nullptr)) return;

	TPPWeapon->AttachToComponent(CoboyTppMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("GunHand"));
}


