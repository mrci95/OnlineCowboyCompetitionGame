// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/RandomStream.h"
#include "Math/Quat.h"
#include "CowboyMovement.h"
#include "ViewComponent.h"
#include "MovementReplicator.h"

#include "WeaponBase.h"
#include "DrawDebugHelpers.h"

// Sets default values
ACowboyCharacter::ACowboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;


	bReplicates = true;
	bAlwaysRelevant = true;
	SetReplicateMovement(false);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);

	CoboyTppMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CowboyTPPMesh"));
	CoboyTppMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CoboyTppMesh->SetRelativeLocation(FVector(0, 0, 0));
	
	TPPAimuthGimbal = CreateDefaultSubobject<USceneComponent>(TEXT("TPPAimuthGimbal"));
	TPPAimuthGimbal->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TPPAimuthGimbal->SetRelativeLocation(FVector(0, 340, 30));

	TPPCameraRoot = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPCameraRoot"));
	TPPCameraRoot->AttachToComponent(TPPAimuthGimbal, FAttachmentTransformRules::KeepRelativeTransform);
	TPPCameraRoot->TargetArmLength = 300.0f;
	TPPCameraRoot->SetRelativeLocation(FVector(0, 0, 0));

	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPCameraRoot, USpringArmComponent::SocketName);

	FPPAimuthGimbal = CreateDefaultSubobject<USceneComponent>(TEXT("FPPAimuthGimbal"));
	FPPAimuthGimbal->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	FPPAimuthGimbal->SetRelativeLocation(FVector(0, 0, 60));

	FPPCameraRoot = CreateDefaultSubobject<USpringArmComponent>(TEXT("FPPCameraRoot"));
	FPPCameraRoot->AttachToComponent(FPPAimuthGimbal, FAttachmentTransformRules::KeepRelativeTransform);
	FPPCameraRoot->TargetArmLength = 0.0f;
	FPPCameraRoot->SetRelativeLocation(FVector(0, 0, 0));

	FPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FPPCamera"));
	FPPCamera->SetupAttachment(FPPCameraRoot, USpringArmComponent::SocketName);
	FPPCamera->SetAutoActivate(false);

	CowboyFppMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CowboyFPPMesh"));
	CowboyFppMesh->AttachToComponent(FPPCameraRoot, FAttachmentTransformRules::KeepRelativeTransform);
	CowboyFppMesh->SetRelativeLocation(FVector(0, 0, 0));

	CowboyMovementComponent = CreateDefaultSubobject< UCowboyMovement>(TEXT("CowboyMovementComponent"));
}

// Called when the game starts or when spawned
void ACowboyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ACowboyCharacter::BeginPlay()"));
	DrawDebugString(GetWorld(), FVector(0, 0, 150), RoleString(), this, FColor::Black);

	CowboyFppMesh->SetVisibility(false);
	CowboyMovementReplicator = FindComponentByClass<UMovementReplicator>();
	ViewComponent = FindComponentByClass<UViewComponent>();

	if (!ensure(Weapon!= nullptr)) return;
	FPPWeapon = GetWorld()->SpawnActor<AWeaponBase>(Weapon.Get(), GetTransform());
	FPPWeapon->SetOwner(this);
	FPPWeapon->AttachToComponent(CowboyFppMesh, FAttachmentTransformRules::SnapToTargetIncludingScale,FName("Gun"));
	FPPWeapon->SetOnlyOwnerSee(true);
	FPPWeapon->SetVisibility(false);
	FPPWeapon->SetCastShadow(false);

	TPPWeapon = GetWorld()->SpawnActor<AWeaponBase>(Weapon.Get(), GetTransform());
	TPPWeapon->SetOwner(this);
	TPPWeapon->AttachToComponent(CoboyTppMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("GunLeg"));
	TPPWeapon->SetCastHiddenShadow(true);

	if (!ensure(ViewComponent != nullptr)) return;
	ViewComponent->Setup(FPPWeapon, TPPWeapon);
}

// Called every frame
void ACowboyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACowboyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookUp", this, &ACowboyCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ACowboyCharacter::LookRight);
	PlayerInputComponent->BindAction("Aiming",IE_Pressed, this, &ACowboyCharacter::ToggleAimingView);
	PlayerInputComponent->BindAction("GrabGun", IE_Pressed, this, &ACowboyCharacter::GrabGun);
}


void ACowboyCharacter::LookUp(float Val)
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;

	CowboyMovementComponent->SetMouseMoveY(Val);
}

void ACowboyCharacter::LookRight(float Val)
{

	if (!ensure(CowboyMovementComponent != nullptr)) return;

	CowboyMovementComponent->SetMouseMoveX(Val);
}

void ACowboyCharacter::ToggleAimingView()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->ToggleAimingView();
	CowboyMovementReplicator->ToggleAimingView();
}

void ACowboyCharacter::GrabGun()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->TakeGun();
	CowboyMovementReplicator->TakeGun();
}


FString ACowboyCharacter::RoleString()
{
	switch (GetLocalRole())
	{
	case ROLE_Authority:
		return "ROLE_Authority";
		break;
	case ROLE_AutonomousProxy:
		return "ROLE_AutonomousProxy";
		break;
	case ROLE_SimulatedProxy:
		return "ROLE_SimulatedProxy";
		break;
	default:
		return "error";
		break;
	}
}
