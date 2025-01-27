// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopItemInfo.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItemInfo : public UUserWidget
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* ItemTitle;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* ItemImage;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemDescription;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* ItemCost;

public:

	UFUNCTION(BlueprintCallable)
	void UpdateItemInfo(class UShopItem* currentShopItem);

};
