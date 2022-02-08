#include <iostream>
using namespace std;

int dx[3] = {1,0,1};
int dy[3] = {0,1,1};
int map[17][17] = { 0 };
int visited[17][17] = { 0 };
int way = 0;

void dfs(int y, int x,int n)
{
	if (y == n && x == n)
	{
		way++;
		return;
	}
	int nx, ny;
	visited[y][x] = 1;

	if (map[y][x] == 2)
	{
		nx = x + dx[0];
		ny = y + dy[0];
		if (nx <= n && ny <= n && map[ny][nx] != 1 && visited[ny][nx] == 0)
		{
			map[ny][nx] = 2;
			dfs(ny, nx, n);
		}

		nx = x + dx[2];
		ny = y + dy[2];
		if (nx <= n && ny <= n && map[ny][nx] != 1 && visited[ny][nx] == 0)
		{
			map[ny][nx] = 4;
			dfs(ny, nx, n);
		}
	}

	else if (map[y][x] == 3)
	{
		nx = x + dx[1];
		ny = y + dy[1];
		if (nx <= n && ny <= n && map[ny][nx] != 1 && visited[ny][nx] == 0)
		{
			map[ny][nx] = 3;
			dfs(ny, nx, n);
		}

		nx = x + dx[2];
		ny = y + dy[2];
		if (nx <= n && ny <= n && map[ny][nx] != 1 && visited[ny][nx] == 0)
		{
			map[ny][nx] = 4;
			dfs(ny, nx, n);
		}
	}

	else if (map[y][x] == 4)
	{
		for (int i = 0; i < 3; i++)
		{
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx <= n && ny <= n && map[ny][nx] != 1 && visited[ny][nx] == 0)
			{
				if (i == 0) map[ny][nx] = 2;
				else if (i == 1) map[ny][nx] = 3;
				else if (i == 2) map[ny][nx] = 4;
				dfs(ny, nx, n);
			}
		}
	}


}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}

	map[1][2] = 2;
	visited[1][1] = 1;

	dfs(1, 2, n);
	cout << way;

}

