// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ShopItemButton.generated.h"

class UButton;
class UImage;
class UShopItem;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShopItemSelected, UShopItem*, shopItem);

/**
 * 
 */
UCLASS()
class BFBLABSCROSSTHEROAD_API UShopItemButton : public UUserWidget, public IUserObjectListEntry
{
	GENERATED_BODY()
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* itemButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UImage* itemImage;

	UPROPERTY(BlueprintReadWrite)
	UShopItem* shopItemData;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FOnShopItemSelected OnShopItemSelected;

	void NativeConstruct();

	UFUNCTION()
	void ShopItemButtonClicked();

	void OnListItemObjectSet(UObject* ListItemObject);

	UFUNCTION(BlueprintCallable)
	void SetButtonData(UShopItem* shopItem);

};
