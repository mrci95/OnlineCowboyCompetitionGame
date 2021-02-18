// Fill out your copyright notice in the Description page of Project Settings.


#include "CowboyRenderTargetHUD.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Components/Image.h"


UCowboyRenderTargetHUD::UCowboyRenderTargetHUD(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer)
{
    // Path to the material
    //ConstructorHelpers::FObjectFinder<UMaterial> snapshotMaterialFinder(TEXT("/Game/CowboyPawn/MAT_PlayerRT"));

    // Need to cast the pointer. The mSnapshotMaterial has type UMaterial*
    //SnapshotMaterialBase = (UMaterial*)snapshotMaterialFinder.Object;
}

void UCowboyRenderTargetHUD::NativeConstruct()
{
	Super::NativeConstruct();
}


void UCowboyRenderTargetHUD::SetRenderView(UTextureRenderTarget2D* RenderTarget)
{

    UE_LOG(LogTemp, Warning, TEXT("UCowboyRenderTargetHUD::SetRenderView"));
    // Creating a new material from the base one and setting the render target as texture
    UMaterialInstanceDynamic* dynamicMaterial = UMaterialInstanceDynamic::Create(SnapshotMaterialBase, this);
    dynamicMaterial->SetTextureParameterValue(FName("Texture"), RenderTarget);

    // Telling the UMG to set the new material
    RenderedView->SetBrushFromMaterial(dynamicMaterial);
}
