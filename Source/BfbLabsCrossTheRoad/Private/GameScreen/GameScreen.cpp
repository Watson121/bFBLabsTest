// Fill out your copyright notice in the Description page of Project Settings.


#include "GameScreen/GameScreen.h"

#include "CtrGameMode.h"
#include "Kismet/GameplayStatics.h"

void UGameScreen::NativeConstruct()
{
	Super::NativeConstruct();

	auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	

	OnChangeLanguage(GameMode->bIsEnglish);
}

void UGameScreen::OnChangeLanguage(bool bIsEnglish)
{
}


