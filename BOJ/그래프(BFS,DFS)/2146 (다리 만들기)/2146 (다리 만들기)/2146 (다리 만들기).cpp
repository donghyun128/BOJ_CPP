// 2146 (다리 만들기).cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int map[101][101] = { 0 };
int visited[101][101] = { 0 };
pair<int, int> d[4] = {{0,1},{0,-1},{1,0},{-1,0}};


void dfs(int y,int x,int landNum,int n)
{
	
	visited[y][x] = 1;
	map[y][x] = landNum;
	
	for (int k = 0; k < 4; k++)
	{
		int nextY = y+ d[k].first;
		int nextX = x+ d[k].second;

		if (nextY > 0 && nextX >> 0 && nextY < n + 1 && nextX < n + 1)
		{
			if (!visited[nextY][nextX] && map[nextY][nextX])
			{
				dfs(nextY, nextX, landNum,n);
			}
		}
	}
}

int BFS(int landNum, int n)
{
	queue<int> qY;
	queue<int> qX;
	int length = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == landNum)
			{
				visited[i][j] = 1;
				qY.push(i);
				qX.push(j);
			}
		}
	}

	while (!qY.empty() && !qX.empty())
	{
		int qSize = qY.size();

		for (int i = 0; i < qSize; i++)
		{
			int curY = qY.front();
			int curX = qX.front();
			qY.pop(); qX.pop();

			for (int j = 0; j < 4; j++)
			{
				int nextY = curY + d[j].first;
				int nextX = curX + d[j].second;
				if (nextY > 0 && nextX > 0 && nextY < n + 1 && nextX < n + 1) {
					if (map[nextY][nextX] != 0 && map[nextY][nextX] != landNum)
						return length;

					else if (visited[nextY][nextX] == 0 && map[nextY][nextX] == 0)
					{
						visited[nextY][nextX] = 1;
						qY.push(nextY);
						qX.push(nextX);
					}
				
				}
			}
		}
		length++;
	}
}

int main() 
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> map[i][j];
		}
	}

	int landNum = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (!visited[i][j] && map[i][j])
			{
				dfs(i, j,landNum,n);
				landNum++;
			}
		}
	}

/*	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/  // 디버그용

	int length = 10000;

	for (int i = 1; i < landNum; i++)
	{
		memset(visited, 0, sizeof(visited));
		length = min(length,BFS(i, n));
	}
	printf("%d", length);
}

