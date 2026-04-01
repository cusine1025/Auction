#pragma once

#include <vector>
#include "Item.h"
#include "Participant.h"

using namespace std;

class Player : public Participant
{

	vector<Item*> Inventory;

public:

	//돈 추가 함수
	void AddMoney(float Money) { CurrentMoney += Money; };

	//돈 차감 함수
	void SpendMoney(float Money) { CurrentMoney -= Money; };

	//현재 돈 반환 함수
	float GetCurrentMoney() const { return CurrentMoney; };

	//인벤토리에 아이템 넣는 함수
	bool PutItemToInventory(Item* NewItem);

	//아이템 구매 함수
	bool PurchaseItem(Item* NewItem);
};