#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	//�׵���Ϣ�洢
	//1.���ú��׵���Ϣ��9*9(����ʱҪ����������У���11*11��
	char mine[ROWS][COLS] = { 0 };
	printf("ɨ�׿�ʼ...\n");
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	//ɨ��
	//DisplayBoard(mine, ROW, COL);
	//ȥmine������Ϣ����show��
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		printf("%d\n", input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����Ƿ���������ѡ��\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}