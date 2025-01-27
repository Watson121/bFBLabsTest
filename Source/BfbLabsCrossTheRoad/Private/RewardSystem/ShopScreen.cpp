// Fill out your copyright notice in the Description page of Project Settings.


#include "RewardSystem/ShopScreen.h"
#include "CrossRoadGameInstance.h"
#include "RewardSystem/ShopItem.h"
#include "RewardSystem/ShopItemGrid.h"
#include "Components/TileView.h"

// Setting what the current selected item will be
void UShopScreen::SetCurrentSelectedItem(UShopItem* NewCurrentSelectedItem)
{
	currentSelectedItem = NewCurrentSelectedItem;
}

// If the player has enough points, they will be able to purchase an item
void UShopScreen::PurchaseItem()
{
	int score = Cast<UCrossRoadGameInstance>(GetGameInstance())->GetScore();
	
	if (currentSelectedItem == NULL) {
		UE_LOG(LogTemp, Error, TEXT("No Current Selected Item"));
		return;
	}

	// Checking if you have enough score, and if so then remove the amount from the score pool
	if (score >= currentSelectedItem->ItemCost()) {
		Cast<UCrossRoadGameInstance>(GetGameInstance())->DecreaseScore(currentSelectedItem->ItemCost());
	
		// Removing Item from Grid so it can no longer be purchased
		shopItemGrid->ShopItemTileView->RemoveItem(currentSelectedItem);
		Cast<UCrossRoadGameInstance>(GetGameInstance())->purchasedItems.Add(currentSelectedItem);
	}
	

}

void UShopScreen::NativeConstruct()
{
	Super::NativeConstruct();
}
