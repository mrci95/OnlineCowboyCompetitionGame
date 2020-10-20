// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Math/RandomStream.h"
#include "Math/Quat.h"
#include "CowboyMovement.h"
#include "ViewComponent.h"
#include "TPPAimingComponent.h"

// Sets default values
ACowboyCharacter::ACowboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;


	bReplicates = true;
	SetReplicateMovement(false);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);

	CoboyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CowboyTPPMesh"));
	CoboyMesh->SetRelativeLocation(FVector(0, 0, 0));
	CoboyMesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	
	TPPAimuthGimbal = CreateDefaultSubobject<USceneComponent>(TEXT("TPPAimuthGimbal"));
	TPPAimuthGimbal->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TPPAimuthGimbal->SetRelativeLocation(FVector(0, 340, 30));


	TPPCameraRoot = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPCameraRoot"));
	TPPCameraRoot->AttachToComponent(TPPAimuthGimbal, FAttachmentTransformRules::KeepRelativeTransform);
	TPPCameraRoot->TargetArmLength = 300.0f;
	TPPCameraRoot->SetRelativeLocation(FVector(0, 0, 0));

	// Create a camera and attach to our spring arm
	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPCameraRoot, USpringArmComponent::SocketName);


}

// Called when the game starts or when spawned
void ACowboyCharacter::BeginPlay()
{
	Super::BeginPlay();

	CowboyMovement = FindComponentByClass<UCowboyMovement>();
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
}


void ACowboyCharacter::LookUp(float Val)
{
	if (!ensure(CowboyMovement != nullptr)) return;

	CowboyMovement->SetMouseMoveY(Val);
}

void ACowboyCharacter::LookRight(float Val)
{

	if (!ensure(CowboyMovement != nullptr)) return;

	CowboyMovement->SetMouseMoveX(Val);
}



