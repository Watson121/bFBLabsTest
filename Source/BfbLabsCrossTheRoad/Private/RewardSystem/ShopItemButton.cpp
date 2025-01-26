// Fill out your copyright notice in the Description page of Project Settings.


#include "RewardSystem/ShopItemButton.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "RewardSystem/ShopItem.h"

void UShopItemButton::NativeConstruct()
{
	Super::NativeConstruct();

	itemButton->OnClicked.AddUniqueDynamic(this, &UShopItemButton::ShopItemButtonClicked);
}

void UShopItemButton::ShopItemButtonClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Yellow, TEXT("Shop item Button Clicked!"));
}

void UShopItemButton::SetButtonData(UShopItem* shopItem)
{
	if (shopItem == NULL) {
		GEngine->AddOnScreenDebugMessage(-1, 14.0f, FColor::Red, TEXT("Passed empty shop item data"));
		return;
	}

	shopItemData = shopItem;

	// If there is an item image, then set button image to it
	if (shopItemData->ItemImage() != NULL) {
		itemImage->SetBrushFromTexture(shopItemData->ItemImage());
	}

}
