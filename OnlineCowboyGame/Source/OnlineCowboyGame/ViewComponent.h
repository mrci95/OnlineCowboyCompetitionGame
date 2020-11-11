// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "ViewComponent.generated.h"

class UTPPAimingComponent;
class UFPPAimingComponent;
class UCameraComponent;
class USkeletalMeshComponent;
class UCowboyAnimInstance;
class AWeaponBase;

// Manages FPP and TPP view
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UViewComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UViewComponent();

	void Setup(APawn* Owner, UTPPAimingComponent* TPPAimingComp, USkeletalMeshComponent* TPPMesh, UFPPAimingComponent* FPPAimingComp, USkeletalMeshComponent* FPPMesh);
	void Setup(AWeaponBase* FPPWeaponArg, AWeaponBase* TPPWeaponArg);

	virtual void InitializeComponent() override;
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

	void TakeGun();

	void GunTaken();

	void OnFire();

	FVector GetBulletHitPoint();

	void Respawn();

protected:

	APawn* Pawn;

	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<View> CurrentView;

	UPROPERTY()
	UTPPAimingComponent* TPPAimingComponent;

	UPROPERTY()
	UFPPAimingComponent* FPPAimingComponent;

	USkeletalMeshComponent* CoboyTppMesh;

	USkeletalMeshComponent* CowboyFppMesh;

	UCowboyAnimInstance* TPPAnimInstance;

	AWeaponBase* FPPWeapon = nullptr;

	AWeaponBase* TPPWeapon = nullptr;

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

	void SetCameraLookAtRotationPreviousView(View oldView);

	FVector FPP_GetBulletHitPoint();

	FVector TPP_GetBulletHitPoint();
};
