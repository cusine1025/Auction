#pragma once

#include <vector>

using namespace std;

class Player
{

	float CurrentMoney;

	vector<Item*> Inventory;

	//아이템 넣는 함수
	bool PutItemToInventory(Item* NewItem);
};