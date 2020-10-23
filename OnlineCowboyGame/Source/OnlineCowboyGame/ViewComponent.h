// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "ViewComponent.generated.h"

class UTPPAimingComponent;
class UFPPAimingComponent;
// Manages FPP and TPP view
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UViewComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UViewComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ToggleAimingView();

	void SetAimingView(TEnumAsByte<View> Val);

	TEnumAsByte<View> GetAimingView() { return CurrentView; };

	void SimulateMouseMovement(const FMouseMovement& Move);

	float GetCameraYaw();

	void SetCameraYaw(float Val);

	float GetCameraPitch();

	void SetCameraPitch(float Val);

	TEnumAsByte<View> GetCurrentView(){ return CurrentView; };

protected:

	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<View> CurrentView;

	UPROPERTY()
	UTPPAimingComponent* TPPAimingComponent;

	UPROPERTY()
	UFPPAimingComponent* FPPAimingComponent;

private:
	void FPP_SimulateMouseMovement(const FMouseMovement& Move);

	void TPP_SimulateMouseMovement(const FMouseMovement& Move);

	float FPP_GetCameraYaw();

	float TPP_GetCameraYaw();

	void FPP_SetCameraYaw(float Val);

	void TPP_SetCameraYaw(float Val);

	float FPP_GetCameraPitch();

	float TPP_GetCameraPitch();

	void FPP_SetCameraPitch(float Val);

	void TPP_SetCameraPitch(float Val);

	void ChangeViewToTPP();

	void ChangeViewToFPP();
};
