// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameStateInterface.h"
#include "CowboyCharacter.generated.h"

class USkeletalMeshComponent;
class UCapsuleComponent;

class UCowboyMovement;
class UViewComponent;
class UTPPAimingComponent;
class USpringArmComponent;
class UCameraComponent;
class USceneComponent;
class UMovementReplicator;
class AWeaponBase;
class UTPPAimingComponent;
class UFPPAimingComponent;
class AStaticMeshActor;
class USceneCaptureComponent2D;
class UTextureRenderTarget2D;

UCLASS()
class ONLINECOWBOYGAME_API ACowboyCharacter : public APawn, public IGameStateInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACowboyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	AWeaponBase* GetFPPWeapon() { return FPPWeapon; };

	AWeaponBase* GetTPPWeapon() { return TPPWeapon; }; 

	AActor* GetDeathCamTarget() { return DeathCamTarget; };

	UTextureRenderTarget2D* GetMatchIntroView() { return MatchIntroViewRenderTarget2D; };

	void DestroyWeapons();

	virtual void Restart() override;

	//Input binding
	void LookUp(float Val);

	void LookRight(float Val);

	void ToggleAimingView();

	void GrabGun();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* CoboyTppMesh;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* CowboyFppMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* TPPAimuthGimbal;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	USpringArmComponent* TPPCameraRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UCameraComponent* TPPCamera;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* FPPAimuthGimbal;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* FPPCameraRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPPCamera;

	UPROPERTY(VisibleAnywhere)
	UCowboyMovement* CowboyMovementComponent;

	UPROPERTY(VisibleAnywhere)
	UMovementReplicator* CowboyMovementReplicator;

	UPROPERTY(VisibleAnywhere)
	UViewComponent* ViewComponent;

	UPROPERTY(VisibleAnywhere)
	UTPPAimingComponent* TPPAimingComponent;

	UPROPERTY(VisibleAnywhere)
	UFPPAimingComponent* FPPAimingComponent;

	UPROPERTY(VisibleAnywhere)
	USceneCaptureComponent2D* MatchIntroView;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AWeaponBase> Weapon;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AActor> DeathCamActor;

	UPROPERTY()
	AWeaponBase* FPPWeapon = nullptr;

	UPROPERTY()
	AWeaponBase* TPPWeapon = nullptr;

	bool CanFire();
	void OnFire();
	void Fired();

	bool CanReload();
	bool IsReloading();

	void Reload();
	void ReloadBreak();

	void ClearCylinder();
	void InsertingBullet();
	void BulletInserted();
	void ReloadEnd();

	void Winner();
	void Death();

protected:
	void OnStartingGame();
	void OnRoundStarted();

private:

	UFUNCTION()
	void OnCowobyHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	FString RoleString();

	UPROPERTY()
	AActor* DeathCamTarget = nullptr;

	UPROPERTY()
	UTextureRenderTarget2D* MatchIntroViewRenderTarget2D = nullptr;
};
