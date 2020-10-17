// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CowboyCharacter.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class UCapsuleComponent;

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

private:

	

	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* CapsuleComponent;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CoboyMesh;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* TPPCameraRoot;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* TPPCamera;

	UPROPERTY(EditAnywhere)
	float TPPCameraRangeRadius = 200.0f;

	float TPPCameraLimit;
	FVector TPPConeDirection;

	void IntitiateTPPRangeCone();

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

	//input
	void LookUp(float Val);

	void LookRight(float Val);

	FVector2D MouseMove;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SendMove(FMouseMove Move);

	FMouseMove CreateMove(float DeltaTime);

	void SimulateAiming(FMouseMove LastMove);

	void UpdateServerState();

	UPROPERTY(ReplicatedUsing = OnRep_ServerState)
	FAimingServerState ServerState;


	UFUNCTION()
		void OnRep_ServerState();
};
