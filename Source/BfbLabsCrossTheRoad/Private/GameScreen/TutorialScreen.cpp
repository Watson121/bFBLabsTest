// Fill out your copyright notice in the Description page of Project Settings.


#include "GameScreen/TutorialScreen.h"

#include "CtrGameMode.h"
#include "WebBrowser.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
#include "Components/ScaleBox.h"
#include "Components/TextBlock.h"
#include "Kismet/GameplayStatics.h"


void UTutorialScreen::NativeConstruct()
{
	Super::NativeConstruct();
	
	LeftSideButton->OnClicked.AddUniqueDynamic(this, &UTutorialScreen::OnLeftSideChoiceClicked);
	RightSideButton->OnClicked.AddUniqueDynamic(this, &UTutorialScreen::OnRightSideChoiceClicked);
	ContinueButton->OnClicked.AddUniqueDynamic(this, &UGameScreen::NextScreenRequest);

	TutorialPanel->SetVisibility(ESlateVisibility::Hidden);	
}

void UTutorialScreen::OnChoiceClicked(const bool bIsLeftClicked) const
{
	ACtrGameMode* GameMode = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->SetDrivingOnLeftSide(bIsLeftClicked);
	ChoiceScaleBox->SetVisibility(ESlateVisibility::Hidden);
	TutorialPanel->SetVisibility(ESlateVisibility::Visible);
}

void UTutorialScreen::OnChangeLanguage(bool bIsEnglish)
{
	auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
	Cast<UTextBlock>(LeftSideButton->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("LEFT side of the road") : TEXT("à GAUCHE de la route"))));

	Cast<UTextBlock>(RightSideButton->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("RIGHT side of the road") : TEXT("à DROITE de la route"))));

	Cast<UTextBlock>(ContinueButton->GetChildAt(0))->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Continue") : TEXT("Continuer"))));

	TextFirstPart->SetText(
			FText::FromString(FString(GameMode->bIsEnglish ? TEXT("Vehicles drive on the :") : TEXT("Les véhicules roulent :"))));

	WebBrowser->LoadURL(GameMode->bIsEnglish ? TEXT("https://www.gov.uk/guidance/the-highway-code/rules-for-pedestrians-1-to-35") :
		TEXT("https://www.securite-routiere.gouv.fr/reglementation-liee-aux-modes-de-deplacements/pietons-et-mobilite-urbaine/reglementation-des"));
}