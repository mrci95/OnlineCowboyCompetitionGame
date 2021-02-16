// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCharacter.h"
#include "CowboyPlayerController.h"

//Legacy components
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/StaticMeshActor.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Engine/TextureRenderTarget2D.h"

//Helpers
#include "DrawDebugHelpers.h"
#include "Math/RandomStream.h"
#include "Math/Quat.h"
#include "TimerManager.h"

//Custom components
#include "TPPAimingComponent.h"
#include "FPPAimingComponent.h"
#include "CowboyMovement.h"
#include "ViewComponent.h"
#include "MovementReplicator.h"

#include "WeaponBase.h"
#include "CowboyPlayerState.h"
#include "CowboyCompetitionGameState.h"

// Sets default values
ACowboyCharacter::ACowboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("ACowboyCharacter()"));

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

	//Setup TPP Aiming Comp
	TPPAimingComponent = CreateDefaultSubobject< UTPPAimingComponent>(TEXT("CowboyTPPAimingComponent"));
	if (TPPAimingComponent != nullptr)
		TPPAimingComponent->Setup(TPPAimuthGimbal, TPPCameraRoot, TPPCamera);

	//Setup FPP Aiming Comp
	FPPAimingComponent = CreateDefaultSubobject<UFPPAimingComponent>(TEXT("CowboyFPPAimingComponent"));
	if(FPPAimingComponent != nullptr)
		FPPAimingComponent->Setup(FPPAimuthGimbal, FPPCameraRoot, FPPCamera);

	//Setup View Comp
	ViewComponent = CreateDefaultSubobject<UViewComponent>(TEXT("CowboyViewComponent"));
	if (ViewComponent != nullptr)
		ViewComponent->Setup(this, TPPAimingComponent, CoboyTppMesh, FPPAimingComponent, CowboyFppMesh);

	CowboyMovementComponent = CreateDefaultSubobject< UCowboyMovement>(TEXT("CowboyMovementComponent"));
	CowboyMovementComponent->Setup(this, ViewComponent);

	CowboyMovementReplicator = CreateDefaultSubobject< UMovementReplicator>(TEXT("CowboyMovementReplicator"));
	CowboyMovementReplicator->Setup(CowboyMovementComponent);

	CoboyTppMesh->OnComponentHit.AddDynamic(this, &ACowboyCharacter::OnCowobyHit);

	//Setup SceneCaptureComponent2D for match intro/outro preview
	MatchIntroView = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("MatchIntroView"));
	MatchIntroView->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	MatchIntroView->SetRelativeLocation(FVector(90, -141, 55));
	MatchIntroView->SetRelativeRotation(FRotator(0, 97, 0));
	MatchIntroView->FOVAngle = 60;
	MatchIntroView->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_RenderScenePrimitives;
	MatchIntroView->CaptureSource = ESceneCaptureSource::SCS_SceneColorHDR;
	MatchIntroView->MaxViewDistanceOverride = 400.f;
	MatchIntroView->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ACowboyCharacter::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("ACowboyCharacter::BeginPlay()"));

	CowboyFppMesh->SetVisibility(false);

	if (!ensure(Weapon!= nullptr)) return;
	FPPWeapon = GetWorld()->SpawnActor<AWeaponBase>(Weapon.Get(), GetTransform());
	FPPWeapon->SetOwner(this);
	FPPWeapon->AttachToComponent(CowboyFppMesh, FAttachmentTransformRules::SnapToTargetIncludingScale,FName("Gun"));
	FPPWeapon->SetOnlyOwnerSee(true);
	FPPWeapon->SetVisibility(false);
	FPPWeapon->SetCastShadow(false);

	TPPWeapon = GetWorld()->SpawnActor<AWeaponBase>(Weapon.Get(), GetTransform());
	TPPWeapon->SetOwner(this);
	TPPWeapon->AttachToComponent(CoboyTppMesh, FAttachmentTransformRules::SnapToTargetIncludingScale, FName("GunSocket_Holder"));
	TPPWeapon->SetCastHiddenShadow(true);

	if (!ensure(DeathCamActor != nullptr)) return;
	DeathCamTarget = GetWorld()->SpawnActor<AActor>(DeathCamActor.Get(), GetTransform());
	DeathCamTarget->SetOwner(this);
	DeathCamTarget->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	DeathCamTarget->SetActorRelativeLocation(FVector(328.67f, 167.13, 94.81));
	DeathCamTarget->SetActorRelativeRotation(FRotator(-12.80, 205.99, 0));
	DeathCamTarget->SetActorHiddenInGame(true);

	if (!ensure(ViewComponent != nullptr)) return;
	ViewComponent->Setup(FPPWeapon, TPPWeapon);

	UWorld* World = GetWorld();
	if (World)
	{
		if (ACowboyCompetitionGameState* GS = World->GetGameState<ACowboyCompetitionGameState>())
		{
			GS->Subscribe(this);
		}
	}

	MatchIntroViewRenderTarget2D = NewObject<UTextureRenderTarget2D>();
	
	// Setting parameters and size
	MatchIntroViewRenderTarget2D->ClearColor = FLinearColor::White;
	MatchIntroViewRenderTarget2D->InitAutoFormat(1920, 1080);

	// Setting the new target
	MatchIntroView->TextureTarget = MatchIntroViewRenderTarget2D;

	if (ACowboyPlayerState* PS = GetPlayerState<ACowboyPlayerState>())
	{
		FString User = HasAuthority() ? "Server" : "Client";
		UE_LOG(LogTemp, Warning, TEXT("%s PS found"), *User);


		PS->SetMatchIntroView(MatchIntroViewRenderTarget2D);
	}
	else
	{
		FString User = HasAuthority() ? "Server" : "Client";
		UE_LOG(LogTemp, Warning, TEXT("%s PS not found"), *User);
	}
}

