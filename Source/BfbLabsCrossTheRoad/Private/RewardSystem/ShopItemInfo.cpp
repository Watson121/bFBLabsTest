// Fill out your copyright notice in the Description page of Project Settings.


#include "RewardSystem/ShopItemInfo.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "RewardSystem/ShopItem.h"

void UShopItemInfo::UpdateItemInfo(UShopItem* currentShopItem)
{

	// Checking Current Shop Item is valid or not
	if (currentShopItem == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Red, TEXT("Passed empty shop item data"));
		return;
	}

	// Setting Text For Item Title
	ItemTitle->SetText(currentShopItem->ItemName());

	// Setting Text For Item Description
	ItemDescription->SetText(currentShopItem->ItemDescription());

	// Setting Text For Item Cost
	FString combinedCostString = FString::Printf(TEXT("Cost: %d Points"), currentShopItem->ItemCost());
	ItemCost->SetText(FText::FromString(combinedCostString));

	// Setting Image for Item Image
	ItemImage->SetBrushFromTexture(currentShopItem->ItemImage());

}
