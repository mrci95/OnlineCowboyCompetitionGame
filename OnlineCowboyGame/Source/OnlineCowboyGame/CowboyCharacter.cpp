// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "DrawDebugHelpers.h"
#include "Math/RandomStream.h"
#include "Math/Quat.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"

#include "Net/UnrealNetwork.h"

// Sets default values
ACowboyCharacter::ACowboyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);

	CoboyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CowboyTPPMesh"));
	CoboyMesh->SetRelativeLocation(FVector(0, 0, 0));
	CoboyMesh->AttachToComponent(RootComponent,FAttachmentTransformRules::KeepRelativeTransform);
	
	TPPCameraRoot = CreateDefaultSubobject<USpringArmComponent>(TEXT("TPPCameraRoot"));
	TPPCameraRoot->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	TPPCameraRoot->TargetArmLength = 300.0f;
	TPPCameraRoot->SetRelativeLocation(FVector(0, 340, 30));

	// Create a camera and attach to our spring arm
	TPPCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("TPPCamera"));
	TPPCamera->SetupAttachment(TPPCameraRoot, USpringArmComponent::SocketName);

	




}

void ACowboyCharacter::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACowboyCharacter, ServerState);
}

// Called when the game starts or when spawned
void ACowboyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	IntitiateTPPRangeCone();
	
}

// Called every frame
void ACowboyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsLocallyControlled())
	{
		FMouseMove LastMove = CreateMove(DeltaTime);
		SimulateAiming(LastMove);

		if (GetLocalRole() == ROLE_AutonomousProxy)
		{
			Server_SendMove(LastMove);
		}
		else
		{
			UpdateServerState();
		}
	}



	


	
}

// Called to bind functionality to input
void ACowboyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LookUp", this, &ACowboyCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookRight", this, &ACowboyCharacter::LookRight);
}

void ACowboyCharacter::IntitiateTPPRangeCone()
{
	//TO DO get real character pos
	FVector EnemyWorldLoc;

	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);
	
	for (AActor* SpawnPoint : SpawnPoints)
	{
		if (!SpawnPoint->GetActorLocation().Equals(GetActorLocation()))
		{
			EnemyWorldLoc = SpawnPoint->GetActorLocation();
		}
	}

	
	FVector TPPCameraRootLocation = TPPCameraRoot->GetComponentLocation(); //Camera root position
	TPPConeDirection = EnemyWorldLoc - TPPCameraRootLocation; //Cone direction from Camera to Enemy
	FVector RadiusVector = (TPPConeDirection.ToOrientationQuat().GetUpVector().GetSafeNormal() * TPPCameraRangeRadius);
	FVector ConeBaseEdgePoint = EnemyWorldLoc + RadiusVector;
	FVector ConeEdge = ConeBaseEdgePoint - TPPCameraRootLocation;

	float ConeHigh = TPPConeDirection.Size();
	UE_LOG(LogTemp, Warning, TEXT("ConeHigh: %f"), ConeHigh);

	float ConeAncleInRadians = FMath::Sin(TPPCameraRangeRadius / (ConeBaseEdgePoint - TPPCameraRootLocation).Size());
	UE_LOG(LogTemp, Warning, TEXT("ConeAncleInRadians: %f"), ConeAncleInRadians);

	const int32 RandomSeed = FMath::Rand();
	FRandomStream CameraRandomStream(RandomSeed);

	const FVector InitialRandomVector = CameraRandomStream.VRandCone(TPPConeDirection.GetSafeNormal(), ConeAncleInRadians);

	TPPCameraLimit = FVector::DotProduct(TPPConeDirection.GetSafeNormal(), ConeEdge.GetSafeNormal());

	UE_LOG(LogTemp, Warning, TEXT("DotLimit: %f"), TPPCameraLimit);
	UE_LOG(LogTemp, Warning, TEXT("DotCamera: %f"), FVector::DotProduct(TPPConeDirection.GetSafeNormal(), InitialRandomVector.GetSafeNormal()));

	FRotator LookAtRandomRotation = UKismetMathLibrary::FindLookAtRotation(TPPCamera->GetComponentLocation(), (TPPCamera->GetComponentLocation() + InitialRandomVector * 100));

	TPPCameraRoot->SetRelativeRotation(LookAtRandomRotation);


	if (DrawTppRangeCone)
		DrawDebugCone(GetWorld(), TPPCameraRootLocation, TPPConeDirection.GetSafeNormal(), ConeHigh, ConeAncleInRadians, ConeAncleInRadians, 16, FColor::Red, true, -1, 0, 1);

	if (DrawTppConeDirectionLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, EnemyWorldLoc, FColor::Blue, true, -1, 0, 1);

	if (DrawTppRandomInitialCameraViewLine)
		DrawDebugLine(GetWorld(), TPPCamera->GetComponentLocation(), (TPPCamera->GetComponentLocation() + InitialRandomVector * 1000), FColor::Emerald, true, -1, 0, 1);

	if (DrawTppConeRadiusLine)
		DrawDebugLine(GetWorld(), EnemyWorldLoc, ConeBaseEdgePoint, FColor::Blue, true, -1, 0, 1);

	if(DrawTppConeLimitEdgeLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, ConeBaseEdgePoint, FColor::Purple, true, -1, 0, 1);
}

