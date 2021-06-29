#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

// ����Ĵ��벻̫�ã���Ϊ��û�б����Ƶ�������Ժ��޸�Ϊ5*5�ģ��д�ӡ������Ȼֻ��3��
//void DisplayBoard(char board[ROW][COL], int row, int col)
//{
//	int i = 0;
//	for (i = 0; i < ROW; i++)
//	{
//		//1.��ӡ��һ�е�����
//		printf(" %c | %c | %c \n",board[i][0], board[i][1], board[i][2]);
//		//2.��ӡ�ָ���
//		if(i < row - 1)
//			printf("---|---|---\n");
//	}
//}

//�Ż���ӡ����
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//��ӡһ�е�����
			printf(" %c ", board[i][j]);
			//���һ�в���Ҫ��ӡ |
			if(j<col-1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���,���һ���ָ��в��ô�ӡ
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("���������������:>");
		scanf("%d%d", &x, &y);
		//�ж�x,y����ĺϷ���
		if (x >= 1 && x <= row && y >= 1 && y <= col) 
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������Ѿ���ռ��!\n");
			}
		}
		else
		{
			printf("����Ƿ�,����������!\n");
		}
	}

}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����ߣ�>");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			printf("(%d,%d)\n", x, y);
			break;
		}
	}
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//�ж���
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			//��㷵�����е�һ���ַ�
			return board[i][0];
		}
	}
	//�ж���
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//�ж������Խ��ߣ����Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][i] != ' ')
	{
		return board[1][1];
	}
	//б�Խ���
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][i] != ' ')
	{
		return board[1][1];
	}

	//�ж��Ƿ�ƽ��
	if (1 == IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}