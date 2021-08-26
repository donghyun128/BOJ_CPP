// 2667 (단지번호붙이기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int map[26][26];
int visited[26][26] = { 0 };
int n_cnt[626] = { 0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int y, int x, int size, int n_hood)
{
	n_cnt[n_hood]++;
	visited[y][x] = 1;
	map[y][x] = n_hood;

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > 0 && ny > 0 && nx <= size && ny <= size) 
		{
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
				dfs(ny, nx, size, n_hood);
		}
	}
}

int main()
{
	int n;
	int n_hood = 1;
	string line;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> line;
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = (line[j - 1] - '0');
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j] && map[i][j])
			{
				dfs(i, j, n, n_hood);
				n_hood++;
			}
		}
	}

	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j];
		}
		cout << endl;
	}*/

	sort(n_cnt + 1, n_cnt + n_hood);

	printf("%d\n", n_hood - 1);
	
	for (int i=1; i < n_hood; i++)
	{
		printf("%d\n", n_cnt[i]);
	}
}