void ACowboyCharacter::LookUp(float Val)
{
	MouseMove.Y = Val;
}

void ACowboyCharacter::LookRight(float Val)
{
	MouseMove.X = Val;
}

FMouseMove ACowboyCharacter::CreateMove(float DeltaTime)
{
	FMouseMove MouseMoveStruct;
	MouseMoveStruct.Move.X = MouseMove.X;
	MouseMoveStruct.Move.Y = MouseMove.Y;
	MouseMoveStruct.DeltaTime = DeltaTime;

	return MouseMoveStruct;
}

void ACowboyCharacter::SimulateAiming(FMouseMove LastMove)
{
	float RotationAnglePitch = 2 * LastMove.DeltaTime * LastMove.Move.Y;
	FQuat DeltaPitch(TPPConeDirection.ToOrientationQuat().GetRightVector().GetSafeNormal(), RotationAnglePitch);

	float RotationAngleYaw = 2 * LastMove.DeltaTime * LastMove.Move.X;
	FQuat DeltaYaw(TPPConeDirection.ToOrientationQuat().GetUpVector().GetSafeNormal(), RotationAngleYaw);

	FQuat NewRotation = DeltaYaw * TPPCameraRoot->GetComponentTransform().GetRotation();
	NewRotation = DeltaPitch * NewRotation;
	float NewRotationDotProduct = FVector::DotProduct(TPPConeDirection.GetSafeNormal(), TPPCameraRoot->GetRelativeRotation().Vector().GetSafeNormal());
	float pitchClamped = FMath::Clamp<float>(NewRotation.Rotator().Pitch, -30, 30);
	float yawClamped = FMath::Clamp<float>(NewRotation.Rotator().Yaw, -90, 20);
	float rollClamped = 0;
	FRotator NewRotationRotator;
	NewRotationRotator.Pitch = pitchClamped;
	NewRotationRotator.Yaw = yawClamped;
	NewRotationRotator.Roll = rollClamped;

	FQuat NewRotationClamped = NewRotationRotator.Quaternion();

	TPPCameraRoot->SetWorldRotation(NewRotationClamped);

	if (NewRotationDotProduct >= TPPCameraLimit)
	{
		DrawDebugLine(GetWorld(), TPPCameraRoot->GetComponentLocation(), (TPPCameraRoot->GetComponentLocation() + TPPCamera->GetForwardVector() * 1000), FColor::Black, false, -1, 0.1f, 5);
	}
	else
	{
		DrawDebugLine(GetWorld(), TPPCameraRoot->GetComponentLocation(), (TPPCameraRoot->GetComponentLocation() + TPPCameraRoot->GetRelativeRotation().Vector().GetSafeNormal() * 100), FColor::Red, false, -1, 0.1f, 5);
	}
}

void ACowboyCharacter::Server_SendMove_Implementation(FMouseMove Move)
{
	SimulateAiming(Move);

	UpdateServerState();
}

bool ACowboyCharacter::Server_SendMove_Validate(FMouseMove Move)
{
	return true;
}

void ACowboyCharacter::UpdateServerState()
{
	ServerState.Transform = TPPCameraRoot->GetComponentTransform();
}

void ACowboyCharacter::OnRep_ServerState()
{
	if (GetLocalRole() == ROLE_SimulatedProxy)
	{
		TPPCameraRoot->SetWorldTransform(ServerState.Transform);
	}
}



