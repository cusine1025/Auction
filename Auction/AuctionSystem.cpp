#include "AuctionSystem.h"

void AuctionSystem::StartAuction()
{
	AuctionItem = nullptr;

	if (AuctionItem) {
		delete AuctionItem;
		AuctionItem = new Item();
	}
}

void AuctionSystem::EndAuction()
{
	for (NPC* Npc : Npcs) {
		delete Npc;
		Npc = nullptr;
	}
}
