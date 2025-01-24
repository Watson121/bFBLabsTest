// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Delegates/DelegateCombinations.h"
#include "GameScreen.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FIntDelegate, int8, IntValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBoolDelegate, bool, BoolValue);

/**
 * 
 */
UCLASS()
class UGameScreen : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	
	UPROPERTY(BlueprintReadWrite)
	FIntDelegate OnChangeScreenRequest;

	
	virtual void OnChangeLanguage(bool bIsEnglish);

	UFUNCTION(BlueprintCallable)
	void NextScreenRequest(){OnChangeScreenRequest.Broadcast(1) ;}

	UFUNCTION(BlueprintCallable)
	void PreviousScreenRequest(){OnChangeScreenRequest.Broadcast(-1) ;}
};
