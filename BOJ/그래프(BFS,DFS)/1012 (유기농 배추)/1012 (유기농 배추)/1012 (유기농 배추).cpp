// 1012 (유기농 배추).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <cstring>
using namespace std;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int map[51][51] = { 0 };
int visited[51][51];

void dfs(int y, int x, int n, int m)
{
	visited[y][x] = 1;

	for (int d = 0; d < 4; d++)
	{
		int ny = y + dy[d];
		int nx = x + dx[d];

		if (ny >= 0 && nx >= 0 && ny < n && nx < m)
		{
			if (!visited[ny][nx] && map[ny][nx])
				dfs(ny, nx, n, m);
		}

	}


}

int main()
{
	int t, m, n, k;
	cin >> t;
	
	for (int p = 0; p < t; p++)
	{
		int worm = 0;
		cin >> m >> n >> k;
		for (int q = 0; q < k; q++)
		{
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					dfs(i, j, n, m);
					worm++;
				}
			}
		}
		cout << worm << endl;
		memset(visited, 0, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
}
