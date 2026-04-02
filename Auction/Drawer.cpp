#include "Drawer.h"
#include "Data.h"

#include <Windows.h>
#include <conio.h>
#include <string>
#include <sstream>

using namespace std;

//플레이어 입력
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_TAB 9

//색상코드
enum {
	BLACK,
	DARK_BLUE,
	DARK_GREEN,
	DARK_SKYBLUE,
	DARK_RED,
	DARK_VOILET,
	DAKR_YELLOW,
	GRAY,
	DARK_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

vector<string> messages = {
	"경매를 시작합니다!",
	"흥미로운 물건이 나왔군요.",
	"이건 아주 희귀한 물건입니다!",
	"이 물건의 가치를 알아보실 수 있으실까요?"
};

string MoneyFormat(float value) {

	// 소수점 버리고 정수로 변환
	string s = to_string((long long)value); 	
	int insertPos = s.length() - 3;

	while (insertPos > 0) {
		s.insert(insertPos, ",");
		insertPos -= 3;
	}
	return s;
}

void MoveCursor(int row, int col) {
	printf("\033[%d;%dH", row, col);
}

void DrawBox(int row, int col, int width, int height)
{
	//네모 위 그리기
	MoveCursor(row, col);
	printf("┌");
	for (int i = 0; i < width - 2; ++i) printf("─");
	printf("┐");

	//네모 중간 그리기
	for (int i = 1; i < height - 1; ++i) {
		MoveCursor(row + i, col);
		printf("│");
		for (int j = 0; j < width - 2; ++j) printf(" ");
		printf("│");
	}

	//네모 아래 그리기
	MoveCursor(row + height - 1, col);
	printf("└");
	for (int i = 0; i < width - 2; ++i) printf("─");
	printf("┘");
}

void DrawAsciiArt(int X, int Y, const string& AsciiArt) {
	stringstream ss(AsciiArt);
	string Line;
	int CurrentY = Y;

	while (std::getline(ss, Line)) {
		MoveCursor(CurrentY++, X); // 한 줄 내려갈 때마다 X좌표는 고정, Y좌표만 +1
		printf("%s", Line.c_str());
	}
}

void DrawMainMenu()
{
	const char* menus[] = {
	"게임 시작",
	"게임 정보",
	"나 안할래"
	};

	int menu = 1;
	int select = 1;
	int menuCount = 3;
	int selected = 0;
	while (menu) {

		system("cls");

		DrawBox(1, 0, 120, 50);

		int MenuRow = 40;
		int MenuCol = 50;

		//메뉴 박스
		DrawBox(MenuRow, 50, 15, 7);

		select = 1;

		while (select) {
			//메뉴 출력
			for (int i = 0; i < 3; ++i) {
				MoveCursor(MenuRow+2 + i, 51);
				if (i == selected)
					printf("\033[01;33m > %s\033[0m\n", menus[i]);
				else if (i == menuCount - 1)
					printf("   %s", menus[i]);
				else
					printf("   %s\n", menus[i]);
			}

			MoveCursor(MenuRow+4, 62);

			int key = _getch();

			if (key == 0 || key == 224) {
				key = _getch();
				switch (key) {
				case KEY_UP:
					selected = (selected - 1 + menuCount) % menuCount;
					break;
				case KEY_DOWN:
					selected = (selected + 1) % menuCount;
					break;
				}
			}
			else if (key == KEY_ENTER) {
				switch (selected) {
				case 0:
					//drawGame();
					select = 0;
					break;
				case 1:
					//drawInfo();
					select = 0;
					break;
				case 2:
					exit(0);
					break;
				}
			}
		}
	}
}

const int SLOT_ROW = 7;
const int SLOTW_WIDTH = 30;
const int SLOT_HEIGHT = 6;

void DrawAuctionScreen()
{
	AuctionSystem Auction = AuctionSystem::GetInstance();
	bool IsPlaying = true;

	while (IsPlaying) {
		system("cls");

		//전체 프레임
		DrawBox(1, 0, 120, 45);

		//로그 섹션
		DrawBox(31, 0, 120, 15);

		//물건 그리기
		//물건 이름 칸
		DrawBox(1, 0, 30, 3);
		//물건 설명 칸
		DrawBox(31, 0, 120, 3);

		//슬롯 섹션
		DrawBox(1, 89, 32, 31);

		//참가자 슬롯
		for (int i = 0; i < 4; i++) {
			DrawBox(SLOT_ROW + (i * SLOT_HEIGHT), 90, SLOTW_WIDTH, SLOT_HEIGHT);
			MoveCursor(SLOT_ROW + (i * SLOT_HEIGHT) + 1, 92);
			//플레이어 데이터 쓰기
			if (i == 0) {
				printf("당신");
			}
			//NPC 데이터 쓰기
			else {
				printf("NPC%d", i);
			}
		}

		//지갑 그리기
		//지갑 섹션
		DrawBox(1, 89, 32, 6);
		MoveCursor(2, 91);
		printf("당신의 지갑");
		

		//경매 시퀀스 시작
		while (true) {
			UpdateItem(Auction.AuctionItem);

			UpdateWallet(Auction.CurrentPlayer);

			int Index = 0;
			for (Participant* Part : Auction.Participants) {

				if (Part) {
					
					if (NPC* Npc = dynamic_cast<NPC*>(Part)) {
						Npc->HandleItem(Auction.AuctionItem);
						Sleep(500);
					}

					UpdateSlot(Part, Index);
				}

				Index++;
			}

			int key = _getch();

			Auction.JoinParticipants();
		}
	}
	
}

void UpdateItem(Item* NewItem)
{
	if (NewItem) {
		//이름 출력
		MoveCursor(2, 3);
		printf("                         ");
		MoveCursor(2, 3);
		printf("%s", NewItem->Name.c_str());
		//시작가 범위 출력
		MoveCursor(2, 33);
		printf("                                                 ");
		MoveCursor(2, 33);
		string MinValue = MoneyFormat(NewItem->MinValue);
		string MaxValue = MoneyFormat(NewItem->MaxValue);
		printf("시작가 범위 : %s 원 ~ %s 원", MinValue.c_str(), MaxValue.c_str());

		//설명 출력
		MoveCursor(32, 3);
		printf("                                                            ");
		MoveCursor(32, 3);
		printf("%s", NewItem->Description.c_str());

		//아스키 아트 출럭
		DrawAsciiArt(30, 5, NewItem->AsciiArt);
	}
}

void UpdateSlot(Participant* Part, int Index)
{
	MoveCursor(SLOT_ROW + (Index * SLOT_HEIGHT) + 3, 92);
	printf("                    ");
	MoveCursor(SLOT_ROW + (Index * SLOT_HEIGHT) + 3, 92);
	if (Part->GetState() == STATE::READY) {
		printf("대기");
	}
	else if (Part->GetState() == STATE::DROP) {
		printf("포기");
	}
	else {
		string Money = MoneyFormat(Part->GetCallValue());
		printf("입찰가 : %s 원", Money.c_str());
	}
}

void UpdateWallet(Player* Player)
{
	MoveCursor(4, 91);

	if (Player) {
		string Money = MoneyFormat(Player->GetCurrentMoney());
		printf("%s 원", Money.c_str());
	}
	else {
		printf("엥... 지갑이 없는디요...");
	}
}

