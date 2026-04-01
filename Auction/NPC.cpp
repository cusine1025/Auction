#include "NPC.h"
#include "math.h"
#include <random>

void NPC::SetMaxValue(Item* TargetItem)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.3f, 0.9f);
	float randomValue = dis(gen);

	MaxValue = TargetItem->RealValue * randomValue;
}
