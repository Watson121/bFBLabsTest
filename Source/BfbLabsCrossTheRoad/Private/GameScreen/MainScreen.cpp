// Fill out your copyright notice in the Description page of Project Settings.


#include "GameScreen/MainScreen.h"

#include "CtrGameMode.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void UMainScreen::NativeConstruct()
{
	Super::NativeConstruct();

	French->OnClicked.AddUniqueDynamic(this, &UMainScreen::OnFrench);
	English->OnClicked.AddUniqueDynamic(this, &UMainScreen::OnEnglish);
}

void UMainScreen::OnChangeLanguage(bool bIsEnglish)
{
	auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
	Cast<UTextBlock>(ReplayTutorial->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Replay tutorial") : TEXT("Rejouer tutoriel"))));

	Cast<UTextBlock>(CrossRoad->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("CrossRoad") : TEXT("Traverser"))));

	Cast<UTextBlock>(CrossRoad->GetChildAt(0))->SetText(
		FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Score Shop") : TEXT("Boutique de partitions"))));

	Cast<UTextBlock>(French->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("French") : TEXT("Français"))));

	Cast<UTextBlock>(English->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("English") : TEXT("Anglais"))));

	
	
}