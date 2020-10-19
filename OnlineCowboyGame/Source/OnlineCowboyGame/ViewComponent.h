// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CowboyMovement.h"
#include "ViewComponent.generated.h"

UENUM()
enum View
{
	TPP     UMETA(DisplayName = "TPP"),
	FPP     UMETA(DisplayName = "FPP"),
};

class UTPPAimingComponent;
// Manages FPP and TPP view
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ONLINECOWBOYGAME_API UViewComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UViewComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ToggleCurrentView();

	void SimulateMouseMovement(const FMouseMovement& Move);

protected:

	UPROPERTY(VisibleAnywhere)
	TEnumAsByte<View> CurrentView;

	UPROPERTY()
	UTPPAimingComponent* TPPAimingComponent;
private:
	void FPP_SimulateMouseMovement(const FMouseMovement& Move);

	void TPP_SimulateMouseMovement(const FMouseMovement& Move);
};
