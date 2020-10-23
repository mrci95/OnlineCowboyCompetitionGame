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

	FString OwnerRoleString();

	USceneComponent* TPPAimuthGimbal;

	USpringArmComponent* TPPCameraRoot;

	UCameraComponent* TPPCamera;

	UPROPERTY(EditAnywhere)
	float TPPCameraRangeRadius = 200.0f;

	float TPPCameraLimit;
	FVector TPPConeDirection;

	void IntitiateRangeCone();

	//View debug section
	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppRangeCone = true;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeDirectionLine = true;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppRandomInitialCameraViewLine = true;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeRadiusLine = true;

	UPROPERTY(EditAnywhere, Category = "Draw debug")
		bool DrawTppConeLimitEdgeLine = true;

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

	float GetCameraYaw();

	void SetCameraYaw(float Val);

	float GetCameraPitch();

	void SetCameraPitch(float Val);
};
