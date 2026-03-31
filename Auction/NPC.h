#pragma once
#include "Item.h"

class NPC
{
	float CallValue;
	float MaxValue;

	//경매가 높게 부르는 함수
	
	//상한가 설정 함수
	void SetMaxValue(Item* TargetItem);
};