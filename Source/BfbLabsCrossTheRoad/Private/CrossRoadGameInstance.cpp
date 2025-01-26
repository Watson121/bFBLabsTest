// Fill out your copyright notice in the Description page of Project Settings.


#include "CrossRoadGameInstance.h"

// Increasing the score by the value passed in
void UCrossRoadGameInstance::IncreaseScore(int val)
{
	GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Yellow, TEXT("Current Score: ") + FString::FromInt(score));
	score += val;
	GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Yellow, TEXT("Updated Score: ") + FString::FromInt(score));

	OnIncreaseScore.Broadcast();
}

void UCrossRoadGameInstance::DecreaseScore(int val)
{
	GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Yellow, TEXT("Current Score: ") + FString::FromInt(score));
	score -= val;
	GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Yellow, TEXT("Updated Score: ") + FString::FromInt(score));

	OnDecreaseScore.Broadcast();
}
