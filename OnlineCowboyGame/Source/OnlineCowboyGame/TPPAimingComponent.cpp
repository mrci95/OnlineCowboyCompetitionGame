// Fill out your copyright notice in the Description page of Project Settings.


#include "TPPAimingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values for this component's properties
UTPPAimingComponent::UTPPAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent()"));
}

void UTPPAimingComponent::Setup(USceneComponent* Gimbal, USpringArmComponent* CameraRoot, UCameraComponent* Camera)
{
	TPPAimuthGimbal = Gimbal;
	TPPCameraRoot = CameraRoot;
	TPPCamera = Camera;


	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::Setup"));
}

// Called when the game starts
void UTPPAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::BeginPlay()"));
}


// Called every frame
void UTPPAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTPPAimingComponent::IntitiateRangeCone()
{
	FVector EnemyWorldLoc;

	TArray<AActor*> SpawnPoints;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), SpawnPoints);

	for (AActor* SpawnPoint : SpawnPoints)
	{
		if (!SpawnPoint->GetActorLocation().Equals(GetOwner()->GetActorLocation()))
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
	//UE_LOG(LogTemp, Warning, TEXT("ConeHigh: %f"), ConeHigh);

	float ConeAncleInRadians = FMath::Sin(TPPCameraRangeRadius / (ConeBaseEdgePoint - TPPCameraRootLocation).Size());
	//UE_LOG(LogTemp, Warning, TEXT("ConeAncleInRadians: %f"), ConeAncleInRadians);

	const int32 RandomSeed = FMath::Rand();
	FRandomStream CameraRandomStream(RandomSeed);

	const FVector InitialRandomVector = CameraRandomStream.VRandCone(TPPConeDirection.GetSafeNormal(), ConeAncleInRadians);

	TPPCameraLimit = FVector::DotProduct(TPPConeDirection.GetSafeNormal(), ConeEdge.GetSafeNormal());

	//UE_LOG(LogTemp, Warning, TEXT("DotLimit: %f"), TPPCameraLimit);
	//UE_LOG(LogTemp, Warning, TEXT("DotCamera: %f"), FVector::DotProduct(TPPConeDirection.GetSafeNormal(), InitialRandomVector.GetSafeNormal()));

	FRotator LookAtRandomRotation = UKismetMathLibrary::FindLookAtRotation(TPPCameraRootLocation, (TPPCameraRootLocation + InitialRandomVector.GetSafeNormal() * 100));

	FQuat LocalLookAtRotationYaw = TPPAimuthGimbal->GetComponentTransform().InverseTransformRotation(LookAtRandomRotation.Quaternion());
	FQuat LocalLookAtRotationPitch= TPPCameraRoot->GetComponentTransform().InverseTransformRotation(LookAtRandomRotation.Quaternion());

	
	

	TPPAimuthGimbal->SetRelativeRotation(FRotator(0,0, 0));
	TPPCameraRoot->SetRelativeRotation(FRotator(0,0, 0));
	TPPAimuthGimbal->SetWorldRotation(LookAtRandomRotation);



	if (DrawTppRangeCone)
		DrawDebugCone(GetWorld(), TPPCameraRootLocation, TPPConeDirection.GetSafeNormal(), ConeHigh, ConeAncleInRadians, ConeAncleInRadians, 16, FColor::Red, true, -1, 0, 1);

	if (DrawTppConeDirectionLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, EnemyWorldLoc, FColor::Blue, true, -1, 0, 1);

	if (DrawTppRandomInitialCameraViewLine)
		DrawDebugLine(GetWorld(), TPPCamera->GetComponentLocation(), (TPPCamera->GetComponentLocation() + InitialRandomVector * 1000), FColor::Emerald, true, -1, 0, 1);

	if (DrawTppConeRadiusLine)
		DrawDebugLine(GetWorld(), EnemyWorldLoc, ConeBaseEdgePoint, FColor::Blue, true, -1, 0, 1);

	if (DrawTppConeLimitEdgeLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, ConeBaseEdgePoint, FColor::Purple, true, -1, 0, 1);
}

