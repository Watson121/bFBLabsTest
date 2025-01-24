// Fill out your copyright notice in the Description page of Project Settings.


#include "GameScreen/LoginScreen.h"

#include "CtrGameMode.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"

void ULoginScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	ValidateButton->OnClicked.AddUniqueDynamic(this, &ULoginScreen::OnValidate);
	French->OnClicked.AddUniqueDynamic(this, &ULoginScreen::OnFrench);
	English->OnClicked.AddUniqueDynamic(this, &ULoginScreen::OnEnglish);
}

void ULoginScreen::OnValidate()
{
	//Todo database call to check informations

	NextScreenRequest();
	
}

void ULoginScreen::OnChangeLanguage(bool bIsEnglish)
{
	auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
	Cast<UTextBlock>(ValidateButton->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Validate") : TEXT("Valider"))));

	MailAddress->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("MailAddress") : TEXT("Addresse mail"))));

	Password->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Password") : TEXT("Mot de passe"))));

	Cast<UTextBlock>(French->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("French") : TEXT("Français"))));

	Cast<UTextBlock>(English->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("English") : TEXT("Anglais"))));
}
