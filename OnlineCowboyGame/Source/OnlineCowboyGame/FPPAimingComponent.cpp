// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPAimingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UFPPAimingComponent::UFPPAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("UFPPAimingComponent()"));
}

void UFPPAimingComponent::Setup(USceneComponent* Gimbal, USpringArmComponent* CameraRoot, UCameraComponent* Camera)
{
	FPPAimuthGimbal = Gimbal;
	FPPCameraRoot = CameraRoot;
	FPPCamera = Camera;


	UE_LOG(LogTemp, Warning, TEXT("UFPPAimingComponent::Setup"));
}

// Called when the game starts
void UFPPAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("UFPPAimingComponent::BeginPlay()"));
}


// Called every frame
void UFPPAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

//DO NOT CHANGEEE!!!!!! SUPER SIMPLE METHOD :)
void UFPPAimingComponent::SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(FPPAimuthGimbal != nullptr)) return;
	if (!ensure(FPPCameraRoot != nullptr)) return;


	FRotator NewYaw = FPPAimuthGimbal->GetRelativeRotation();
	NewYaw.Yaw = FMath::Clamp<float>(NewYaw.Yaw + Move.MouseMoveVector.X, -89.f, 89.f);
	FPPAimuthGimbal->SetRelativeRotation(NewYaw);

	FRotator NewPitch = FPPCameraRoot->GetRelativeRotation();
	NewPitch.Pitch = FMath::Clamp<float>(NewPitch.Pitch + Move.MouseMoveVector.Y, -89.f, 89.f);
	FPPCameraRoot->SetRelativeRotation(NewPitch);
}

void UFPPAimingComponent::SetViewActive(bool Activate)
{
	if (!ensure(FPPCamera != nullptr)) return;

	FPPCamera->SetActive(Activate);
}

float UFPPAimingComponent::GetCameraYaw()
{
	if (!ensure(FPPAimuthGimbal != nullptr)) return 0;

	return FPPAimuthGimbal->GetRelativeRotation().Yaw;
}

void UFPPAimingComponent::SetCameraYaw(float Val)
{
	if (!ensure(FPPAimuthGimbal != nullptr)) return;

	FRotator NewYaw = FPPAimuthGimbal->GetRelativeRotation();
	NewYaw.Yaw = FMath::Clamp<float>(Val, -89.f, 89.f);
	FPPAimuthGimbal->SetRelativeRotation(NewYaw);
}

float UFPPAimingComponent::GetCameraPitch()
{
	if (!ensure(FPPCameraRoot != nullptr)) return 0;

	return FPPCameraRoot->GetRelativeRotation().Pitch;
}
void UFPPAimingComponent::SetCameraPitch(float Val)
{
	if (!ensure(FPPCameraRoot != nullptr)) return;

	FRotator NewPitch = FPPCameraRoot->GetRelativeRotation();
	NewPitch.Pitch = FMath::Clamp<float>(Val, -89.f, 89.f);
	FPPCameraRoot->SetRelativeRotation(NewPitch);
}


void UFPPAimingComponent::SetCameraLookAtPoint(FVector PointInWorld)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(FPPAimuthGimbal->GetComponentLocation(), PointInWorld);

	FPPAimuthGimbal->SetRelativeRotation(FRotator(0, 0, 0));
	FPPCameraRoot->SetRelativeRotation(FRotator(0, 0, 0));
	FPPAimuthGimbal->SetWorldRotation(LookAtRotation);
}

void UFPPAimingComponent::GetAimingOffset(float& Yaw, float& Pitch)
{
	FVector CowboyDirection = GetOwner()->GetActorForwardVector();
	
	Pitch = FPPCameraRoot->GetRelativeRotation().Pitch;
	Yaw = FPPAimuthGimbal->GetRelativeRotation().Yaw;
}


