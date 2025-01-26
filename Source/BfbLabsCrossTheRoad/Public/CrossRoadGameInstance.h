// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "CrossRoadGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnIncreaseScore);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDecraseScore);

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UCrossRoadGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

#pragma region Scoring

	UFUNCTION(BlueprintCallable, Category = "Score")
	FORCEINLINE int GetScore() const { return score; }

	UFUNCTION(BlueprintCallable, Category = "Score")
	void IncreaseScore(int val);

	UFUNCTION(BlueprintCallable, Category = "Score")
	void DecreaseScore(int val);

	UPROPERTY(VisibleAnywhere, meta = (ClampMin = "0"), Category = "Score")
	int score = 0;

	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnIncreaseScore OnIncreaseScore;

	UPROPERTY(BlueprintAssignable, Category = "Score")
	FOnDecraseScore OnDecreaseScore;

#pragma endregion




	

};
