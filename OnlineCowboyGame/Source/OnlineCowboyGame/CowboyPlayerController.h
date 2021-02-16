// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Components/TimelineComponent.h"
#include "CowboyPlayerController.generated.h"

class APostProcessVolume;
class UTimelineComponent;
class UCurveFloat;
/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API ACowboyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACowboyPlayerController();

	virtual void BeginPlay() override;

	virtual void PlayerTick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupInputComponent() override;

	void RequestRespawn();

	void PawnRestarted();

	void ClearCylinder();
	void InsertingBullet();
	void BulletInserted();
	void ReloadBreak();
	void ReloadEnd();
	void DisableAndResetInput();


	void OnPawnDeath();

	/** Function which gets called from the Timeline on a Tick */
	UFUNCTION()
	void OnTimelineTick(float Value);

	//DEBUG
	void FPPViewDisabled();

protected:

	//Death post process enabler timeline


	/** Timeline for the effectprogress*/
	FTimeline DeathPostprocessTimeline;

	UPROPERTY(EditAnywhere, Category = "Timeline")
	UCurveFloat* TimelineCurve;


private:

	//Input binding
	void Reload();
	void OnFire();
	void LookUp(float Val);

	void LookRight(float Val);

	void ToggleAimingView();

	void GrabGun();

	void RequestRespawnFromGM();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_RequestRespawn();
	void Server_RequestRespawn_Implementation();
	bool Server_RequestRespawn_Validate();

	APostProcessVolume* DeathPostProcess;
	void EnableDeathPostProcessWithBlend();
	void DisableDeathPostProcessWithBlend();
};
