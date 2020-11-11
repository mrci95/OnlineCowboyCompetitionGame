// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "FPPAimingComponent.generated.h"

class USceneComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UFPPAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFPPAimingComponent();

	void Setup(USceneComponent* Gimbal, USpringArmComponent* CameraRoot, UCameraComponent* Camera);


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	USceneComponent* FPPAimuthGimbal;

	USpringArmComponent* FPPCameraRoot;

	UCameraComponent* FPPCamera;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SimulateMouseMovement(const FMouseMovement& Move);

	void SetViewActive(bool Activate);

	UCameraComponent* GetCamera() { return FPPCamera; };

	float GetCameraYaw();

	void SetCameraYaw(float Val);

	float GetCameraPitch();

	void SetCameraPitch(float Val);

	void SetCameraLookAtPoint(FVector PointInWorld);

	void GetAimingOffset(float& Yaw, float& Pitch);

};
