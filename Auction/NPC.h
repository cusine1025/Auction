#pragma once
#include "Item.h"

class NPC
{
	float MaxValue;
	
public:

	//NPC가 포기할 상한선 설정 함수
	void SetMaxValue(Item* TargetItem);
};