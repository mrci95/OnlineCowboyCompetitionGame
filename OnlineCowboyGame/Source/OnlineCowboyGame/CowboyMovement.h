// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.generated.h"


class UViewComponent;

USTRUCT()
struct FMouseMovement
{
	GENERATED_USTRUCT_BODY()

	//Mouse coordinates
	UPROPERTY()
	FVector2D MouseMoveVector;

	UPROPERTY()
	float DeltaTime;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UCowboyMovement : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCowboyMovement();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//Set Mouse Move
	void SetMouseMoveX(float Val) { MouseMoveVector.X = Val; };

	void SetMouseMoveY(float Val) { MouseMoveVector.Y = Val; };

private:

	APawn* Pawn;

	UViewComponent* ViewComponent;

	//Mouse input from Player Controller
	FVector2D MouseMoveVector;

	//Last simulated move
	FMouseMovement LastMouseMovement;

	//METHODS
	FMouseMovement CreateMouseMovement(float DeltaTime);

	
};
