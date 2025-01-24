// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameScreen.h"
#include "Components/TextBlock.h"
#include "TutorialScreen.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UTutorialScreen : public UGameScreen
{
	GENERATED_BODY()

	
	
public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UScaleBox* ChoiceScaleBox;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UCanvasPanel* TutorialPanel;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* LeftSideButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* RightSideButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* ContinueButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* TextFirstPart;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UWebBrowser* WebBrowser;

private:
	UFUNCTION()
	void OnLeftSideChoiceClicked() { OnChoiceClicked(true);}
	UFUNCTION()
	void OnRightSideChoiceClicked() { OnChoiceClicked(false);}
	void OnChoiceClicked(bool bIsLeftClicked) const;
	virtual void OnChangeLanguage(bool bIsEnglish) override;

	virtual void NativeConstruct() override;

	
};
