// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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

UCLASS()
class ONLINECOWBOYGAME_API ACowboyCharacter : public APawn
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

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* CoboyTppMesh;

	UPROPERTY(EditAnywhere)
	USkeletalMeshComponent* CowboyFppMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* TPPAimuthGimbal;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* TPPCameraRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* TPPCamera;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* FPPAimuthGimbal;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* FPPCameraRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPPCamera;

	UPROPERTY(VisibleAnywhere)
	UCowboyMovement* CowboyMovementComponent;

	UMovementReplicator* CowboyMovementReplicator;

	UViewComponent* ViewComponent;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AWeaponBase> Weapon;

	UPROPERTY()
	AWeaponBase* FPPWeapon = nullptr;

	UPROPERTY()
	AWeaponBase* TPPWeapon = nullptr;


private:

	//Input binding
	void LookUp(float Val);

	void LookRight(float Val);

	void ToggleAimingView();

	void GrabGun();

	FString RoleString();
};
