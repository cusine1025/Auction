#include "Player.h"
#include "Item.h"

bool Player::PutItemToInventory(Item* NewItem)
{
	if (Inventory.size() >= 20) return false;

	Inventory.push_back(NewItem);

	return true;
}
