#pragma once

#include <stdio.h>
#include "AuctionSystem.h"

//마우스 커서 위치 이동
void MoveCursor(int row, int col);

//네모 그리기 함수
void DrawBox(int row, int col, int width, int height);

//아스키 아트 그리기 함수


//메인 메뉴 그리기 함수
void DrawMainMenu();

//경매 틀 그리기 함수
void DrawAuctionScreen();

//아이템 데이터 업데이트 함수
void UpdateItem(Item* NewItem);

//참가자 슬롯 업데이트 함수
void UpdateSlot(Participant* Part, int Index);

//플레이어 지갑 업데이트 함수
void UpdateWallet(Player* Player);