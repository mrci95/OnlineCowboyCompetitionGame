// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "TPPAimingComponent.generated.h"

class USceneComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UTPPAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTPPAimingComponent();

	void Setup(USceneComponent* Gimbal, USpringArmComponent* CameraRoot, UCameraComponent* Camera);

	FString OwnerRoleString();

	UPROPERTY()
	USceneComponent* TPPAimuthGimbal;

	UPROPERTY()
	USpringArmComponent* TPPCameraRoot;

	UPROPERTY()
	UCameraComponent* TPPCamera;

	UPROPERTY(EditAnywhere)
	float TPPCameraRangeRadius = 200.0f;

	UPROPERTY(EditAnywhere)
	float TPPCameraPitchLimit = 89.0f;

	UPROPERTY(EditAnywhere)
	float TPPCameraYawLimit = 89.0f;

	float TPPCameraLimit;
	FVector TPPConeDirection;

	void IntitiateRangeCone();

	//View debug section
	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppRangeCone = true;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeDirectionLine = false;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppRandomInitialCameraViewLine = false;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeRadiusLine = false;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeLimitEdgeLine = false;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppCurrentCameraViewLine = true;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SetViewActive(bool Activate);

	void SimulateMouseMovement(const FMouseMovement& Move);

	UCameraComponent* GetCamera() { return TPPCamera; } ;

	float GetCameraYaw();

	void SetCameraYaw(float Val);

	float GetCameraPitch();

	void SetCameraPitch(float Val);

	void SetCameraLookAtPoint(FVector PointInWorld);

	void GetAimingOffset(float& Yaw, float& Pitch);
};
