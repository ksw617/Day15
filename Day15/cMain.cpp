#include <stdio.h>
#include <Windows.h>

void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

enum Dir
{
	DOWN,
	LEFT,
	RIGHT,
	UP,
};


char shape[4][13][8] =
{
	{	 //Down
		{0,0,1,1,0,0,0,0},
		{0,1,0,0,1,1,1,0},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,1,0,1},
		{1,0,1,1,1,0,1,1},
		{1,1,0,0,0,0,1,1},
		{1,0,2,0,0,2,0,1},
		{0,1,0,0,0,0,1,0},
		{1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,1},
		{0,1,0,1,1,0,1,0},
		{0,1,1,0,0,1,1,0},
	},

	{	 //Left
		{0,0,0,1,1,0,0,0},	 
		{0,1,1,0,0,1,1,0},	 
		{1,0,0,0,0,0,0,1},	 
		{1,0,0,0,0,0,0,1},	 
		{1,1,0,0,0,0,0,1},	 
		{1,0,1,1,1,0,0,1},	 
		{1,0,0,0,0,1,0,1},	 
		{0,2,0,2,0,0,1,0},	 
		{1,0,0,0,0,1,1,0},	 
		{0,1,1,1,1,0,0,0},	 
		{1,0,0,0,0,1,0,0},	 
		{1,0,1,1,0,1,0,0},
		{0,1,0,0,1,0,0,0},
	},

	{	 //Right
		{0,0,0,1,1,0,0,0},
		{0,1,1,0,0,1,1,0},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,1,1},
		{1,0,0,1,1,1,0,1},
		{1,0,1,0,0,0,0,1},
		{0,1,0,0,2,0,2,0},
		{0,1,1,0,0,0,0,1},
		{0,0,0,1,1,1,1,0},
		{0,0,1,0,0,0,0,1},
		{0,0,1,0,1,1,0,1},
		{0,0,0,1,0,0,1,0},
	},

	{	  //Up
		{0,0,0,0,1,1,0,0},
		{0,1,1,1,0,0,1,0},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,1},
		{0,1,0,0,0,0,1,0},
		{1,0,1,1,1,1,0,1},
		{1,0,0,0,0,0,0,1},
		{0,1,0,1,1,0,1,0},
		{0,1,1,0,0,1,1,0},
	},
};

struct Obj
{
	int x;
	int y;
	Dir dir;
	char (*shape)[13][8];
};

struct Heart
{
	int x;
	int y;

};

int main()
{
	Obj player;
	player.x = 10;
	player.y = 10;
	player.dir = DOWN;
	player.shape = shape;

	while (true)
	{
		system("cls");
		
		if (GetAsyncKeyState(VK_LEFT))
		{
			player.x--;
			player.dir = LEFT;

		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			player.x++;
			player.dir = RIGHT;

		}
		if (GetAsyncKeyState(VK_UP))
		{

			player.y--;
			player.dir = UP;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			player.y++;
			player.dir = DOWN;
		}


		for (int y = 0; y < 13; y++)
		{
			for (int x = 0; x < 8; x++)
			{
				switch (shape[player.dir][y][x])
				{
				case 1:
					SetPosition(player.x + x, player.y + y);
					printf("бс");
					break;
				case 2:
					SetPosition(player.x + x, player.y + y);
					printf("б▄");
					break;
				default:
					break;

				}
			}
		}

		Sleep(10);
	}

	return 0;
}