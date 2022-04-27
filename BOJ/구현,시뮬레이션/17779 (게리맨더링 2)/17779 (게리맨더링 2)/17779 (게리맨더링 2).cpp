#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#define MAX 1000000
using namespace std;

int N;
int A[20][20] = { 0 };
int sungergu[20][20] = { 0 };
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int ans = MAX;

struct node
{
	int x, y;
};

void bfs(int x1,int x2,int y1,int y2,int area)
{
	bool visited[20][20] = { false };
	queue<node> q;
	q.push({ x1,y1 });
	visited[x1][y1] = 1;
	while (!q.empty())
	{
		int cx = q.front().x;
		int cy = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (nx < x1 || ny < y1 || nx > x2 || ny > y2) continue;
			if (!visited[nx][ny] && sungergu[nx][ny] == 0)
			{
				sungergu[nx][ny] = area;
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}


	}

}

void border(int x,int y,int d1,int d2)
{
	for (int cx = x; cx <= x + d1; cx)
	{
		for (int cy = y; cy >= y - d1; cy--,cx++)
		{
			sungergu[cx][cy] = 5;
		}
	}

	for (int cx = x; cx <= x + d2; cx)
	{
		for (int cy = y; cy <= y + d2; cy++,cx++)
		{
			sungergu[cx][cy] = 5;
		}
	}

	for (int cx = x + d1; cx <= x + d1 + d2; cx)
	{
		for (int cy = y - d1; cy <= y - d1 + d2; cy++,cx++)
		{
			sungergu[cx][cy] = 5;

		}
	}

	for (int cx = x + d2; cx <= x + d1 + d2; cx)
	{
		for (int cy = y + d2; cy >= y + d2 - d1; cy--,cx++)
		{
			sungergu[cx][cy] = 5;
		}
	}

	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cout << sungergu[r][c];
		}
		cout << "\n";
	}


}
void divide(int x, int y, int d1, int d2)
{
	border(x, y, d1, d2);
}

void setParameter()
{

	for (int x = 1; x <= N-2; x++)
	{
		for (int y = 1; y <= N-1; y++)
		{
			for (int d1 = 1; d1 <= y - 1; d1++)
			{
				for (int d2 = 1; d1 + d2 <= N; d2++)
				{
					divide(x, y, d1, d2);
					memset(sungergu, 0, sizeof(sungergu));
				}
			}
		}
	}

}

void input()
{
	cin >> N;
	for (int r = 1; r <= N; r++)
	{
		for (int c = 1; c <= N; c++)
		{
			cin >> A[r][c];
		}
	}
}

int main()
{
	input();
	setParameter();
}