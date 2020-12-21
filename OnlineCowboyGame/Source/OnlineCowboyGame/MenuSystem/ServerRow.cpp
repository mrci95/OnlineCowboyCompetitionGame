// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerRow.h"
#include "MainMenu.h"
#include "Components/Button.h"

bool UServerRow::Initialize()
{

	Super::Initialize();

	ServerRowButton->OnClicked.AddDynamic(this, &UServerRow::OnClicked);

	return true;
}

void UServerRow::Setup(UMainMenu* InParent, uint32 InIndex)
{
	Parent = InParent;
	Index = InIndex;
	Selected = false;
}

void UServerRow::OnClicked()
{
	if (Parent != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Select %d"), Index);
		Parent->SetSelectedIndex(Index);
	}
}