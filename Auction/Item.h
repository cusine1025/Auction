#pragma once
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct ItemData {
	string Name;
	string Description;
	float Value;
};

class Item
{
public:

	string Name;
	string Description;

	float RealValue = 0;
	float MinValue = 0;
	float MaxValue = 0;
	float CallValue = 0;

	//생성자
	Item();

	//감정가 범위 세팅 함수
	void SetEstimatedRange();
};