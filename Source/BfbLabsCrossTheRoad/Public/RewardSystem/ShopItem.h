// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "ShopItem.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FShopItemRow : public FTableRowBase {
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UShopItem* shopItem;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	bool bPurchased = false;

};


UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItem : public UDataAsset
{
	GENERATED_BODY()
	
protected:

	UPROPERTY(EditAnywhere, Category = "Shop Item")
	FText itemName;

	UPROPERTY(EditAnywhere, Category = "Shop Item")
	FText itemDescription;

	UPROPERTY(EditAnywhere, Category = "Shop Item")
	class UTexture2D* itemImage;

	UPROPERTY(EditAnywhere, Category = "Shop Item", meta = (ClampMin = 2, ClampMax = 6))
	int itemCost = 2;

public:

	UFUNCTION(BlueprintPure)
	FORCEINLINE FText ItemName() const { return itemName; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE FText ItemDescription() const { return itemDescription; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE UTexture2D* ItemImage() const { return itemImage; }

	UFUNCTION(BlueprintPure)
	FORCEINLINE int ItemCost() const { return itemCost; }

};
