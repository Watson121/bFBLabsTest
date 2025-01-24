// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CtrGameMode.h"
#include "GameScreen.h"
#include "Kismet/GameplayStatics.h"
#include "LoginScreen.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API ULoginScreen : public UGameScreen
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UEditableTextBox* MailAddress;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UEditableTextBox* Password;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ValidateButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* French;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* English;

private:
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnValidate();
	virtual void OnChangeLanguage(bool bIsEnglish) override;

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
};
