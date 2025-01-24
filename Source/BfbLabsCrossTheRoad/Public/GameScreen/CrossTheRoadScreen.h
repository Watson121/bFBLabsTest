// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameScreen.h"
#include "CrossTheRoadScreen.generated.h"

UENUM()
enum class ECrossStep : uint8 {
	CS_None,
	CS_FirstLook,
	CS_SecondLook,
	CS_ThirdLook,
	CS_ReadyToCross
};

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UCrossTheRoadScreen : public UGameScreen
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* YawValueText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* CurrentStepText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* ReadyButton;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton;
	
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UEditableTextBox* DebugValue;
	
private:
	UFUNCTION()
	void OnReady();
	
	virtual void NativeConstruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	void UpdateStringForCurrentStep() const;
	
	virtual void OnChangeLanguage(bool bIsEnglish) override;

	UPROPERTY()
	APlayerController* PlayerController;

	UPROPERTY()
	class ACtrGameMode* GameMode;

	float YawOnStart;
	bool bIsDrivingOnLeftSide;
	bool bShouldLookRight;
	ECrossStep CurrentStep = ECrossStep::CS_None;
	
	FVector Tilt;
	FVector RotationRate;
	FVector Gravity;
	FVector Acceleration;

	const uint8 FloatToAngleMultiplier = 60;
	const uint8 MinAngleToConsiderTurn = 60;
};
