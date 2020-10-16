// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCharacter.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Math/RandomStream.h"

// Sets default values
ACowboyCharacter::ACowboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Remove not needed parent components
	GetMesh()->DestroyComponent();
	GetMesh()->SetActive(false);

	GetArrowComponent()->DestroyComponent();
	GetArrowComponent()->SetActive(false);

	GetMovementComponent()->DestroyComponent();
	GetMovementComponent()->SetActive(false);

	CoboyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CowboyTPPMesh"));
	CoboyMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	
	TPPCameraRoot = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPCameraRoot"));
	TPPCameraRoot->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TPPCameraRoot->TargetArmLength = 300.0f;
	TPPCameraRoot->SetRelativeLocation(FVector(0, 340, 30));

	// Create a camera and attach to our spring arm
	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPCameraRoot, USpringArmComponent::SocketName);

	




}

// Called when the game starts or when spawned
void ACowboyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	//TODO
	FVector EnemyWorldLoc = FVector(350, 0, 112);
	FVector TPPCameraPos = TPPCameraRoot->GetComponentLocation();

	FVector ConeDirection = EnemyWorldLoc - TPPCameraPos;
	float ConeBaseRadius = 200.0f;
	float ConeHigh = ConeDirection.Size();
	UE_LOG(LogTemp, Warning, TEXT("ConeHigh: %f"), ConeHigh);

	float ConeAncleInRadians = FMath::Tan(ConeBaseRadius / ConeHigh);
	UE_LOG(LogTemp, Warning, TEXT("ConeAncleInRadians: %f"), ConeAncleInRadians);

	const int32 RandomSeed = FMath::Rand();
	FRandomStream CameraRandomStream(RandomSeed);

	const FVector InitialRandomVector = CameraRandomStream.VRandCone(ConeDirection.GetSafeNormal(), ConeAncleInRadians);



	FRotator LookAtRandomRotation = UKismetMathLibrary::FindLookAtRotation(TPPCameraPos, (TPPCameraPos + InitialRandomVector*100));

	TPPCameraRoot->SetWorldRotation(LookAtRandomRotation.Quaternion());

	DrawDebugLine(GetWorld(), TPPCameraPos, (TPPCameraPos + InitialRandomVector * 1000), FColor::Emerald, true, -1, 0, 5);


}

// Called every frame
void ACowboyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector EnemyWorldLoc = FVector(350, 0, 112);
	FVector TPPCameraPos = TPPCameraRoot->GetComponentLocation();


	FVector ConeDirection = EnemyWorldLoc - TPPCameraPos;
	float ConeBaseRadius = 200.0f;
	float ConeHigh = ConeDirection.Size();
	UE_LOG(LogTemp, Warning, TEXT("ConeHigh: %f"), ConeHigh);

	float ConeAncleInRadians = FMath::Tan(ConeBaseRadius / ConeHigh);
	UE_LOG(LogTemp, Warning, TEXT("ConeAncleInRadians: %f"), ConeAncleInRadians);

	DrawDebugCone(GetWorld(), TPPCameraPos, ConeDirection.GetSafeNormal(), ConeHigh, ConeAncleInRadians, ConeAncleInRadians, 16, FColor::Red);


	
}

// Called to bind functionality to input
void ACowboyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

