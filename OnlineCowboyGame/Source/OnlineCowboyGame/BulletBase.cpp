// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletBase.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABulletBase::ABulletBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	SetRootComponent(SphereCollider);

	BulletMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletMesh"));
	BulletMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	BulletMesh->SetRelativeLocation(FVector(0, 0, 0));

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));

	SphereCollider->OnComponentHit.AddDynamic(this, &ABulletBase::OnHit);
}

// Called when the game starts or when spawned
void ABulletBase::BeginPlay()
{
	Super::BeginPlay();
	
	SetLifeSpan(10.0f);

}

// Called every frame
void ABulletBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABulletBase::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor && HitComp && OtherComp)
	{
		UE_LOG(LogTemp, Warning, TEXT("Bullet hit event, HitComp %s, OtherActor %s,  OtherComp %s, bone: %s "), *HitComp->GetName(), *OtherActor->GetName(), *OtherComp->GetName(), *Hit.BoneName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("Bullet hit event, bullet owner hex %x "), (void*)GetInstigator());
	}
	Destroy();
}

