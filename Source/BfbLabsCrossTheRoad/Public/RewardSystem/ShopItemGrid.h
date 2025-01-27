// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopItemGrid.generated.h"


class UTileView;
class UShopScreen;

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItemGrid : public UUserWidget
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTileView* ShopItemTileView;

	UFUNCTION(BlueprintCallable)
	void SetShopScreen(UShopScreen* _shopScreen);

protected:

	UPROPERTY(BlueprintReadOnly)
	UShopScreen* ShopScreen;

};
