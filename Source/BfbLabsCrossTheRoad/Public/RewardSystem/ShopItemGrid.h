// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ShopItemGrid.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItemGrid : public UUserWidget
{
	GENERATED_BODY()
	
protected: 

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTileView* ShopItemTileView;

};
