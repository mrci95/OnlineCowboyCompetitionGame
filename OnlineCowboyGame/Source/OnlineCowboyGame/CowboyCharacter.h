// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CowboyCharacter.generated.h"


class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ONLINECOWBOYGAME_API ACowboyCharacter : public ACharacter
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

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CoboyMesh;

	UPROPERTY(EditAnywhere)
	USpringArmComponent* TPPCameraRoot;


	UPROPERTY(EditAnywhere)
	UCameraComponent* TPPCamera;
};
