// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameHUD.generated.h"


class UTextureRenderTarget2D;
/**
 * 
 */
UCLASS()
class ONLINECOWBOYGAME_API AGameHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	AGameHUD();


	void ShowMatchHUDAtGameStart();
	void Hide();
	void BeginPlayersPresentation();
	void EndPlayersPresentation();
	void BeginMatchSummary();
	void ShowWinner(FString PlayerName, UTextureRenderTarget2D* View);
	void UpdatePlayersScore(uint16 PlayerOne, uint16 PlayerTwo);
	void SetPlayersData(FString PlayerOne, FString PlayerTwo);
	void OnPawnPossessed();

	void SetCurrentRound(uint16 Round);

	void OnFire();

	void ReloadStart();
	void ClearCylinder();
	void InsertingBullet();
	void BulletInserted();
	void ReloadEnd();

	void SetRoundStartCounter(uint8 Counter);


protected:

	virtual void BeginPlay() override;

	//UPROPERTY(EditAnywhere)
	TSubclassOf<class UGameHUDWidget> GameHUDWidgetClass;

	TSubclassOf<class UMatchHUD> MatchHUDClass;



private:

	UPROPERTY()
	class UGameHUDWidget* GameHUDWidget;

	UPROPERTY()
	class UMatchHUD* MatchHUD;


	void CreateGameInterface();

	void CreateMatchHUD();

	void CreateMatchIntroHUD();

	FTimerHandle DelayTimer;
	void PresentPlayers();
	void PresentPlayersName();
};
