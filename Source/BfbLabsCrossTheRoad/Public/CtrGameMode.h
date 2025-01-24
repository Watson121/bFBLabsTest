// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameScreen/GameScreen.h"
#include "CtrGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API ACtrGameMode : public AGameModeBase
{
	GENERATED_BODY()


public:
	bool bIsEnglish = true;
	
	void SetDrivingOnLeftSide(const bool IsDrivingOnLeftSide)
	{
		bIsDrivingOnLeftSide = IsDrivingOnLeftSide;
	}
	
	bool GetDrivingOnLeftSide() const
	{
		return bIsDrivingOnLeftSide;
	}

	UPROPERTY(BlueprintReadWrite)
	FBoolDelegate OnChangeLanguage;

private:
	bool bIsDrivingOnLeftSide;
	
};
