#include "Drawer.h"
#include "Data.h"

#include <Windows.h>
#include <conio.h>

//플레이어 입력값
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13
#define KEY_ESC 27
#define KEY_TAB 9

//색상
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

void MoveCursor(int row, int col) {
	printf("\033[%d;%dH", row, col);
}

void DrawBox(int row, int col, int width, int height)
{
    //윗줄
    MoveCursor(row, col);
    printf("┌");
    for (int i = 0; i < width - 2; ++i) printf("─");
    printf("┐");

    //중간
    for (int i = 1; i < height - 1; ++i) {
        MoveCursor(row + i, col);
        printf("│");
        for (int j = 0; j < width - 2; ++j) printf(" ");
        printf("│");
    }

    //아랫줄
    MoveCursor(row + height - 1, col);
    printf("└");
    for (int i = 0; i < width - 2; ++i) printf("─");
    printf("┘");
}

void DrawMainMenu()
{
    const char* menus[] = {
    "게임 시작",
    "게임 정보",
    "종료"
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

        //메뉴 박스 출력
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

void DrawAuctionScreen(AuctionSystem* CurrentAuction)
{
    system("cls");

    //메인 틀
    DrawBox(1, 0, 120, 50);

    //로그 창
    DrawBox(36, 0, 120, 15);

    //참여자 섹션
    DrawBox(1, 89, 32, 36);

    //참여자 슬롯
    int SlotRow = 12;
    int SlotWidth = 30;
    int SlotHeight = 6;
    for (int i = 0; i < 4; i++) {
        DrawBox(SlotRow+(i*SlotHeight), 90, SlotWidth, SlotHeight);
    }

    int key = _getch();
}

