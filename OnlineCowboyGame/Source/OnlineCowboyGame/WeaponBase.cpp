// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponBase.h"
#include "BulletBase.h"
#include "Components/SkeletalMeshComponent.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	SetRootComponent(WeaponMesh);
}

// Called when the game starts or when spawned
void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::SetOnlyOwnerSee(bool Val)
{
	if (!ensure(WeaponMesh != nullptr)) return;
	WeaponMesh->SetOnlyOwnerSee(Val);
}

void AWeaponBase::SetVisibility(bool Val)
{
	if (!ensure(WeaponMesh != nullptr)) return;
	WeaponMesh->SetVisibility(Val);
}

void AWeaponBase::SetCastShadow(bool Val)
{
	if (!ensure(WeaponMesh != nullptr)) return;
	WeaponMesh->SetCastShadow(Val);
}


void AWeaponBase::SetCastHiddenShadow(bool Val)
{
	if (!ensure(WeaponMesh != nullptr)) return;
	WeaponMesh->bCastHiddenShadow = Val;
}

void AWeaponBase::OnFire(FVector HitPoint)
{
	UE_LOG(LogTemp, Warning, TEXT("AWeaponBase::OnFire, GunOwner %x"), (void*)GetOwner());

	if (!ensure(WeaponMesh != nullptr)) return;

	FVector BulletSpawnLoc = WeaponMesh->GetSocketLocation(FName("BulletSpawn"));
	FRotator BulletSpawnDir = UKismetMathLibrary::FindLookAtRotation(BulletSpawnLoc, HitPoint);

	if (!ensure(Bullet != nullptr)) return;

	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.Instigator = Cast<APawn>(GetOwner());
	ABulletBase* BulletActor = GetWorld()->SpawnActor<ABulletBase>(Bullet.Get(), BulletSpawnLoc, BulletSpawnDir, SpawnParameters);
}
