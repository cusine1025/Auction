#pragma once

#include <vector>
#include "Item.h"
#include "Participant.h"

using namespace std;

class Player : public Participant
{

	vector<Item*> Inventory;

public:

	Player();

	//인벤토리에 아이템 넣는 함수
	bool PutItemToInventory(Item* NewItem);

	//아이템 구매 함수
	bool PurchaseItem(Item* NewItem);
};