#include "AuctionSystem.h"

AuctionSystem::AuctionSystem()
{
	StartAuction();
}

void AuctionSystem::StartAuction()
{
	if (AuctionItem) {
		delete AuctionItem;
		AuctionItem = nullptr;
	}

	AuctionItem = new Item();

	for (int i = 0; i < 3; i++) {
		NPC* Npc = new NPC();
		Npc->SetMaxValue(AuctionItem);
		Npcs.push_back(Npc);
	}
}

void AuctionSystem::EndAuction()
{
	AuctionItem = nullptr;

	for (NPC* Npc : Npcs) {
		delete Npc;
		Npc = nullptr;
	}

}
