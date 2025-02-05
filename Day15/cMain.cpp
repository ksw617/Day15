#include <stdio.h>
#include <Windows.h>

void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


char shape[13][8] =
{
	{0,0,1,1,0,0,0,0},
	{0,1,0,0,1,1,1,0},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,1},
	{1,0,1,1,1,0,1,1},
	{1,1,0,0,0,0,1,1},
	{1,0,1,0,0,1,0,1},
	{0,1,0,0,0,0,1,0},
	{1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,1},
	{0,1,0,1,1,0,1,0},
	{0,1,1,0,0,1,1,0},
};

int main()
{
	while (true)
	{
		system("cls");
		for (int y = 0; y < 13; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				switch (shape[y][x])
				{
				case 1:
					SetPosition(x, y);
					printf("бс");
					break;
				default:
					break;
				}

			}
		}

		Sleep(50);
	}

	return 0;
}