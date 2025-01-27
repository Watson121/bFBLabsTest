// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameScreen/GameScreen.h"
#include "ShopScreen.generated.h"

class UButton;
class UShopItemGrid; 
class UShopItemInfo;
class UTextBlock;
class UShopItem;

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopScreen : public UGameScreen
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "Shop Items")
	void SetCurrentSelectedItem(UShopItem* NewCurrentSelectedItem);

	UFUNCTION(BlueprintCallable, Category = "Shop Items")
	FORCEINLINE TArray<UShopItem*> GetPurchaseditems() const { return purchasedItems; }

protected:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* PurchaseButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* BackButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UShopItemGrid* shopItemGrid;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UShopItemInfo* shopItemInfo;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextBlock* currentScore;

	UPROPERTY(BlueprintReadWrite)
	UShopItem* currentSelectedItem;

	UPROPERTY(BlueprintReadWrite)
	TArray<UShopItem*> purchasedItems;

	UFUNCTION(BlueprintCallable)
	void PurchaseItem();

	void NativeConstruct();

};
