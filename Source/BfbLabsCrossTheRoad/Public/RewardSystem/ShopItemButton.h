// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ShopItemButton.generated.h"

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItemButton : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* itemButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UImage* itemImage;

	UPROPERTY(BlueprintReadWrite)
	class UShopItem* shopItemData;

	void NativeConstruct();

	UFUNCTION()
	void ShopItemButtonClicked();

	void OnListItemObjectSet(UObject* ListItemObject);

	UFUNCTION(BlueprintCallable)
	void SetButtonData(UShopItem* shopItem);

};
