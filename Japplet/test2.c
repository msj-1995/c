#define _CRT_SECURE_NO_WARNINGS 1
//引自己的头文件使用双引号
#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("***** 1.play     0.exit*****\n");
	printf("****************************\n");
}

//游戏的整个算法实现
void game()
{
	char ret = 0;
	//数组-存放走出的棋盘信息,初始时这个数组中全部是是空格（没有什么内容在里面）
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1) {
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢了
		ret = IsWin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢了
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局啦！\n");
	}
}

void test()
{
	int input = 0;
	//设置随机种子
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("进入三子棋游戏\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}