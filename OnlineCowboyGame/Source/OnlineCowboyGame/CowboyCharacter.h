// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CowboyCharacter.generated.h"

class UStaticMeshComponent;
class UCapsuleComponent;

class UCowboyMovement;
class UViewComponent;
class UTPPAimingComponent;
class USpringArmComponent;
class UCameraComponent;
class USceneComponent;
class UMovementReplicator;


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


	UPROPERTY(BlueprintReadOnly)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CoboyTppMesh;

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

private:

	//Input binding
	void LookUp(float Val);

	void LookRight(float Val);

	void ToggleAimingView();

	FString RoleString();
};
