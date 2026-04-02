#include "Player.h"
#include "Item.h"

Player::Player()
{
	AddMoney(5000000);
}

bool Player::PutItemToInventory(Item* NewItem)
{
	if (Inventory.size() >= 20) return false;

	Inventory.push_back(NewItem);

	return true;
}

bool Player::PurchaseItem(Item* NewItem)
{
	//돈 없음
	if (NewItem->CallValue > CurrentMoney) return false;

	//인벤토리 넣기 시도
	if (PutItemToInventory(NewItem)) {
		//성공하면 돈 차감
		SpendMoney(NewItem->CallValue);
		return true;
	}

	//풀 인벤
	return false;
}
