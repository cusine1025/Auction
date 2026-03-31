#pragma once

#include <stdio.h>
#include "AuctionSystem.h"

//커서 이동 함수
void MoveCursor(int row, int col);

//문자 들어갈 네모 그리는 함수
void DrawBox(int row, int col, int width, int height);

//메인 메뉴 그리는 함수
void DrawMainMenu();

//경매 화면 그리는 함수
void DrawAuctionScreen(AuctionSystem* CurrentAuction);