FString UTPPAimingComponent::OwnerRoleString()
{
	switch (GetOwnerRole())
	{
		case ROLE_Authority:
			return "ROLE_Authority";
			break;
		case ROLE_AutonomousProxy:
			return "ROLE_AutonomousProxy";
			break;
		case ROLE_SimulatedProxy:
			return "ROLE_SimulatedProxy";
			break;
		default:
			return "error";
			break;
	}
}

//DO NOT CHANGEEE!!!!!! SUPER SIMPLE METHOD :)
void UTPPAimingComponent::SimulateMouseMovement(const FMouseMovement& Move)
{
	if (!ensure(TPPAimuthGimbal != nullptr)) return;
	if (!ensure(TPPCameraRoot != nullptr)) return;
	if (!ensure(TPPCamera != nullptr)) return;


	FRotator NewYaw = TPPAimuthGimbal->GetRelativeRotation();
	NewYaw.Yaw = FMath::Clamp<float>(NewYaw.Yaw + Move.MouseMoveVector.X, -TPPCameraYawLimit, TPPCameraYawLimit);
	TPPAimuthGimbal->SetRelativeRotation(NewYaw);

	FRotator NewPitch = TPPCameraRoot->GetRelativeRotation();
	NewPitch.Pitch = FMath::Clamp<float>(NewPitch.Pitch + Move.MouseMoveVector.Y, -TPPCameraPitchLimit, TPPCameraPitchLimit);
	TPPCameraRoot->SetRelativeRotation(NewPitch);
}

float UTPPAimingComponent::GetCameraYaw()
{
	if (!ensure(TPPAimuthGimbal != nullptr)) return 0;

	return TPPAimuthGimbal->GetRelativeRotation().Yaw;
}

void UTPPAimingComponent::SetCameraYaw(float Val)
{
	if (!ensure(TPPAimuthGimbal != nullptr)) return;

	FRotator NewYaw = TPPAimuthGimbal->GetRelativeRotation();
	NewYaw.Yaw = FMath::Clamp<float>(Val, -TPPCameraYawLimit, TPPCameraYawLimit);
	TPPAimuthGimbal->SetRelativeRotation(NewYaw);
}

float UTPPAimingComponent::GetCameraPitch()
{
	if (!ensure(TPPCameraRoot != nullptr)) return 0;

	return TPPCameraRoot->GetRelativeRotation().Pitch;
}
void UTPPAimingComponent::SetCameraPitch(float Val)
{

	if (!ensure(TPPCameraRoot != nullptr)) return;

	FRotator NewPitch = TPPCameraRoot->GetRelativeRotation();
	NewPitch.Pitch = FMath::Clamp<float>(Val, -TPPCameraPitchLimit, TPPCameraPitchLimit);
	TPPCameraRoot->SetRelativeRotation(NewPitch);
}

void UTPPAimingComponent::SetViewActive(bool Activate)
{
	if (!ensure(TPPCamera != nullptr)) return;
	TPPCamera->SetActive(Activate);
}


void UTPPAimingComponent::SetCameraLookAtPoint(FVector PointInWorld)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(TPPAimuthGimbal->GetComponentLocation(), PointInWorld);

	TPPAimuthGimbal->SetRelativeRotation(FRotator(0, 0, 0));
	TPPCameraRoot->SetRelativeRotation(FRotator(0, 0, 0));
	TPPAimuthGimbal->SetWorldRotation(LookAtRotation);
}

void UTPPAimingComponent::GetAimingOffset(float& Yaw, float& Pitch)
{
	FVector CowboyDirection = GetOwner()->GetActorForwardVector();
	FQuat OffsetAngle = FQuat::FindBetweenNormals(TPPConeDirection.GetSafeNormal(), TPPCamera->GetForwardVector());
	Pitch = FMath::Clamp<float>(OffsetAngle.Rotator().Pitch, -7.5f, 7.5f) * CowboyDirection.X;
	Yaw = FMath::Clamp<float>(OffsetAngle.Rotator().Yaw, -7.5f, 7.5f);
}


