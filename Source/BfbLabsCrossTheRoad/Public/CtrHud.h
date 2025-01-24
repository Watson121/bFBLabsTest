// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GameScreen/GameScreen.h"
#include "CtrHud.generated.h"

UENUM()
enum class ETextNames : uint8 {
	TN_Step1
};
/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API ACtrHud : public AHUD
{
	GENERATED_BODY()
	
private:
	UFUNCTION()
	void OnChangeLanguage(bool bArg){CurrentGameScreen->OnChangeLanguage(bArg);}
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnChangeScreenRequest(int8 Offset);
	
	void ChangeCurrentScreen();

	UPROPERTY()
	class UGameScreen* CurrentGameScreen;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<UGameScreen>> ScreensArray;
	
	uint8 CurrentGameScreenId = 0;
};
