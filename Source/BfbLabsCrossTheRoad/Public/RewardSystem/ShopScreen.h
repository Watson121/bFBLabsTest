// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameScreen/GameScreen.h"
#include "ShopScreen.generated.h"

class UButton;
class UShopItemGrid; 
class UShopItemInfo;

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopScreen : public UGameScreen
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* PurchaseButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UShopItemGrid* shopItemGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UShopItemInfo* shopItemInfo;

	UFUNCTION(BlueprintCallable)
	void PurchaseItem();

	void NativeConstruct();

};
