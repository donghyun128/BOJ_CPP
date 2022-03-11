#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;
int R, C, T;
int map[50][50] = { 0 };
int map_tmp[50][50] = { 0 };
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};

queue<tuple<int, int, int>> dust_circulating;

int cleaner_up_y;
int cleaner_up_x;
int cleaner_down_y;
int cleaner_down_x;

void testPrint()
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void map_copy(int dst[][50], int  src[][50])
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			dst[i][j] = src[i][j];
		}
	}
}

void dustSpread()
{
	map_copy(map_tmp, map);

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] >= 5)
			{
				int dust_spreaded = map[i][j] / 5;

				for (int k = 0; k < 4; k++)
				{
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && ny < R && nx >= 0 && nx < C && map[ny][nx] != -1)
					{
						map_tmp[ny][nx] += dust_spreaded;
						map_tmp[i][j] -= dust_spreaded;
					}
				}
			}
		}
	}
	map_copy(map, map_tmp);

}

void circulate()
{
	
	for (int y = cleaner_up_y-1; y > 0; y--)
		map[y][0] = map[y - 1][0];
	for (int x = 0; x < C-1; x++)
		map[0][x] = map[0][x + 1];
	for (int y = 0; y < cleaner_up_y; y++)
		map[y][C - 1] = map[y + 1][C - 1];
	for (int x = C - 1; x > 1; x--)
		map[cleaner_up_y][x] = map[cleaner_up_y][x - 1];
	map[cleaner_up_y][1] = 0;
	

	for (int y = cleaner_down_y + 1; y < R - 1; y++)
		map[y][0] = map[y + 1][0];
	for (int x = 0; x < C - 1; x++)
		map[R - 1][x] = map[R - 1][x + 1];
	for (int y = R - 1; y > cleaner_down_y; y--)
		map[y][C - 1] = map[y - 1][C - 1];
	for (int x = C - 1; x > 1; x--)
		map[cleaner_down_y][x] = map[cleaner_down_y][x -1];
	map[cleaner_down_y][1] = 0;

}
int dustLeft()
{
	int left_dust = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			if (map[i][j] > 0)
				left_dust += map[i][j];
		}
	}
	return left_dust;
}
void cleaning()
{
	for (int i = 0; i < T; i++)
	{
		dustSpread();

		//testPrint();

		circulate();

		//testPrint();

	}

	cout << dustLeft();
}

void input()
{
	bool isUpChecked = false;

	cin >> R >> C >> T;
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			cin >> map[r][c];
			if (map[r][c] == -1)
			{
				if (!isUpChecked)
				{
					cleaner_up_y = r;
					cleaner_up_x = c;
					isUpChecked = true;
				}
				else
				{
					cleaner_down_y = r;
					cleaner_down_x = c;
				}
			}
		}
	}
}

void solution()
{
	input();
	cleaning();
}



int main()
{
	solution();
}

