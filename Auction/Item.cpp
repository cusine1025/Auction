#include "Item.h"
#include <random>

vector<ItemData> Items = {
	{
		"개쩌는 물건",
		"쩔어준다.",
		1500
	},
	{
		"좀 쩌는 물건",
		"좀 쩔어준다.",
		1000
	},
	{
		"짜치는 물건",
		"개짜치네;;.",
		500
	}
};

Item::Item()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, Items.size() - 1);
	int R = dis(gen);

	ItemData Data = Items[1];
	Name = Data.Name;
	Description = Data.Description;
	RealValue = Data.Value;

	SetEstimatedRange();
}

void Item::SetEstimatedRange()
{
	if (RealValue == 0) return;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);
	//랜덤 인수
	float R = dis(gen);

	//오차범위
	float W = RealValue * 0.8;
	
	//감정 최소값
	MinValue = RealValue - (W * R);
	//감정 최대값
	MaxValue = RealValue + (W * (1.0f - R));
}
