// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CowboyRenderTargetHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API UCowboyRenderTargetHUD : public UUserWidget
{
	GENERATED_BODY()

public:

	UCowboyRenderTargetHUD(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

	void SetRenderView(class UTextureRenderTarget2D* RenderTarget);
	
protected:
	
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UImage* RenderedView = nullptr;

private:

	UPROPERTY()
	class UMaterial* SnapshotMaterialBase;



};
