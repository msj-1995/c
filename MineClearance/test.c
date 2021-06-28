#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	//雷的信息存储
	//1.布置好雷的信息：9*9(创建时要多加两行两列，即11*11）
	char mine[ROWS][COLS] = { 0 };
	printf("扫雷开始...\n");
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//扫雷
	//DisplayBoard(mine, ROW, COL);
	//去mine中找信息传到show中
	FindMine(mine, show, ROW, COL);
}

void menu()
{
	printf("**********************************\n");
	printf("*********    1. play    **********\n");
	printf("*********    2. exit    **********\n");
	printf("**********************************\n");
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		printf("%d\n", input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入非法，请重新选择！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}