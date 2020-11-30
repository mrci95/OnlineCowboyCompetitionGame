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

	void DestroyWeapons();

	virtual void Restart() override;

	UPROPERTY(VisibleAnywhere)
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

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AWeaponBase> Weapon;

	UPROPERTY()
	AWeaponBase* FPPWeapon = nullptr;

	UPROPERTY()
	AWeaponBase* TPPWeapon = nullptr;

	bool CanFire();
	void OnFire();
	void Fired();

	bool CanReload();
	void Reload();
	void ReloadEnd();
	bool IsReloading();
	void BulletInserted();

protected:
	void OnStartingGame();

private:
	FTimerHandle RespawnTimer;
	void OnRespawnTimerExpiration();

	UFUNCTION()
	void OnCowobyHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	//Input binding
	void LookUp(float Val);

	void LookRight(float Val);

	void ToggleAimingView();

	void GrabGun();


	FString RoleString();

	void Respawn();

	uint16 CurrentAmmo = 6;
	bool Reloading = false;


};
