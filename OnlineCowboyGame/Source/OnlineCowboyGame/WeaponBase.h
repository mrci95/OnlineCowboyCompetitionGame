// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

class ABulletBase;

UCLASS()
class ONLINECOWBOYGAME_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponBase();

	void SetOnlyOwnerSee(bool Val);

	void SetVisibility(bool Val);

	void SetCastShadow(bool Val);

	void SetCastHiddenShadow(bool Val);

	USkeletalMeshComponent* GetMesh() { return WeaponMesh; };

	void OnFire(FVector HitPoint);

	void MontagePlay_Fire();
	void MontagePlay_ReloadStart();
	void MontagePlay_ReloadBreak();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Setup")
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<ABulletBase> Bullet;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	class UGunAnimInstance* AnimInstance = nullptr;
};
