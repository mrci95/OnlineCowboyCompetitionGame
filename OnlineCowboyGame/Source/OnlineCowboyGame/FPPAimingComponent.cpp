// Fill out your copyright notice in the Description page of Project Settings.


#include "FPPAimingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values for this component's properties
UFPPAimingComponent::UFPPAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UFPPAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	FPPAimuthGimbal = Cast<USceneComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("FPPAimuthGimbal")));

	FPPCameraRoot = Cast<USpringArmComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("FPPCameraRoot")));

	FPPCamera = Cast<UCameraComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("FPPCamera")));
	
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


