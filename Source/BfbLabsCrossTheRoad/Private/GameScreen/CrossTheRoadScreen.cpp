// Fill out your copyright notice in the Description page of Project Settings.


#include "GameScreen/CrossTheRoadScreen.h"

#include "CtrGameMode.h"
#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/TextBlock.h"
#include "CrossRoadGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UCrossTheRoadScreen::NativeConstruct()
{
	GameMode  = Cast<ACtrGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
	Super::NativeConstruct();

	PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);	

	UpdateStringForCurrentStep();

	ReadyButton->OnClicked.AddUniqueDynamic(this, &UCrossTheRoadScreen::OnReady);
	BackButton->OnClicked.AddUniqueDynamic(this, &UGameScreen::PreviousScreenRequest);

	
#if !UE_EDITOR
	DebugValue->SetVisibility(ESlateVisibility::Hidden);
#endif
}

void UCrossTheRoadScreen::OnReady()
{
	
	bShouldLookRight = GameMode->GetDrivingOnLeftSide();
	
	CurrentStep = ECrossStep::CS_FirstLook;
	UpdateStringForCurrentStep();
	
	ReadyButton->SetVisibility(ESlateVisibility::Hidden);
	
	PlayerController->GetInputMotionState(Tilt, RotationRate, Gravity, Acceleration);
	YawOnStart = 0;

#if UE_EDITOR
	DebugValue->SetText(FText());
#endif
}

void UCrossTheRoadScreen::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	if(CurrentStep == ECrossStep::CS_None || CurrentStep == ECrossStep::CS_ReadyToCross) return;
	
	//float YawOnStart = 0.0f;
#if UE_EDITOR
	YawOnStart = FCString::Atof(*DebugValue->GetText().ToString());
#else
	PlayerController->GetInputMotionState(Tilt, RotationRate, Gravity, Acceleration);
	YawOnStart += RotationRate.X;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, test.ToString());
#endif 	
	
	YawValueText->SetText(FText::FromString(FString::FromInt(YawOnStart)));

	if((YawOnStart < -MinAngleToConsiderTurn && !bShouldLookRight) ||
		(YawOnStart > MinAngleToConsiderTurn && bShouldLookRight))
	{
		uint8 NextEnumValue =  static_cast<uint8>(CurrentStep) + 1;
		CurrentStep = static_cast<ECrossStep>(NextEnumValue);
		
		bShouldLookRight = !bShouldLookRight;
		UpdateStringForCurrentStep();

		// Get Game Instance, and Increase the Score By One
		Cast<UCrossRoadGameInstance>(GetGameInstance())->IncreaseScore(1);

		if(CurrentStep == ECrossStep::CS_ReadyToCross)
		{
			ReadyButton->SetVisibility(ESlateVisibility::Visible);
		}
	}	
}

void UCrossTheRoadScreen::UpdateStringForCurrentStep() const
{
	FString NewTextForStep;
	switch (CurrentStep)
	{
	case ECrossStep::CS_None:
		NewTextForStep = GameMode->bIsEnglish ?
TEXT("When you are ready, point your phone at the other side of the street and press the button"):
TEXT("Quand vous serez prêt, visez l'autre côté de la rue avec votre téléphone et appuyez sur le bouton")	;
		break;
	case ECrossStep::CS_FirstLook:
		NewTextForStep = NewTextForStep = GameMode->bIsEnglish ?
			FString("Start by looking on your ") + FString(bShouldLookRight ? "Right!" : "Left!"):
				FString(TEXT("Commencez par regarder à ")) + FString(bShouldLookRight ? "Droite!" : "Gauche!");
		break;
	case ECrossStep::CS_SecondLook:
	case ECrossStep::CS_ThirdLook:
		NewTextForStep = NewTextForStep = GameMode->bIsEnglish ?
			FString(TEXT("Well done, now look on your ")) + FString(bShouldLookRight ? "Right!" : "Left!"):
			FString(TEXT("Bravo, maintenant regardez à ")) + FString(bShouldLookRight ? "Droite!" : "Gauche!");;
		break;
	case ECrossStep::CS_ReadyToCross:
		NewTextForStep = NewTextForStep = GameMode->bIsEnglish ?
TEXT("Well done, you can now cross the road but stay cautious"):
	TEXT("Bravo, vous pouvez maintenant traverser en restant prudent");
		break;
	default: ;
	}

	CurrentStepText->SetText( FText::FromString(NewTextForStep));
}

void UCrossTheRoadScreen::OnChangeLanguage(bool bIsEnglish)
{
	UpdateStringForCurrentStep();
}
