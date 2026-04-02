#pragma once
#include "Item.h"
#include "Participant.h"

class NPC : public Participant
{
	float MaxValue = 0;
	
public:

	NPC();

	//NPC가 포기할 상한선 설정 함수
	void SetMaxValue(Item* TargetItem);

	//아이템 어쩔 지 결정하는 함수 - 입찰가 올릴 지, 포기할 지.
	void HandleItem(Item* TargetItem);
};