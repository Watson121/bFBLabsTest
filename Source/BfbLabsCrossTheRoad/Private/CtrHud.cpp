// Fill out your copyright notice in the Description page of Project Settings.


#include "CtrHud.h"

#include "CtrGameMode.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "GameScreen/GameScreen.h"

void ACtrHud::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetPlayerController(GetWorld(),0)->SetShowMouseCursor(true);
	ChangeCurrentScreen();

	auto GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->OnChangeLanguage.AddDynamic(this, &ACtrHud::OnChangeLanguage);
}

void ACtrHud::ChangeCurrentScreen()
{
	
	if(CurrentGameScreen != nullptr)
	{
		CurrentGameScreen->RemoveFromParent();
		CurrentGameScreen->OnChangeScreenRequest.RemoveDynamic(this, &ACtrHud::OnChangeScreenRequest);
		
	}

	const TSubclassOf<UGameScreen> NewGameScreen = ScreensArray[CurrentGameScreenId];
	CurrentGameScreen = Cast<UGameScreen>(CreateWidget(GetWorld(), NewGameScreen));
	CurrentGameScreen->OnChangeScreenRequest.AddUniqueDynamic(this, &ACtrHud::OnChangeScreenRequest);
	
	CurrentGameScreen->AddToViewport();	
}

void ACtrHud::OnChangeScreenRequest(int8 Offset)
{
	CurrentGameScreenId = FMath::Clamp(CurrentGameScreenId + Offset, 0, ScreensArray.Num()-1);
	ChangeCurrentScreen();
}