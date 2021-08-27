// 7576 (토마토).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
#include <iostream>
#include <queue>
using namespace std;
int t[1001][1001];
int visited[1001][1001] = {0};
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void bfs(int n, int m)
{
	queue<int> qy;
	queue<int> qx;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (t[i][j] == 1)
			{
				qy.push(i);
				qx.push(j);
				visited[i][j] = 1;
			}
		}
	}

	while (!qy.empty() && !qx.empty())
	{
		int cy = qy.front();
		int cx = qx.front();
		qy.pop();
		qx.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			if (ny >= 1 && nx >= 1 && nx <= m && ny <= n) {
				if (visited[ny][nx] == 0 && t[ny][nx] == 0)
				{
					visited[ny][nx] = 1;
					t[ny][nx] = t[cy][cx] + 1;
					qy.push(ny);
					qx.push(nx);
				}
			}
		}

	}
}

int isRipped(int n, int m)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (t[i][j] == 0)
				return 0;
		}
		
	}
	return 1;
}

int main()
{
	int m, n;
	int days = 1;
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> t[i][j];
		}
	}
	
	bfs(n, m);

	/*for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cout << t[i][j] << " ";
		}
		cout << endl;
	}*/

	if (!isRipped(n, m))
		printf("-1");
	else
	{
		int max = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (t[i][j] > max)
					max = t[i][j];
			}
		}
		printf("%d", max - 1);
	}
}
