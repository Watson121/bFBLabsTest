// Fill out your copyright notice in the Description page of Project Settings.


#include "RewardSystem/ShopItemGrid.h"
#include "RewardSystem/ShopScreen.h"

void UShopItemGrid::SetShopScreen(UShopScreen* _shopScreen)
{
	if (_shopScreen == NULL) {
		return;
	}

	ShopScreen = _shopScreen;
}