// Called every frame
void ACowboyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (ACowboyPlayerState* PS = GetPlayerState<ACowboyPlayerState>())
	{
		uint16 RoundsWon = PS->GetRoundsWon();
		FString Name = PS->GetPlayerName();
		//DrawDebugString(GetWorld(), FVector(0, 0, 100), FString::Printf(TEXT("RoundsWon %d"), RoundsWon), this, FColor::Black, 0.1f);
		//DrawDebugString(GetWorld(), FVector(0, 0, 150), FString::Printf(TEXT("%s"), *Name), this, FColor::Black, 0.1f);

	}

		UWorld* World = GetWorld();
		if (World)
		{
			if (ACowboyCompetitionGameState* GS = World->GetGameState<ACowboyCompetitionGameState>())
			{
				FString CurrentStateString = GS->GetGameState() == EGameState::WAITING_FOR_PLAYERS ? "Waiting for players..." : "Starting";
				//DrawDebugString(GetWorld(), FVector(750, 0, 100), CurrentStateString, this, FColor::Black, 0.1f);
			}
		}

}

// Called to bind functionality to input
void ACowboyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



void ACowboyCharacter::Restart()
{
	Super::Restart();

	if (IsLocallyControlled())
	{
		if (ACowboyPlayerController* PC = GetController<ACowboyPlayerController>())
		{
			PC->PawnRestarted();
		}
	}
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

bool ACowboyCharacter::CanFire()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return false;
	return CowboyMovementComponent->CanFire();
}

void ACowboyCharacter::OnFire()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->OnFire();
	CowboyMovementReplicator->OnFire();
}


bool ACowboyCharacter::CanReload()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return false;
	return CowboyMovementComponent->CanReload();
}

void ACowboyCharacter::Reload()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->Reload();
	CowboyMovementReplicator->Reload();
}

void ACowboyCharacter::ClearCylinder()
{
	if (ACowboyPlayerController* PC = GetController< ACowboyPlayerController>())
	{
		PC->ClearCylinder();
	}
}

void ACowboyCharacter::InsertingBullet()
{
	if (ACowboyPlayerController* PC = GetController< ACowboyPlayerController>())
	{
		PC->InsertingBullet();
	}
}

void ACowboyCharacter::ReloadBreak()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->ReloadBreak();
	CowboyMovementReplicator->ReloadBreak();
}

void ACowboyCharacter::ReloadEnd()
{
	if (ACowboyPlayerController* PC = GetController<ACowboyPlayerController>())
	{
		PC->ReloadEnd();
	}
}

bool ACowboyCharacter::IsReloading()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return true;
	return CowboyMovementComponent->IsReloading();
}

void ACowboyCharacter::BulletInserted()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;
	if (!ensure(CowboyMovementReplicator != nullptr)) return;

	CowboyMovementComponent->BulletInserted();

	if (ACowboyPlayerController* PC = GetController<ACowboyPlayerController>())
	{
		PC->BulletInserted();
	}
}

void ACowboyCharacter::OnCowobyHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

	if (OtherActor && HitComp && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Character hit event, HitComp %s, OtherActor %s, OtherComp %s, Bone %s"), *HitComp->GetName(), *OtherActor->GetName(), *OtherComp->GetName(), *Hit.BoneName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Bullet owner hex: %x"),(void*)OtherActor->GetInstigator());

		//Hit detected by actor with authority
		if (HasAuthority())
		{

			UWorld* World = GetWorld();
			ACowboyCompetitionGameState* GS = World->GetGameState<ACowboyCompetitionGameState>();

			if (World == nullptr) return;
			if (GS == nullptr) return;

			if (GS->GetGameState() != EGameState::ROUND_PENDING) return;

			//Enable ragdoll on self and all simulated proxies
			CowboyMovementReplicator->OnHit(Hit.Normal * 5000, Hit.Location, Hit.BoneName);		
			
			//Mark shooter as a winner of this round
			if (APawn* Winner = OtherActor->GetInstigator())
			{
				if (ACowboyPlayerState* PSWinner = Winner->GetPlayerState<ACowboyPlayerState>())
				{
					PSWinner->RoundWin();
				}
			}

			//Request round over in game state
			GS->SetGameState(EGameState::ROUND_OVER);
		}

		// VFX - blood particle



	}
}

void ACowboyCharacter::OnStartingGame()
{

}

void ACowboyCharacter::OnRoundStarted()
{
	
}

void ACowboyCharacter::DestroyWeapons()
{
	CowboyMovementReplicator->DestroyWeapons();
}

void ACowboyCharacter::Winner()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;

	CowboyMovementComponent->Winner();
}


void ACowboyCharacter::Death()
{
	if (IsLocallyControlled())
	{
		if (ACowboyPlayerController* PC = GetController<ACowboyPlayerController>())
		{
			PC->OnPawnDeath();

			if (!ensure(CowboyMovementComponent != nullptr)) return;

			CowboyMovementComponent->Death();
		}
	}
}

void ACowboyCharacter::FPPDisabled()
{
	if (!ensure(CowboyMovementComponent != nullptr)) return;

	View AimingView = CowboyMovementComponent->GetAimingView();

	if (AimingView == View::FPP)
	{
		ToggleAimingView();
	}
}