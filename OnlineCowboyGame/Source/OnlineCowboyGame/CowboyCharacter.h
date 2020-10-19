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

USTRUCT()
struct FMouseMove
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		FVector2D Move;
	UPROPERTY()
		float DeltaTime;
};

USTRUCT()
struct FAimingServerState
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
		FTransform Transform;

};

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
	UStaticMeshComponent* CoboyMesh;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* TPPAimuthGimbal;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* TPPCameraRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* TPPCamera;

	UCowboyMovement* CowboyMovement;

	UTPPAimingComponent* TppAimingComponent;

private:



	//Input binding
	void LookUp(float Val);

	void LookRight(float Val);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SendMove(FMouseMove Move);

	void UpdateServerState();

	UPROPERTY(ReplicatedUsing = OnRep_ServerState)
	FAimingServerState ServerState;


	UFUNCTION()
	void OnRep_ServerState();
};
