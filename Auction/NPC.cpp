#include "NPC.h"
#include "math.h"
#include <random>
#include "AuctionSystem.h"

NPC::NPC()
{

}

void NPC::SetMaxValue(Item* TargetItem)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> dis(0.3f, 0.9f);
	float randomValue = dis(gen);

	MaxValue = TargetItem->GetRealValue() * randomValue;
}

void NPC::HandleItem(Item* TargetItem)
{
	//지가 생각한 상한선 보다 비싸면 포기
	if (TargetItem->CallValue > MaxValue) {
		SetState(STATE::DROP);
	}
	else {
		AuctionSystem Auction = AuctionSystem::GetInstance();
		CallValue = TargetItem->CallValue + Auction.Increament;
		TargetItem->CallValue = CallValue;
	}
}
