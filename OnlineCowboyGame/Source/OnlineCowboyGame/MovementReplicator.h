// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "MovementReplicator.generated.h"



USTRUCT()
struct FAimingServerState
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY()
		float CameraYaw;

		UPROPERTY()
		float CameraPitch;

		UPROPERTY()
		uint8 View;

};



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UMovementReplicator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMovementReplicator();

	void ToggleAimingView();
	void TakeGun();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	APawn* Pawn;

	UCowboyMovement* CowboyMovement;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_SendMove(FMouseMovement Move);

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_ToggleAimingView();

	UFUNCTION(Server, Reliable, WithValidation)
	void Server_TakeGun();
	void Server_TakeGun_Implementation();
	bool Server_TakeGun_Validate();

	UFUNCTION(NetMulticast, Reliable, WithValidation)
	void Multi_TakeGun();
	void Multi_TakeGun_Implementation();
	bool Multi_TakeGun_Validate();

	void UpdateServerState();


	UPROPERTY(ReplicatedUsing = OnRep_ServerState)
	FAimingServerState ServerState;

	UFUNCTION()
	void OnRep_ServerState();

};
