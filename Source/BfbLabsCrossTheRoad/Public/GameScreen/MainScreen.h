// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CtrGameMode.h"
#include "GameScreen/GameScreen.h"
#include "Kismet/GameplayStatics.h"
#include "WebBrowser.h"

#include "MainScreen.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UMainScreen : public UGameScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ReplayTutorial;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* CrossRoad;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* French;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* English;

	

	UFUNCTION()
	void OnEnglish()
	{
		auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->bIsEnglish = true;
		GameMode->OnChangeLanguage.Broadcast(true);
	};
	UFUNCTION()
	void OnFrench()
	{
		auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
		GameMode->bIsEnglish = false;
		GameMode->OnChangeLanguage.Broadcast(false);
	};
	void NativeConstruct();
	virtual void OnChangeLanguage(bool bIsEnglish) override;
};
