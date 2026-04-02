#include "AuctionSystem.h"

AuctionSystem::AuctionSystem()
{
	Player* MainPlayer = new Player();
	SetPlayer(MainPlayer);

	StartAuction();
}

void AuctionSystem::JoinParticipants()
{
	for (Participant* Part : Participants) {
		Part->SetState(STATE::JOIN);
	}
}

void AuctionSystem::SetNewItem()
{
	if (AuctionItem) {
		delete AuctionItem;
		AuctionItem = nullptr;
	}

	AuctionItem = new Item();
}

void AuctionSystem::StartAuction()
{
	SetNewItem();

	Participants.push_back(CurrentPlayer);

	for (int i = 0; i < 3; i++) {
		NPC* Npc = new NPC();
		Npc->SetMaxValue(AuctionItem);
		Npcs.push_back(Npc);
		Participants.push_back(Npc);
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
