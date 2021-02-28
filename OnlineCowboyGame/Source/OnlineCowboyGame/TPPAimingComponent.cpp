// Fill out your copyright notice in the Description page of Project Settings.


#include "TPPAimingComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerStart.h"
#include "Kismet/KismetMathLibrary.h"
#include "ViewComponent.h"

// Sets default values for this component's properties
UTPPAimingComponent::UTPPAimingComponent()
#include "CowboyCharacter.h"
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetIsReplicatedByDefault(true);
	SetIsReplicated(true);
	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent()"));
}

void UTPPAimingComponent::GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(UTPPAimingComponent, CameraInitialDirection);
	DOREPLIFETIME(UTPPAimingComponent, bWithinAimingCone);
	
}

void UTPPAimingComponent::Setup(ACowboyCharacter* PawnOwner, USceneComponent* Gimbal, USpringArmComponent* CameraRoot, UCameraComponent* Camera)
{
	TPPAimuthGimbal = Gimbal;
	TPPCameraRoot = CameraRoot;
	TPPCamera = Camera;
	Owner = PawnOwner;

	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::Setup"));
}

// Called when the game starts
void UTPPAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::BeginPlay()"));

	IntitiateRangeCone();
}


// Called every frame
void UTPPAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTPPAimingComponent::IntitiateRangeCone()
{
	
	if (Owner == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::IntitiateRangeCone() pawn is null"));
		return;
	}


	UE_LOG(LogTemp, Warning, TEXT("UTPPAimingComponent::IntitiateRangeCone()"));
	

	FVector RangeStart = TPPCamera->GetComponentLocation();
	FVector RangeEnd = Owner->GetActorLocation() + Owner->GetActorForwardVector() * 1500;

	UE_LOG(LogTemp, Warning, TEXT("%s Start %s, End %s"), *Owner->GetName(), *RangeStart.ToString(), *RangeEnd.ToString());
	//DrawDebugLine(GetWorld(), RangeStart, RangeEnd, FColor::Emerald, true, -1, 0, 5);

	TPPConeDirection = RangeEnd - RangeStart; 
	FVector RadiusVector = (TPPConeDirection.ToOrientationQuat().GetUpVector().GetSafeNormal() * TPPCameraRangeRadius);
	FVector ConeBaseEdgePoint = RangeEnd + RadiusVector;
	FVector ConeEdge = ConeBaseEdgePoint - RangeStart;

	float ConeHigh = TPPConeDirection.Size();
	UE_LOG(LogTemp, Warning, TEXT("ConeHigh: %f"), ConeHigh);

	float ConeAncleInRadians = FMath::Sin(TPPCameraRangeRadius / (ConeBaseEdgePoint - RangeStart).Size());
	UE_LOG(LogTemp, Warning, TEXT("ConeAncleInRadians: %f"), ConeAncleInRadians);


	if (Owner->HasAuthority())
	{
		const int32 RandomSeed = FMath::Rand();
		FRandomStream CameraRandomStream(RandomSeed);

		const FVector InitialRandomVector = CameraRandomStream.VRandCone(TPPConeDirection.GetSafeNormal(), ConeAncleInRadians);

		FVector RandomLocationAtConeBase = RangeStart + InitialRandomVector.GetSafeNormal() * ConeHigh;

		TPPCameraLimit = FVector::DotProduct(TPPConeDirection.GetSafeNormal(), ConeEdge.GetSafeNormal());

		//////UE_LOG(LogTemp, Warning, TEXT("DotCamera: %f"), FVector::DotProduct(TPPConeDirection.GetSafeNormal(), InitialRandomVector.GetSafeNormal()));



		FRotator LookAtRandomRotation = UKismetMathLibrary::FindLookAtRotation(TPPCamera->GetComponentLocation(), RandomLocationAtConeBase);
		CameraInitialDirection = LookAtRandomRotation;
		SetCameraInitialDirection();
		////FQuat LocalLookAtRotationYaw = TPPAimuthGimbal->GetComponentTransform().InverseTransformRotation(LookAtRandomRotation.Quaternion());
		////FQuat LocalLookAtRotationPitch= TPPCameraRoot->GetComponentTransform().InverseTransformRotation(LookAtRandomRotation.Quaternion());
		//DrawDebugCone(GetWorld(), RangeStart, TPPConeDirection.GetSafeNormal(), ConeHigh, ConeAncleInRadians, ConeAncleInRadians, 16, FColor::Red, true, -1, 0, 1);
	}



	//;

	/*if (DrawTppRangeCone)

	if (DrawTppConeDirectionLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, EnemyWorldLoc, FColor::Blue, true, -1, 0, 1);

	if (DrawTppRandomInitialCameraViewLine)
		DrawDebugLine(GetWorld(), TPPCamera->GetComponentLocation(), (TPPCamera->GetComponentLocation() + InitialRandomVector * 1000), FColor::Emerald, true, -1, 0, 1);

	if (DrawTppConeRadiusLine)
		DrawDebugLine(GetWorld(), EnemyWorldLoc, ConeBaseEdgePoint, FColor::Blue, true, -1, 0, 1);

	if (DrawTppConeLimitEdgeLine)
		DrawDebugLine(GetWorld(), TPPCameraRootLocation, ConeBaseEdgePoint, FColor::Purple, true, -1, 0, 1);*/
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
	FVector CowboyDirection = Owner->GetActorForwardVector();


	FQuat OffsetAngle = FQuat::FindBetweenNormals(TPPConeDirection.GetSafeNormal(), TPPCamera->GetForwardVector());
	Pitch = FMath::Clamp<float>(OffsetAngle.Rotator().Pitch, -11.f, 11.f) * CowboyDirection.X;
	Yaw = -FMath::Clamp<float>(OffsetAngle.Rotator().Yaw, -11.f, 11.f);

	if (Owner->HasAuthority() && Owner->IsLocallyControlled())
	{
		UE_LOG(LogTemp, Warning, TEXT("Pitch %f, Yaw %f"), Pitch, Yaw);
	}

}

void UTPPAimingComponent::OnRep_CameraInitialDirection()
{
	SetCameraInitialDirection();
}


void UTPPAimingComponent::SetCameraInitialDirection()
{
	TPPAimuthGimbal->SetRelativeRotation(FRotator(0, 0, 0));
	TPPCameraRoot->SetRelativeRotation(FRotator(0, 0, 0));
	TPPAimuthGimbal->SetWorldRotation(CameraInitialDirection);
}

bool UTPPAimingComponent::IsWithinAimingCone()
{
	if (Owner->HasAuthority())
	{
		float AimingDotProduct = FVector::DotProduct(TPPConeDirection.GetSafeNormal(), TPPCamera->GetForwardVector());
		bWithinAimingCone = AimingDotProduct > TPPCameraLimit;
	}

	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("%d"),bWithinAimingCone));

	return bWithinAimingCone;
}




